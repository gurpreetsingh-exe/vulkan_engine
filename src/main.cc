#include "GLFW/glfw3.h"
#include "glm/vec4.hpp"
#include "Application.hh"

int main() {
    Application* app = new Application("Engine");
    app->run();

    delete app;
    return 0;
}
