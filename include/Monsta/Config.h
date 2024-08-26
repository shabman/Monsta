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

#ifndef LIB_MONSTA_CONFIG_H
#define LIB_MONSTA_CONFIG_H

// clang-format off

#if defined( __APPLE__ )
# include <TargetConditionals.h>
# if defined( TARGET_OS_MAC )
#   if defined(__i386__) || defined(__x86_64__)
#     error This Project Only Supports Apple Silicon    
#   endif
#   define MONSTA_PLAT_MAC
# elif defined( TARGET_OS_IPHONE )
#   define MONSTA_PLAT_IPHONE
# endif
#elif defined( __unix__ ) || defined( __unix ) || defined( unix )
# define MONSTA_PLAT_LINUX
#elif defined( _WIN32 ) || defined( _WIN64 )
# define MONSTA_PLAT_WIN
#elif defined( __ANDROID__ )
# define MONSTA_PLAT_ANDROID
#else
# error Unknown Platform Detected. Aborting...
#endif

#if __cplusplus < 201703
# error Compiler is outdated, Please use C++17 to compile this project.
#endif

#ifndef _glfw3_h_
# ifdef LIB_MONSTA_FORWARD_GLFW_DECL
#   define GLFW_WINDOW_DECL() struct GLFWwindow;
# endif
#endif

#define MONSTA_OPENGL_MAJOR_VERSION 4
#define MONSTA_OPENGL_MINOR_VERSION 1

// clang-format on

#ifdef MONSTA_UTIL_FUNCS

#include <tuple>
#include <variant>

template <size_t V, typename... T>
decltype ( auto ) GetParameterPackValue ( T&&... args ) noexcept
{
  return std::get<V> ( std::forward_as_tuple ( std::forward<T> ( args )... ) );
}

#endif

#endif /* LIB_MONSTA_CONFIG_H */
