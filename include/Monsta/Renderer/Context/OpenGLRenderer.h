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

#ifndef LIB_MONSTA_OPENGLRENDERER_H
#define LIB_MONSTA_OPENGLRENDERER_H

#include "Context.h"
#include <cstdint>

namespace Monsta::Renderer
{

class OpenGLRenderer final : public Context
{
private:
  uint32_t m_vertices;

protected:
  OpenGLRenderer ();
  ~OpenGLRenderer () override;

public:
  static OpenGLRenderer* getInstance () noexcept;

  void init () noexcept override;
  void run () noexcept override;
  void release () noexcept override;
};

}

#endif /* LIB_MONSTA_OPENGLRENDERER_H */
