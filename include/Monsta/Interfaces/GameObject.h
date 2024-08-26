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

#ifndef LIB_MONSTA_GAME_OBJECT_H
#define LIB_MONSTA_GAME_OBJECT_H

#include "Monsta/Renderer/Pipeline/Shader.h"

namespace Monsta::Interface
{

class GameObject
{
private:
  Renderer::Shader* m_shader;

public:
  GameObject ();
  virtual ~GameObject () = 0;

public:
  virtual void draw () = 0;
  virtual void stop () = 0;

public:
  virtual void deselect () noexcept;
};

}

#endif /* LIB_MONSTA_GAME_OBJECT_H */
