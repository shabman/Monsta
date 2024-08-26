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

#ifndef LIB_MONSTA_EVENTHELPER_H
#define LIB_MONSTA_EVENTHELPER_H

#include "Monsta/Interfaces/EventListener.h"
#include <set>

namespace Monsta::Events
{

/**
 * @brief An event helper system to publish events to listeners.
 *
 * @since 0.0.1
 */
class EventHelper final
{
public:
  EventHelper () = delete;
  ~EventHelper () = delete;

public:
  /**
   * @brief Adds an event listener class to the given set.
   *
   * @param src - The source set to add the listener to.
   * @param v - The class to add into the set.
   *
   * @warning This method is internally called, do NOT call it
   * directly.
   */
  template <typename T>
  static void
  add ( std::set<T*>* src, T* v )
  {
    src->emplace ( v );
  }
  /**
   * @brief Removes an event listener class from a given set.
   *
   * @param src - The source set to remove the listener to.
   * @param v - The class to remove from the set.
   *
   * @warning This method is internally called, do NOT call it
   * directly.
   */
  template <typename T>
  static void
  remove ( std::set<T*>* src, T* v )
  {
    auto pos = std::find ( src->begin (), src->end (), v );
    if ( pos != src->end () )
      {
        src->erase ( pos );
      }
  }
  /**
   * @brief Removes an event listener class from a given set using an index.
   *
   * @param src - The source set to remove the listener to.
   * @param index - The index to remove from the set.
   *
   * @warning This method is internally called, do NOT call it
   * directly.
   */
  template <typename T>
  static void
  remove ( std::set<T*>* src, const uint32_t index )
  {
    auto i = *std::next ( src->begin (), index );
    src->erase ( i );
  }
};

}

#endif /* LIB_MONSTA_EVENTHELPER_H */
