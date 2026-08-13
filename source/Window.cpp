#include "Window.hpp"


invoker::Window::Window(){

  bool b =  glfwInit();

  if(!b) 
    throw std::runtime_error("Failed to initialise GLFW");
  

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // Not opengl
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  invoker::Window::window = glfwCreateWindow(HEIGHT, WIDTH, TITLE, nullptr, nullptr);

  if(!window){
      glfwTerminate();
      throw std::runtime_error("Failed to create GLFW window");
  }
}

invoker::Window::~Window() {
    if(window)
        glfwDestroyWindow(window);
    glfwTerminate();
}

bool invoker::Window::close(){
    return glfwWindowShouldClose(window);
}

void invoker::Window::poll(){
  glfwPollEvents();
}
