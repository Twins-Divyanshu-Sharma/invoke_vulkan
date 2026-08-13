#ifndef INVOKED_WINDOW_HPP
#define INVOKED_WINDOW_HPP

#include "GLFW/glfw3.h"
#include <stdexcept>

namespace invoker{

class Window{

private:
  GLFWwindow* window;
  const uint32_t HEIGHT = 800, 
                 WIDTH = 600;
  const char* TITLE = "Invoke_Vulkan";

public:
  Window();
  ~Window();

  Window(const Window&) = delete;
  Window& operator= (const Window&) = delete;

  bool close();
  void poll();

};

}

#endif
