#include <Monsta/Monsta.h>
#include <iostream>

int
main ()
{
  std::cout << "Hello Monsta 3D!\n";
  std::cout << __cplusplus << "\n";

  Monsta::Core::Window window ( 900, 500, "Test" );
  Monsta::Core::Window window2 ( 800, 400, "Test2" );

  window.show ();
  window2.show ( true );

  window.start ();
}