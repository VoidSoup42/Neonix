#include "SimpleRenderer.hpp"
#include <GL/glew.h>
#include <iostream>

namespace Neonix
{
    void SimpleRenderer::Submit(Renderable& object)
    {
        m_renderQueue.emplace_back(object);
    }
    
    void SimpleRenderer::Render(Shader& shader)
    {
        for (uint32_t i = 0; i < m_renderQueue.size(); i++)
        {
            Renderable& obj = m_renderQueue.front();

            shader.Bind();
            
            glBindVertexArray(obj.GetVertexArray());
            glDrawElements(GL_TRIANGLES, obj.GetIndicesCount(), GL_UNSIGNED_SHORT, nullptr);            
        }
    }
}