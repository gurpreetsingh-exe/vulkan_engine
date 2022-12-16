#pragma once

#include <vulkan/vulkan.hpp>

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"
#include <string>
#include <chrono>

#include "Event.hh"

class VulkanContext;

class Window {
public:
    Window(int width, int height, std::string name):
        m_Width(width), m_Height(height), m_Name(name) {}
    ~Window();

public:
    void Init();
    const char** getExtensions(uint32_t* extensionCount);
    bool isRunning();
    GLFWwindow* getHandle() { return m_Window; }
    Event* getEvent() { return m_Event; }
    uint32_t getWidth() { return m_Width; }
    uint32_t getHeight() { return m_Height; }
    void setContext(VulkanContext* context) { m_Context = context; }
    VulkanContext* getContext() { return m_Context; }
    void onResize(int width, int height);

private:
    std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::duration<long, std::ratio<1, 1000000000>>> m_LastTime;
    GLFWwindow* m_Window;
    Event* m_Event;
    int m_Width;
    int m_Height;
    bool m_isRunning;
    std::string m_Name;
    VulkanContext* m_Context;
};
