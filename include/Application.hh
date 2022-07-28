#include <vulkan/vulkan.h>

#include "Window.hh"

class Application {
public:
    Application(std::string name);
    ~Application();

    void run();

private:
    Window* m_Window;
    VkInstance m_Instance;
    VkApplicationInfo m_AppInfo;
    VkInstanceCreateInfo m_CreateInfo;
    std::string m_Name;
};
