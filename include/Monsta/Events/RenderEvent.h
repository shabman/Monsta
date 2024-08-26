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

#ifndef LIB_MONSTA_RENDEREVENT_H
#define LIB_MONSTA_RENDEREVENT_H

#include "Monsta/Core/Game.h"
#include "Monsta/Interfaces/EventListener.h"

#include <set>

namespace Monsta
{

namespace Core
{
class Window;
}

namespace Events
{

enum class RenderEventType
{
  EVENT_START,
  EVENT_PAUSE,
  EVENT_DESTROY
};

class RenderEvent final
{
private:
  static std::set<Core::Game*> s_eventQueue;

public:
  RenderEvent () = delete;
  ~RenderEvent () = delete;

private:
  friend class Monsta::Core::Window;

  static void releaseAll () noexcept;

public:
  static void add ( Core::Game* );
  static void remove ( Core::Game* );
  static void remove ( const uint32_t );

  static void dispatchEvent ( const RenderEventType& );
  static void dispatchTick ( float );
};

}
}

#endif /* LIB_MONSTA_RENDEREVENT_H */
