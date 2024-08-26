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

#define MONSTA_UTIL_FUNCS

#include "Monsta/Events/InputEvent.h"
#include "Monsta/Config.h"
#include "Monsta/Events/EventHelper.h"

namespace Monsta::Events
{

std::set<const Interface::EventListener*> InputEvent::s_eventQueue;

template <typename... EventArgs>
void
InputEvent::dispatch ( const InputType& inputMode, EventArgs... data )
{
  // The parameter pack values are guaranteed so the indexes do not need to be dynamic
  for ( const auto& listener : s_eventQueue )
    {
      Interface::EventListener* mtListener = const_cast<Interface::EventListener*> ( listener );
      if ( inputMode == InputType::EVENT_KEY_CALLBACK )
        {
          mtListener->onKeyPressed (
              GetParameterPackValue<0> ( data... ),
              GetParameterPackValue<1> ( data... ),
              GetParameterPackValue<2> ( data... ),
              GetParameterPackValue<3> ( data... ) );
        }
      if ( inputMode == InputType::EVENT_MOUSE_MOVED )
        {
          mtListener->onMouseMove (
              GetParameterPackValue<0> ( data... ),
              GetParameterPackValue<1> ( data... ) );
        }
      if ( inputMode == InputType::EVENT_MOUSE_CLICKED )
        {
          mtListener->onMouseClick (
              GetParameterPackValue<0> ( data... ),
              GetParameterPackValue<1> ( data... ),
              GetParameterPackValue<2> ( data... ) );
        }
    }
}

void
InputEvent::releaseAll () noexcept
{
  s_eventQueue.clear ();
}

void
InputEvent::_OnKeyCallback ( GLFWwindow* /* window */, int key, int scancode, int action, int mods )
{
  dispatch ( InputType::EVENT_KEY_CALLBACK, key, scancode, action, mods );
}

void
InputEvent::_OnMouseMoveCallback ( GLFWwindow* /* window */, double xpos, double ypos )
{
  dispatch ( InputType::EVENT_MOUSE_MOVED, xpos, ypos, 0x0, 0x0 );
}

void
InputEvent::_OnMouseClickCallback ( GLFWwindow* /* window */, int button, int action, int mods )
{
  dispatch ( InputType::EVENT_MOUSE_CLICKED, button, action, mods, 0x0 );
}

void
InputEvent::add ( const Interface::EventListener* clazz )
{
  EventHelper::add ( &s_eventQueue, clazz );
}

void
InputEvent::remove ( const Interface::EventListener* clazz )
{
  EventHelper::remove ( &s_eventQueue, clazz );
}

void
InputEvent::remove ( const uint32_t index )
{
  EventHelper::remove ( &s_eventQueue, index );
}

}
