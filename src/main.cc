#define GLFW_INCLUDE_VULKAN

#include <iostream>
#include "GLFW/glfw3.h"
#include "glm/vec4.hpp"

int main() {
    if (!glfwInit())
        std::cout << "GLFW cannot be initialized" << std::endl;

    GLFWwindow* window = glfwCreateWindow(400, 400, "Engine", NULL, NULL);
    if (!window) {
        glfwTerminate();
        std::cout << "Failed to create window" << std::endl;
    }

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount,
        nullptr);

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
