#include "Material.hpp"

namespace Neonix
{
    Material::Material()
        : m_shader(
              "../../Resources/Shaders/SimpleShader.vert",
              "../../Resources/Shaders/SimpleShader.frag")
    {
    }

    void Material::Bind() const
    {
        m_shader.Bind();
        m_shader.SetUniformFloat("u_uvScaleX", uvScaleX);
        m_shader.SetUniformFloat("u_uvScaleY", uvScaleY);
        if (albedo)
        {
            m_shader.SetUniformInt("u_useAlbedo", 1);
            albedo->Bind(0);
            albedo->SetUniform(0, m_shader, "u_albedo");
        }
        else
        {
            m_shader.SetUniformInt("u_useAlbedo", 0);
            m_shader.SetUniformVec4("u_diffuseColor", diffuseColor);
        }
    }
}