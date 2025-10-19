#pragma once

#include "Texture.hpp"
#include "Shader.hpp"
#include <memory>

namespace Neonix
{
    class Material
    {
    public:
        std::shared_ptr<Texture> albedo;

        inline void Bind(Shader& shader) const
        {
            if (albedo)
            {
                albedo->Bind(0);
                albedo->SetUnifrom(0, shader, "u_albedo");
            }
        }
    };
}