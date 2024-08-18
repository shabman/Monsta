#include <Monsta/Monsta.h>
#include <iostream>

class SampleListener : public Monsta::Interface::EventListener
{
public:
  SampleListener () = default;
  ~SampleListener () override = default;

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
};

int
main ()
{
  Monsta::Core::Window window ( 900, 500, "Test" );
  Monsta::Renderer::OpenGLRenderer* renderer = Monsta::Renderer::OpenGLRenderer::getInstance ();

  SampleListener listener;
  Monsta::Events::InputEvent::add ( &listener );

  window.init ();
  window.attachContext ( renderer );

  window.start ();

  Monsta::Events::InputEvent::remove ( &listener );
}
