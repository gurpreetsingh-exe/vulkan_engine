#include "Application.hh"

Application::Application(std::string name) {
    m_Name = name;
    m_Window = new Window(512, 512, m_Name);
}

void Application::run() {
    m_Window->Init();

    while(!m_Window->isRunning()) {
        m_Window->onUpdate();
    }
}

Application::~Application() {
    delete m_Window;
}
