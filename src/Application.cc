#include "Application.hh"
#include "Event.hh"

Application::Application(std::string name) {
    m_Name = name;
    m_Window = new Window(width, height, m_Name);
    m_Window->Init();

    m_Camera = new Camera(70.0f, glm::vec2(width, height), 0.1f, 100.0f);
    m_VulkanContext = new VulkanContext(m_Window);
}

void Application::run() {
    while(!m_Window->isRunning()) {
        auto* e = m_Window->getEvent();
        m_Camera->onUpdate(*e);
        m_VulkanContext->drawFrame(*m_Camera);
    }
}

Application::~Application() {
    delete m_Camera;
    delete m_VulkanContext;
    delete m_Window;
}
