#pragma once

#include <array>
#include <vector>
#include <cstring>
#include <optional>
#include <glm/glm.hpp>

#include "Camera.hh"
#include "Window.hh"
#include "Vulkan/VulkanContext.hh"

class Application {
public:
    static constexpr int width = 800;
    static constexpr int height = 800;
    const int MAX_FRAMES_IN_FLIGHT = 2;

    Application(std::string name);
    ~Application();

    void run();

private:
    std::string m_Name;
    Window* m_Window;
    VulkanContext* m_VulkanContext;
    Camera* m_Camera;
};
