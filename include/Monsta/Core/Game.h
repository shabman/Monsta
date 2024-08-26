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

#ifndef LIB_MONSTA_GAME_H
#define LIB_MONSTA_GAME_H

#include "Monsta/Interfaces/EventListener.h"

namespace Monsta::Core
{

/**
 * @brief The equivalent of MonoBehvaiour in Unity. Every class that wants to
 * render, update or listen for input events must inherit from this class.
 * The renderer will invoke the methods when an event or render update is triggered.
 *
 * @since 0.0.1
 */
class Game : public Interface::EventListener
{
public:
  Game ();
  virtual ~Game () override = 0;

public:
  virtual void onKeyPressed ( int, int, int, int ) noexcept override = 0;
  virtual void onMouseMove ( double, double ) noexcept override = 0;
  virtual void onMouseClick ( int, int, int ) noexcept override = 0;

public:
  /**
   * @brief When the engine is starting, this method will be invoked once.
   */
  virtual void onStart () = 0;
  /**
   * @brief Every frame step will invoke this method.
   *
   * @param deltaTime - The time passed since the last frame was rendered.
   */
  virtual void onUpdate ( float ) = 0;
  /**
   * @brief When the window loses focus, you can handle pause states.
   */
  virtual void onPause () = 0;
  /**
   * @brief When the window is closing, the main loop is terminated. This method gets called once
   * when the user is exiting the program.
   */
  virtual void onDestroy () = 0;
};

}

#endif /* LIB_MONSTA_GAME_H */
