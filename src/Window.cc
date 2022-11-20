#include "Window.hh"
#include "Vulkan/VulkanContext.hh"

#include <iostream>

Window::~Window() {
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void GLFW_error(int err, const char* description) {
    std::cout << description << std::endl;
}

static void framebufferResizeCallback(GLFWwindow* window, int width, int height) {
    auto app = reinterpret_cast<VulkanContext*>(glfwGetWindowUserPointer(window));
    app->frameBufferResized = true;
}

void Window::Init() {
    glfwSetErrorCallback(GLFW_error);
    if (!glfwInit())
        throw std::runtime_error("GLFW cannot be initialized");

    if (glfwVulkanSupported() == GLFW_FALSE) {
        throw std::runtime_error("Vulkan is not supported");
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    m_Window = glfwCreateWindow(
        m_Width,
        m_Height,
        m_Name.c_str(),
        nullptr, nullptr);

    glfwSetFramebufferSizeCallback(m_Window, framebufferResizeCallback);

    if (!m_Window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create window");
    }
}

const char** Window::getExtensions(uint32_t* extensionCount) {
    return glfwGetRequiredInstanceExtensions(extensionCount);
}

bool Window::isRunning() {
    m_isRunning = glfwWindowShouldClose(m_Window);
    glfwPollEvents();
    return m_isRunning;
}

GLFWwindow* Window::getHandle() {
    return m_Window;
}
