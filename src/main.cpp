#include <Monsta/Monsta.h>
#include <iostream>

int
main ()
{
  std::cout << "Hello Monsta 3D!\n";
  std::cout << __cplusplus << "\n";

  Monsta::Core::Window window ( 900, 500, "Test" );

  window.init ();
  window.start ();
}