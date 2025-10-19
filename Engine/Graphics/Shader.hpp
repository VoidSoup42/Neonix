#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

namespace Neonix
{
    class Shader
    {
    public:
        Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
        ~Shader();

        void Bind() const;
        void UnBind() const;

        void SetUniformMat4(const char* name, const glm::mat4& value);
        void SetUniformInt(const char* name, int value);
        inline uint32_t GetId() const { return m_id; }

    private:
        uint32_t m_id = 0;
    };
}