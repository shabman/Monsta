//
// Created by Mustafa Malik on 05/05/2024.
//

#include "Monsta/Graphics/Shaders/ShaderReader.h"

namespace Monsta::Shaders
{

    ShaderReader::ShaderReader(std::string& fp) : m_FilePath(fp)
    {
        // TODO: Read shader source and append to string
    }

    ShaderReader::~ShaderReader()
    {
        this->m_Stream.close();
    }

    const std::string& ShaderReader::get_contents() noexcept
    {
        return this->m_Source;
    }

    const std::string& ShaderReader::get_file_path() const noexcept
    {
        return this->m_FilePath;
    }

}