#include "Window.hh"

Window::~Window() {
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void Window::Init() {
    if (!glfwInit())
        throw std::runtime_error("GLFW cannot be initialized");

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

const char** Window::getExtensions(uint32_t& extensionCount) {
    return glfwGetRequiredInstanceExtensions(&extensionCount);
}

void Window::onUpdate() {
    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

bool Window::isRunning() {
    m_isRunning = glfwWindowShouldClose(m_Window);
    return m_isRunning;
}
