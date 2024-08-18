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

enum class RenderEvent
{
  EVENT_START,
  EVENT_UPDATE,
  EVENT_PAUSE,
  EVENT_DESTROY
};

class RenderEvent final
{
private:
  static std::set<const Core::Game*> s_eventQueue;

public:
  RenderEvent () = delete;
  ~RenderEvent () = delete;

private:
  friend class Window;

  static void copyAll ( const std::set<const Interface::EventListener*>* queueSource ) noexcept;
  static void dispatchAll ( const RenderEvent& ) noexcept;
};

}
}

#endif /* LIB_MONSTA_RENDEREVENT_H */