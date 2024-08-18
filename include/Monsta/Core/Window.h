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

#ifndef LIB_MONSTA_WINDOW_H
#define LIB_MONSTA_WINDOW_H

#include "Monsta/Renderer/Context/Context.h"

#include <GLFW/glfw3.h>
#include <cstdint>

namespace Monsta::Core
{

class Window final
{
private:
  GLFWwindow* m_window;
  const char* m_title;
  Renderer::Context* m_ctx;

  uint32_t m_width;
  uint32_t m_height;

public:
  Window ( uint32_t, uint32_t, const char* );
  ~Window ();

public:
  void init () noexcept;
  void close () noexcept;

public:
  void attachContext ( const Renderer::Context* ) noexcept;
  void start () noexcept;

public:
  GLFWwindow* getCoreWindow () const noexcept;
  const char* getTitle () const noexcept;
  Renderer::Context* getContext () const noexcept;

  uint32_t getWidth () const noexcept;
  uint32_t getHeight () const noexcept;
};

}

#endif /* LIB_MONSTA_WINDOW_H */