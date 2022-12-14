#include "Application.hh"
#include "Event.hh"

#include "imgui_impl_vulkan.h"
#include "imgui_impl_glfw.h"

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

        auto& io = ImGui::GetIO();
        ImGui_ImplVulkan_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        static bool opt_fullscreen = true;
        static bool opt_padding = false;
        static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

        ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
        if (opt_fullscreen)
        {
            const ImGuiViewport* viewport = ImGui::GetMainViewport();
            ImGui::SetNextWindowPos(viewport->WorkPos);
            ImGui::SetNextWindowSize(viewport->WorkSize);
            ImGui::SetNextWindowViewport(viewport->ID);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
            window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
            window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
        }

        if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
            window_flags |= ImGuiWindowFlags_NoBackground;

        if (!opt_padding)
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
        bool p_open = true;

        ImGui::Begin("DockSpace", &p_open, window_flags);

        if (!opt_padding)
            ImGui::PopStyleVar();

        if (opt_fullscreen)
            ImGui::PopStyleVar(2);

        if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
        {
            ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
            ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
        }

        ImGui::End();

        ImGui::Begin("Debug");
        ImGui::Text("Delta Time: %.3f ms", 1000.0f / ImGui::GetIO().Framerate);
        ImGui::End();

        ImGui::Begin("Properties");
        ImGui::End();

        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
        ImGui::Begin("Viewport");

        ImGui::End();
        ImGui::PopStyleVar();

        m_VulkanContext->drawFrame(*m_Camera);
    }
}

Application::~Application() {
    delete m_Camera;
    delete m_VulkanContext;
    delete m_Window;
}
