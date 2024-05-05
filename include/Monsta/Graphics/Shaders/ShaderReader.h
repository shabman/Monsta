//
// Created by Mustafa Malik on 05/05/2024.
//

#ifndef __LIB_MONSTA_GRAPHICS_SHADERS_SHADER_READER_H__
#define __LIB_MONSTA_GRAPHICS_SHADERS_SHADER_READER_H__

#include <fstream>
#include <string>

namespace Monsta::Shaders
{

    class ShaderReader
    {
    private:
        std::string m_Source;
        std::string m_FilePath;
        std::fstream m_Stream;

    public:
        explicit ShaderReader(std::string&);
        ~ShaderReader();

        ShaderReader(const ShaderReader&) = delete;
        ShaderReader operator = (const ShaderReader&) = delete;

    public:
        const std::string& get_contents() noexcept;
        const std::string& get_file_path() const noexcept;
    };
}

#endif /* __LIB_MONSTA_GRAPHICS_SHADERS_SHADER_READER_H__ */
