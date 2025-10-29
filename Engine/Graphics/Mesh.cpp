#include "Mesh.hpp"
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>

namespace Neonix
{
    Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices)
        : m_indicesCount(indices.size()),
          m_modelMatrix(1.0f)
    {
        glGenVertexArrays(1, &m_vertexArray);
        glBindVertexArray(m_vertexArray);

        glGenBuffers(1, &m_vertexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
        glNamedBufferData(m_vertexBuffer, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

        // Position
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, 0, sizeof(float) * 8, (void*)offsetof(Vertex, position));

        // Normals
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, 0, sizeof(float) * 8, (void*)offsetof(Vertex, normal));

        // Tex Coords
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, 0, sizeof(float) * 8, (void*)offsetof(Vertex, texCoord));

        glGenBuffers(1, &m_indexBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);
        glNamedBufferData(m_indexBuffer, indices.size() * sizeof(uint32_t), indices.data(), GL_STATIC_DRAW);

        glBindVertexArray(0);
    }

    Mesh::~Mesh()
    {
        glDeleteVertexArrays(1, &m_vertexArray);
        glDeleteBuffers(1, &m_vertexBuffer);
        glDeleteBuffers(1, &m_indexBuffer);
    }

    void Mesh::Translate(const glm::vec3& pos)
    {
        m_modelMatrix = glm::translate(m_modelMatrix, pos);
    }

    void Mesh::Rotate(const glm::vec3& eulerAngles)
    {
        m_modelMatrix = glm::rotate(m_modelMatrix, eulerAngles.x, glm::vec3(1, 0, 0));
        m_modelMatrix = glm::rotate(m_modelMatrix, eulerAngles.y, glm::vec3(0, 1, 0));
        m_modelMatrix = glm::rotate(m_modelMatrix, eulerAngles.z, glm::vec3(0, 0, 1));
    }

    void Mesh::Scale(const glm::vec3& scale)
    {
        m_modelMatrix = glm::scale(m_modelMatrix, scale);
    }

    void Mesh::SetMaterial(const Material& material)
    {
        m_hasMaterial = true;
        m_material = std::make_unique<Material>();
        m_material->albedo = material.albedo;
        m_material->diffuseColor = material.diffuseColor;
        m_material->uvScaleX = material.uvScaleX;
        m_material->uvScaleY = material.uvScaleY;
    }
}