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

#include "Monsta/Events/RenderEvent.h"
#include "Monsta/Events/EventHelper.h"
#include "Monsta/Events/InputEvent.h"

#include <spdlog/spdlog.h>

namespace Monsta::Events
{

std::set<Core::Game*> RenderEvent::s_eventQueue;

void
RenderEvent::releaseAll () noexcept
{
  s_eventQueue.clear ();
  InputEvent::releaseAll ();
  spdlog::info ( "[MONSTA]: Released all events" );
}

void
RenderEvent::add ( Core::Game* clazz )
{
  EventHelper::add ( &s_eventQueue, clazz );
  InputEvent::add ( clazz );
}

void
RenderEvent::remove ( Core::Game* clazz )
{
  EventHelper::remove ( &s_eventQueue, clazz );
  InputEvent::remove ( clazz );
}

void
RenderEvent::remove ( const uint32_t index )
{
  EventHelper::remove ( &s_eventQueue, index );
  InputEvent::remove ( index );
}

void
RenderEvent::dispatchEvent ( const RenderEventType& type )
{
  for ( const auto& listener : s_eventQueue )
    {
      if ( listener == nullptr )
        {
          RenderEvent::remove ( listener );
          continue;
        }
      switch ( type )
        {
        case RenderEventType::EVENT_START:
          {
            listener->onStart ();
            break;
          }
        case RenderEventType::EVENT_PAUSE:
          {
            listener->onPause ();
            break;
          }
        case RenderEventType::EVENT_DESTROY:
          {
            listener->onDestroy ();
            break;
          }
        default:
          {
            spdlog::error ( "Unreachable Case Statement reached!" );
            break;
          }
        }
    }
}

void
RenderEvent::dispatchTick ( float dt )
{
  for ( const auto& tickListener : s_eventQueue )
    {
      if ( tickListener == nullptr )
        {
          RenderEvent::remove ( tickListener );
          continue;
        }
      tickListener->onUpdate ( dt );
    }
}

}
