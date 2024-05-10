//
// Created by Mustafa Malik on 11/05/2024.
//

#ifndef __LIBMONSTA_GRAPHICS_SHADERS_SHADERSYSTEMH_H__
#define __LIBMONSTA_GRAPHICS_SHADERS_SHADERSYSTEMH_H__

#include <string>
#include <tuple>

namespace Monsta
{

    enum class ShaderType
    {
        MONSTA_VERTEX_SHADER,
        MONSTA_FRAGMENT_SHADER
    };

    class ShaderSystem
    {

    private:
        std::string m_Source;

    public:
        ShaderSystem(const std::string&);
        ~ShaderSystem();

    public:
        std::tuple<bool, unsigned int> compile_shader(const ShaderType&) noexcept;
        bool link_shader(const unsigned int&, const unsigned int&) noexcept;
        const std::string& get_source() const noexcept;

    public:
        static unsigned int get_shader_pid() noexcept;
        static void destroy_shader_pid(const unsigned int&) noexcept;

    };
}

#endif /* __LIBMONSTA_GRAPHICS_SHADERS_SHADERSYSTEMH_H__ */
