#include "Window.hh"
#include "Vulkan/VulkanContext.hh"

#include <iostream>

Window::~Window() {
  glfwDestroyWindow(m_Window);
  glfwTerminate();
  delete m_Event;
}

void GLFW_error(int err, const char* description) {
  std::cout << description << std::endl;
}

void Window::createSurface(const VkInstance& instance, VkSurfaceKHR* surface) {
  if (glfwCreateWindowSurface(instance, m_Window, nullptr, surface) !=
      VK_SUCCESS) {
    throw std::runtime_error("failed to create window surface!");
  }
}

static void framebufferResizeCallback(GLFWwindow* window, int width,
                                      int height) {
  auto _window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
  auto context = _window->getContext();
  context->frameBufferResized = true;
  _window->onResize(width, height);
}

bool isKeyPressed(GLFWwindow* window, int keycode) {
  int state = glfwGetKey(window, keycode);
  return state == GLFW_PRESS || state == GLFW_REPEAT;
}

static void getMousePos(GLFWwindow* window, glm::vec2& mousePos) {
  double posX;
  double posY;
  glfwGetCursorPos(window, &posX, &posY);
  mousePos = {posX, posY};
}

static void mouseButtonEventCallback(GLFWwindow* window, int button, int action,
                                     int mods) {
  auto _window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
  auto event = _window->getEvent();
  event->shift = mods & GLFW_MOD_SHIFT;
  event->ctrl = mods & GLFW_MOD_CONTROL;
  event->alt = mods & GLFW_MOD_ALT;
  event->button = (Event::ButtonKind)button;

  if (action == GLFW_PRESS) {
    event->kind = Event::MouseDown;
  } else if (action == GLFW_RELEASE) {
    event->kind = Event::MouseUp;
  } else {
    event->kind = Event::None;
  }

  getMousePos(window, event->mouse);
}

static void mouseEventCallback(GLFWwindow* window, double posX, double posY) {
  auto _window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
  auto event = _window->getEvent();
  if (event->kind == Event::MouseDown || event->kind == Event::MouseClickDrag) {
    event->kind = Event::MouseClickDrag;
  } else {
    event->kind = Event::MouseMove;
  }
  event->mouse = {posX, posY};
}

void Window::Init() {
  glfwSetErrorCallback(GLFW_error);
  if (!glfwInit())
    throw std::runtime_error("GLFW cannot be initialized");

  if (glfwVulkanSupported() == GLFW_FALSE) {
    throw std::runtime_error("Vulkan is not supported");
  }

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
  glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

  m_Window =
      glfwCreateWindow(m_Width, m_Height, m_Name.c_str(), nullptr, nullptr);

  glfwSetWindowUserPointer(m_Window, this);
  glfwSetFramebufferSizeCallback(m_Window, framebufferResizeCallback);

  if (!m_Window) {
    glfwTerminate();
    throw std::runtime_error("Failed to create window");
  }

  m_Event = new Event();
  m_Event->kind = Event::None;
  glfwSetMouseButtonCallback(m_Window, mouseButtonEventCallback);
  glfwSetCursorPosCallback(m_Window, mouseEventCallback);
}

const char** Window::getExtensions(uint32_t* extensionCount) {
  return glfwGetRequiredInstanceExtensions(extensionCount);
}

bool Window::isRunning() {
  static auto time = std::chrono::high_resolution_clock::now();
  m_isRunning = glfwWindowShouldClose(m_Window);
  glfwPollEvents();

  m_Event->deltaTime =
      std::chrono::duration<float, std::chrono::seconds::period>(time -
                                                                 m_LastTime)
          .count();
  m_LastTime = time;
  return m_isRunning;
}

void Window::onResize(int width, int height) {
  m_Width = width;
  m_Height = height;
}
