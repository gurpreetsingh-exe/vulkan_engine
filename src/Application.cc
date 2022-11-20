#include "Application.hh"

Application::Application(std::string name) {
    m_Name = name;
    m_Window = new Window(width, height, m_Name);
    m_Window->Init();

    m_VulkanContext = new VulkanContext(m_Window);
}

void Application::run() {
    while(!m_Window->isRunning()) {
        m_VulkanContext->drawFrame();
    }
}

Application::~Application() {
    delete m_Window;
}
