/**
 * This file is to be removed
 * It is not relevant so piss off with your LICENSE bull shit
 */

#include <Monsta/Monsta.h>
#include <iostream>

class SampleListener : public Monsta::Core::Game
{
public:
  SampleListener () = default;
  ~SampleListener () override
  {
    std::cout << "released from stack\n";
  }

public:
  void
  onKeyPressed ( int key, int scancode, int action, int mods ) noexcept override
  {
    const char* keyName = glfwGetKeyName ( key, scancode );
    if ( action == GLFW_RELEASE && keyName )
      {
        std::cout << "Key Pressed: " << keyName << std::endl;
      }
  }

  void
  onMouseMove ( double x, double y ) noexcept override
  {
    // std::cout << "Pos: " << x << " : " << y << std::endl;
  }

  void
  onMouseClick ( int button, int action, int mods ) noexcept override
  {
    if ( button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_MOUSE_BUTTON_1 )
      {
        std::cout << "Mouse Left Click\n";
      }
  }

  void
  onStart () override
  {
    std::cout << "Starting game class\n";
  }

  void
  onUpdate ( float dt ) override
  {
    std::cout << "On Update\n";
  }

  void
  onPause () override
  {
  }

  void
  onDestroy () override
  {
    std::cout << "Destroying game class\n";
  }
};

int
main ()
{
  Monsta::Core::Window window ( 900, 500, "Test" );
  Monsta::Renderer::OpenGLRenderer* renderer = Monsta::Renderer::OpenGLRenderer::getInstance ();

  SampleListener listener;
  Monsta::Events::RenderEvent::add ( &listener );

  window.init ();
  window.attachContext ( renderer );

  window.start ();
}
