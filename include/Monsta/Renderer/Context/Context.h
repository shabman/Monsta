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

#ifndef LIB_MONSTA_CONTEXT_H
#define LIB_MONSTA_CONTEXT_H

namespace Monsta::Renderer
{

/**
 * @brief Pure Virtual Class for Renderer Context's to inherit from.
 *
 * @note This is only for classes that define a Renderer Context Abstraction Layer.
 * Such examples would be like `OpenGLRenderer`.
 *
 * @since 0.0.1
 */
class Context
{
public:
  Context ();
  virtual ~Context () = 0;

public:
  /**
   * @brief Called before the game loop is about to start. Used to
   * initialise or allocate resources.
   */
  virtual void init () noexcept = 0;
  /**
   * @brief Called every frame in the game loop. Used to render objects
   * with the given Renderer.
   */
  virtual void run () noexcept = 0;
  /**
   * @brief Releases all resources that were initialised, triggers
   * the onDestroy event in the `Monsta::Core::Game` class. This is invoked
   * after the game loop and when the program is about to terminate.
   */
  virtual void release () noexcept = 0;
};

}

#endif /* LIB_MONSTA_CONTEXT_H */
