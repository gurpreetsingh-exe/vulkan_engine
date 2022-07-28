#include "Application.hh"

Application::Application(std::string name) {
    m_Name = name;
    m_Window = new Window(512, 512, m_Name);

    m_AppInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    m_AppInfo.pApplicationName = "VulkanApp";
    m_AppInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    m_AppInfo.pEngineName = "No Engine";
    m_AppInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    m_AppInfo.apiVersion = VK_API_VERSION_1_0;

    m_CreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    m_CreateInfo.pApplicationInfo = &m_AppInfo;

    const char** extensions = m_Window->getExtensions(m_CreateInfo.enabledExtensionCount);
    m_CreateInfo.ppEnabledExtensionNames = extensions;
    m_CreateInfo.enabledLayerCount = 0;

    if (vkCreateInstance(&m_CreateInfo, nullptr, &m_Instance) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create vulkan instance!");
    }
}

void Application::run() {
    m_Window->Init();

    while(!m_Window->isRunning()) {
        m_Window->onUpdate();
    }
}

Application::~Application() {
    vkDestroyInstance(m_Instance, nullptr);
    delete m_Window;
}
