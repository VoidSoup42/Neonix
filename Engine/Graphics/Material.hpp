#pragma once

#include "Texture.hpp"
#include "Shader.hpp"
#include <memory>

namespace Neonix
{
    class Material
    {
    public:
        Material();
        std::shared_ptr<Texture> albedo;
        float uvScaleX = 1.0f;
        float uvScaleY = 1.0f;
        
        inline Shader& GetShader() { return m_shader; }
        void Bind() const;
    
    private:
        Shader m_shader;
    };
}