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

/**
 * @brief Creates one main window to display 3D/2D Graphics.
 * You can only have ONE window per program.
 *
 * @since 0.0.1
 */
class Window final
{
private:
  GLFWwindow* m_window;
  const char* m_title;
  Renderer::Context* m_ctx;

  uint32_t m_width;
  uint32_t m_height;

public:
  /**
   * @brief Constructor for initialising a GLFW Window.
   *
   * @param width - Width of the window.
   * @param height - height of the window.
   * @param title - Title of the window (if applicable).
   */
  Window ( uint32_t, uint32_t, const char* );
  ~Window ();

public:
  /**
   * @brief Initialises the GLFW Window and creates an OpenGL Context.
   */
  void init () noexcept;
  /**
   * @brief Manually closes the GLFW Window and destroys the OpenGL Context.
   */
  void close () noexcept;

public:
  /**
   * @brief Attaches a specific renderer to the window. Different OSes have different
   * Rendering Frameworks (Windows DirectX, Apple Metal, Android OpenGLES, etc), so this
   * method allows you to manually specify which context to use. The default is OpenGL.
   *
   * @param context - The renderer context the window will use to render game objects.
   *
   * @note If a context that is not supported on the current OS is given, the fall-back
   * will use OpenGL as the context.
   */
  void attachContext ( const Renderer::Context* ) noexcept;
  /**
   * @brief Starts the renderer and creates the main game loop.
   */
  void start () noexcept;

public:
  /**
   * @brief Gets a pointer to the GLFW Window.
   *
   * @return A pointer to the GLFW Window in use.
   *
   * @note It is recommended to not directly modify the GLFW Window.
   */
  GLFWwindow* getCoreWindow () const noexcept;
  /**
   * @brief Gets the current title of the window.
   *
   * @return The title of the current window.
   */
  const char* getTitle () const noexcept;
  /**
   * @brief Gets the current context on the window.
   *
   * @return The context used on the current window.
   */
  Renderer::Context* getContext () const noexcept;
  /**
   * @brief Gets the width of the window.
   *
   * @return The width of the window.
   */
  uint32_t getWidth () const noexcept;
  /**
   * @brief Gets the height of the window.
   *
   * @return The height of the window.
   */
  uint32_t getHeight () const noexcept;
};

}

#endif /* LIB_MONSTA_WINDOW_H */
