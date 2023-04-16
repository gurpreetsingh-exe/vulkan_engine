#include "Application.hh"

int main() {
  Application* app = new Application("Engine");
  app->run();

  delete app;
  return 0;
}
