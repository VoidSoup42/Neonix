#include "Renderer.hpp"
#include <GL/glew.h>
#include <iostream>

namespace Neonix
{
    void Renderer::Submit(const Renderable& object)
    {
        m_renderQueue.push_back(&object);
    }
    
    void Renderer::Render(Shader& shader)
    {
        shader.Bind();

        while (!m_renderQueue.empty())
        {
            const Renderable* obj = m_renderQueue.front();
            
            shader.SetUniformMat4("u_model", obj->GetModelMatrix());
            glBindVertexArray(obj->GetVertexArray());
            glDrawElements(GL_TRIANGLES, obj->GetIndicesCount(), GL_UNSIGNED_SHORT, nullptr);            

            m_renderQueue.pop_front();
        }
    }
}