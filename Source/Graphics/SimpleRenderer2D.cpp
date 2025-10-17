#include "SimpleRenderer2D.hpp"
#include <GL/glew.h>
#include <iostream>

namespace Neonix
{
    void SimpleRenderer2D::Submit(Renderable& object)
    {
        m_renderQueue.push_back(&object);
    }
    
    void SimpleRenderer2D::Render(Shader& shader)
    {
        shader.Bind();

        while (!m_renderQueue.empty())
        {
            const Renderable* obj = m_renderQueue.front();
            
            glBindVertexArray(obj->GetVertexArray());
            glDrawElements(GL_TRIANGLES, obj->GetIndicesCount(), GL_UNSIGNED_SHORT, nullptr);            

            m_renderQueue.pop_front();
        }
    }
}