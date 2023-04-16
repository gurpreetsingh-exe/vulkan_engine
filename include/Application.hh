#pragma once

#include <array>
#include <cstring>
#include <glm/glm.hpp>
#include <optional>
#include <vector>

#include "Camera.hh"
#include "Vulkan/VulkanContext.hh"
#include "Window.hh"

class Application {
public:
  static constexpr int width = 800;
  static constexpr int height = 600;
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
