#include "Material.hpp"

namespace Neonix
{
    Material::Material()
        : m_shader(
              "/home/sam/Documents/dev/Neonix/Resources/Shaders/SimpleShader.vert",
              "/home/sam/Documents/dev/Neonix/Resources/Shaders/SimpleShader.frag")
    {
    }

    void Material::Bind() const
    {
        m_shader.Bind();
        m_shader.SetUniformFloat("u_uvScaleX", uvScaleX);
        m_shader.SetUniformFloat("u_uvScaleY", uvScaleY);
        if (albedo)
        {
            albedo->Bind(0);
            albedo->SetUnifrom(0, m_shader,"u_albedo");
        }
    }
}