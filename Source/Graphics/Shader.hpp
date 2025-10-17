#pragma once

#include <GL/glew.h>

namespace Neonix
{
    class Shader
    {
    public:
        Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
        ~Shader();

        void Bind() const;
        void UnBind() const;

        inline uint32_t GetId() const { return m_id; }

    private:
        uint32_t m_id = 0;
    };
}