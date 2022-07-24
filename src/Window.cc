#include "Window.hh"

Window::~Window() {
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void Window::Init() {
    if (!glfwInit())
        std::cout << "GLFW cannot be initialized" << std::endl;

    m_Window = glfwCreateWindow(
        m_Width,
        m_Height,
        m_Name.c_str(),
        nullptr, nullptr);

    if (!m_Window) {
        glfwTerminate();
        std::cout << "Failed to create window" << std::endl;
    }
}

void Window::onUpdate() {
    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

bool Window::isRunning() {
    m_isRunning = glfwWindowShouldClose(m_Window);
    return m_isRunning;
}
