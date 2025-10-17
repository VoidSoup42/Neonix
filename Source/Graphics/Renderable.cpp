#include "Renderable.hpp"
#include <GL/glew.h>

namespace Neonix
{
    Renderable::Renderable(std::vector<Vertex>& vertices, std::vector<unsigned short>& indices) : m_indicesCount(indices.size()), m_modelMatrix(1.0f)
    {
        glGenVertexArrays(1, &m_vertexArray);
        glBindVertexArray(m_vertexArray);

        glGenBuffers(1, &m_vertexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
        glNamedBufferData(m_vertexBuffer, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

        // Position
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, 0, sizeof(float) * 7, (void*)offsetof(Vertex, position));

        // Color
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 4, GL_FLOAT, 0, sizeof(float) * 7, (void*)offsetof(Vertex, color));

        glGenBuffers(1, &m_indexBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);
        glNamedBufferData(m_indexBuffer, indices.size() * sizeof(unsigned short), indices.data(), GL_STATIC_DRAW);

        glBindVertexArray(0);
    }

    Renderable::~Renderable()
    {
        glDeleteVertexArrays(1, &m_vertexArray);
        glDeleteBuffers(1, &m_vertexBuffer);
        glDeleteBuffers(1, &m_indexBuffer);
    }
}