#pragma once

#include <array>
#include <vector>
#include <cstring>
#include <optional>
#include <glm/glm.hpp>

#include "Window.hh"
#include "Vulkan/VulkanContext.hh"

class Application {
public:
    static constexpr int width = 512;
    static constexpr int height = 512;
    const int MAX_FRAMES_IN_FLIGHT = 2;

    Application(std::string name);
    ~Application();

    void run();

private:
    std::string m_Name;
    Window* m_Window;
    VulkanContext* m_VulkanContext;
};
