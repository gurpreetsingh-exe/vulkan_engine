#define GLFW_INCLUDE_VULKAN

#include "GLFW/glfw3.h"
#include "glm/vec4.hpp"
#include "Window.hh"

int main() {
    Window* window = new Window(400, 400, "Engine");
    window->Init();

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount,
        nullptr);

    while(!window->isRunning()) {
        window->onUpdate();
    }

    delete window;
    return 0;
}
