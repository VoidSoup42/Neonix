#pragma once

#include <glm/glm.hpp>
#include <vector>

namespace Neonix
{
    struct Vertex
    {
        glm::vec3 position;
        glm::vec3 normals;
        glm::vec2 texCoords;
    };

    class Renderable
    {
    public:
        Renderable(std::vector<Vertex>& vertices, std::vector<unsigned short>& indices);
        ~Renderable();

        void Translate(const glm::vec3& pos);
        void Rotate(const glm::vec3& eulerAngles);

        inline uint32_t GetVertexArray() const { return m_vertexArray; }
        inline uint32_t GetIndicesCount() const { return m_indicesCount; }
        inline const glm::mat4& GetModelMatrix() const { return m_modelMatrix; }

    private:
        uint32_t m_vertexArray = 0;
        uint32_t m_vertexBuffer = 0;
        uint32_t m_indexBuffer = 0;
        uint32_t m_indicesCount;
        
        glm::mat4 m_modelMatrix;
    };
}