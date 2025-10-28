#pragma once

#include <glm/glm.hpp>
#include <vector>
#include "Material.hpp"

namespace Neonix
{
    struct Vertex
    {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 texCoord;
    };

    class Mesh
    {
    public:
        Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);
        ~Mesh();

        void SetMaterial(const Material& material);
        inline bool HasMaterial() const { return m_hasMaterial; }

        void Translate(const glm::vec3& pos);
        void Rotate(const glm::vec3& eulerAngles);

        inline uint32_t GetVertexArray() const { return m_vertexArray; }
        inline uint32_t GetIndicesCount() const { return m_indicesCount; }
        inline Material& GetMaterial() const { return *m_material; }
        inline const glm::mat4& GetModelMatrix() const { return m_modelMatrix; }

    private:
        uint32_t m_vertexArray = 0;
        uint32_t m_vertexBuffer = 0;
        uint32_t m_indexBuffer = 0;
        uint32_t m_indicesCount;
        
        glm::mat4 m_modelMatrix;
        std::unique_ptr<Material> m_material;
        bool m_hasMaterial = false;
    };
}