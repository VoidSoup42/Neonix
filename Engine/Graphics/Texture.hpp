#pragma once

#include <GL/glew.h>
#include "Shader.hpp"

namespace Neonix
{
    class Texture
    {
    public:
        Texture(const char* path);
        ~Texture();

        void Bind(uint32_t solt) const;
        void Unbind() const;
        void SetUnifrom(uint32_t slot, Shader& shader, const char* uniformName) const;

    private:
        uint32_t m_id = 0;
    };
}