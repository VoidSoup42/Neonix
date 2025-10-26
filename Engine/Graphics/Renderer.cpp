#include "Renderer.hpp"
#include <GL/glew.h>
#include <iostream>

namespace Neonix
{
    void Renderer::Submit(const Mesh& object)
    {
        m_renderQueue.push_back(&object);
    }
    
    void Renderer::Render(Camera& camera)
    {
        while (!m_renderQueue.empty())
        {
            const Mesh* obj = m_renderQueue.front();

            if (!obj->HasMaterial())
            {
                std::cerr << "Mesh has no material assigned! Skipping render.\n";
                m_renderQueue.pop_front();
                continue;
            }
            
            obj->GetMaterial().Bind();
            Shader& shader = obj->GetMaterial().GetShader();
            shader.Bind();
            shader.SetUniformMat4("u_proj", camera.GetProj());
            shader.SetUniformMat4("u_view", camera.GetView());
            shader.SetUniformMat4("u_model", obj->GetModelMatrix());

            glBindVertexArray(obj->GetVertexArray());
            glDrawElements(GL_TRIANGLES, obj->GetIndicesCount(), GL_UNSIGNED_SHORT, nullptr);

            m_renderQueue.pop_front();
        }
    }
}