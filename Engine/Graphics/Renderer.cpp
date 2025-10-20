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
        Shader& shader = m_renderQueue.front()->GetMaterial().GetShader();
        shader.Bind();
        shader.SetUniformMat4("u_proj", camera.GetProj());
        shader.SetUniformMat4("u_view", camera.GetView());

        while (!m_renderQueue.empty())
        {
            const Mesh* obj = m_renderQueue.front();
            shader.SetUniformMat4("u_model", obj->GetModelMatrix());
            obj->GetMaterial().Bind();
            glBindVertexArray(obj->GetVertexArray());

            glDrawElements(GL_TRIANGLES, obj->GetIndicesCount(), GL_UNSIGNED_SHORT, nullptr);

            m_renderQueue.pop_front();
        }
    }
}