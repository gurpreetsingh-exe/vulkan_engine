#include <vulkan/vulkan.hpp>

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"
#include <string>

class Window {
public:
    Window(int width, int height, std::string name):
        m_Width(width), m_Height(height), m_Name(name) {}
    ~Window();

public:
    void Init();
    void onUpdate();
    const char** getExtensions(uint32_t* extensionCount);
    bool isRunning();
    GLFWwindow* getHandle();

private:
    GLFWwindow* m_Window;
    int m_Width;
    int m_Height;
    bool m_isRunning;
    std::string m_Name;
};
