#include "Shader.hpp"
#include "../Utils/FileUtils.hpp"
#include <glm/gtc/type_ptr.hpp>

namespace Neonix
{
    void checkShaderCompilation(GLuint shader, const std::string& name)
    {
        GLint success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            GLint logLength;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
            std::string infoLog(logLength, ' ');
            glGetShaderInfoLog(shader, logLength, nullptr, &infoLog[0]);
            std::cout << "ERROR: Shader compilation failed (" << name << ")" << std::endl << infoLog << std::endl;
        }
    }

    Shader::Shader(const char *vertexShaderPath, const char *fragmentShaderPath)
    {
        uint32_t vs = glCreateShader(GL_VERTEX_SHADER);
        uint32_t fs = glCreateShader(GL_FRAGMENT_SHADER);

        std::string vsSource = read_file(vertexShaderPath);
        std::string fsSource = read_file(fragmentShaderPath);

        const char* vsCharStr = vsSource.c_str();
        const char* fsCharStr = fsSource.c_str();

        glShaderSource(vs, 1, &vsCharStr, nullptr);
        glShaderSource(fs, 1, &fsCharStr, nullptr);

        glCompileShader(vs);
        checkShaderCompilation(vs, "Vertex Shader");
        
        glCompileShader(fs);
        checkShaderCompilation(fs, "Fragment Shader");

        m_id = glCreateProgram();
        glAttachShader(m_id, vs);
        glAttachShader(m_id, fs);

        glLinkProgram(m_id);
        GLint success;
        glGetProgramiv(m_id, GL_LINK_STATUS, &success);
        if (!success)
        {
            GLint logLength;
            glGetProgramiv(m_id, GL_INFO_LOG_LENGTH, &logLength);
            std::string infoLog(logLength, ' ');
            glGetProgramInfoLog(m_id, logLength, nullptr, &infoLog[0]);
            std::cout << "ERROR: Program linking failed" << std::endl << infoLog << std::endl;
        }

        glDeleteShader(vs);
        glDeleteShader(fs);
    }

    Shader::~Shader()
    {
        glDeleteProgram(m_id);
    }

    void Shader::Bind() const
    {
        glUseProgram(m_id);
    }

    void Shader::UnBind() const
    {
        glUseProgram(0);
    }

    void Shader::SetUniformMat4(const char* name, const glm::mat4& value)
    {
        glUniformMatrix4fv(glGetUniformLocation(m_id, name), 1, false, glm::value_ptr(value));
    }

    void Shader::SetUniformInt(const char* name, int value)
    {
        glUniform1i(glGetUniformLocation(m_id, name), value);
    }
}