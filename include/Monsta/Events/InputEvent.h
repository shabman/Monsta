/**
 *  Monsta 3D Game Engine Framework.
 *  Copyright (C) 2024 Mustafa Malik (avia.shabbyman@gmail.com)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef LIB_MONSTA_INPUTEVENT_H
#define LIB_MONSTA_INPUTEVENT_H

#include "Monsta/Interfaces/EventListener.h"
#include <set>

struct GLFWwindow;

namespace Monsta::Core
{
class Window;
}

namespace Monsta::Events
{

enum class InputType
{
  EVENT_KEY_CALLBACK,
  EVENT_MOUSE_MOVED,
  EVENT_MOUSE_CLICKED
};

class InputEvent final
{
private:
  static std::set<const Interface::EventListener*> s_eventQueue;

public:
  InputEvent () = delete;
  ~InputEvent () = delete;

private:
  friend class Monsta::Core::Window;

  template <typename... EventArgs>
  static void dispatch ( const InputType&, EventArgs... data );

  static void _OnKeyCallback ( GLFWwindow*, int, int, int, int );
  static void _OnMouseMoveCallback ( GLFWwindow*, double, double );
  static void _OnMouseClickCallback ( GLFWwindow*, int, int, int );

public:
  static void add ( const Interface::EventListener* );
  static void remove ( const Interface::EventListener* );
  static void remove ( const uint32_t );
};

}

#endif /* LIB_MONSTA_INPUTEVENT_H */
