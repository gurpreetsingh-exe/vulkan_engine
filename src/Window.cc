#include "Window.hh"

#include <iostream>

Window::~Window() {
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void GLFW_error(int err, const char* description) {
    std::cout << description << std::endl;
}

void Window::Init() {
    glfwSetErrorCallback(GLFW_error);
    if (!glfwInit())
        throw std::runtime_error("GLFW cannot be initialized");

    if (glfwVulkanSupported() == GLFW_FALSE) {
        throw std::runtime_error("Vulkan is not supported");
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    m_Window = glfwCreateWindow(
        m_Width,
        m_Height,
        m_Name.c_str(),
        nullptr, nullptr);

    if (!m_Window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create window");
    }
}

const char** Window::getExtensions(uint32_t* extensionCount) {
    return glfwGetRequiredInstanceExtensions(extensionCount);
}

void Window::onUpdate() {
    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

bool Window::isRunning() {
    m_isRunning = glfwWindowShouldClose(m_Window);
    return m_isRunning;
}

GLFWwindow* Window::getHandle() {
    return m_Window;
}
