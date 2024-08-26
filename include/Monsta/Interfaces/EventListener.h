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

#ifndef LIB_MONSTA_EVENTLISTENER_H
#define LIB_MONSTA_EVENTLISTENER_H

namespace Monsta::Interface
{

/**
 * @warning Do not inherit from this class. See `Monsta::Core::Game` for handling render and input events.
 *
 * @since 0.0.1
 */
class EventListener
{
public:
  EventListener ();
  virtual ~EventListener () = 0;

public:
  /**
   * @brief Triggered when the user presses a key.
   *
   * @param key - The key pressed
   * @param scancode - Scancode related to the key
   * @param action - Actions related to the key
   * @param mods - Modifiers of the key
   *
   * @see [GLFW Key Input Guide](https://www.glfw.org/docs/latest/input_guide.html#input_key) for more.
   *
   */
  virtual void onKeyPressed ( int key, int scancode, int action, int mods ) noexcept = 0;
  /**
   * @brief Triggered when the mouse is moved
   *
   * @param xpos - The X position of the mouse
   * @param ypos - The Y position of the mouse
   *
   */
  virtual void onMouseMove ( double xpos, double ypos ) noexcept = 0;
  /**
   * @brief Triggered when a mouse button is pressed.
   *
   * @param button - The button that was pressed (left, right, etc)
   * @param action - Any actions related to the button
   * @param mods - Any modifiers related to the button
   *
   * @see [GLFW Mouse Input Guide](https://www.glfw.org/docs/latest/input_guide.html#input_mouse) for more.
   */
  virtual void onMouseClick ( int button, int action, int mods ) noexcept = 0;
};

}

#endif /* LIB_MONSTA_EVENTLISTENER_H */
