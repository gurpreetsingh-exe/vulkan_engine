#include <vulkan/vulkan.h>

#include "Window.hh"

class Application {
public:
    Application(std::string name);
    ~Application();

    void run();

private:
    Window* m_Window;
    std::string m_Name;
};
