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

#include <cstdint>
#include <GLFW/glfw3.h>

namespace Monsta::Core
{
    class Window final
    {
    private:
        GLFWwindow* m_Window;
        uint32_t m_Width;
        uint32_t m_Height;
    
    public:
        Window();
        ~Window();
    
    public:
        void show() noexcept;
        void close() noexcept;

        /// TODO: Make it a pointer of Context*
        void attachContext(void*) noexcept;
        void start() noexcept;
    };
}

#endif /* LIB_MONSTA_WINDOW_H */