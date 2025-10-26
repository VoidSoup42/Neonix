#pragma once

#include "Mesh.hpp"

namespace Neonix
{
    // Quad (XY plane) - z = 0
    inline std::vector<Vertex> quad_vertices = {
        {{-0.5f, -0.5f,  0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}}, // Bottom Left
        {{ 0.5f, -0.5f,  0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}}, // Bottom Right
        {{ 0.5f,  0.5f,  0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}}, // Top Right
        {{-0.5f,  0.5f,  0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}}  // Top Left
    };

    inline std::vector<unsigned short> quad_indices = {
        0, 1, 2,
        2, 3, 0
    };

    inline Mesh create_quad()
    {
        return Mesh(quad_vertices, quad_indices);
    }

    // Cube vertices and indices
    inline std::vector<Vertex> cube_vertices = {
        // Front face (+Z)
        {{-0.5f, -0.5f,  0.5f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
        {{ 0.5f, -0.5f,  0.5f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
        {{ 0.5f,  0.5f,  0.5f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
        {{-0.5f,  0.5f,  0.5f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},

        // Back face (-Z)
        {{ 0.5f, -0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f}},
        {{-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {1.0f, 0.0f}},
        {{-0.5f,  0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {1.0f, 1.0f}},
        {{ 0.5f,  0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {0.0f, 1.0f}},

        // Left face (-X)
        {{-0.5f, -0.5f, -0.5f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
        {{-0.5f, -0.5f,  0.5f}, {-1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
        {{-0.5f,  0.5f,  0.5f}, {-1.0f, 0.0f, 0.0f}, {1.0f, 1.0f}},
        {{-0.5f,  0.5f, -0.5f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},

        // Right face (+X)
        {{ 0.5f, -0.5f,  0.5f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
        {{ 0.5f, -0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
        {{ 0.5f,  0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}, {1.0f, 1.0f}},
        {{ 0.5f,  0.5f,  0.5f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},

        // Top face (+Y)
        {{-0.5f,  0.5f,  0.5f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}},
        {{ 0.5f,  0.5f,  0.5f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
        {{ 0.5f,  0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}, {1.0f, 1.0f}},
        {{-0.5f,  0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f}},

        // Bottom face (-Y)
        {{-0.5f, -0.5f, -0.5f}, {0.0f, -1.0f, 0.0f}, {0.0f, 0.0f}},
        {{ 0.5f, -0.5f, -0.5f}, {0.0f, -1.0f, 0.0f}, {1.0f, 0.0f}},
        {{ 0.5f, -0.5f,  0.5f}, {0.0f, -1.0f, 0.0f}, {1.0f, 1.0f}},
        {{-0.5f, -0.5f,  0.5f}, {0.0f, -1.0f, 0.0f}, {0.0f, 1.0f}}
    };

    inline std::vector<unsigned short> cube_indices = {
        0, 1, 2, 2, 3, 0,         // Front
        4, 5, 6, 6, 7, 4,         // Back
        8, 9,10,10,11, 8,         // Left
       12,13,14,14,15,12,         // Right
       16,17,18,18,19,16,         // Top
       20,21,22,22,23,20          // Bottom
    };

    inline Mesh create_cube()
    {
        return Mesh(cube_vertices, cube_indices);
    }

    inline Mesh create_plane(float width = 1.0f, float depth = 1.0f, unsigned int segX = 1, unsigned int segZ = 1)
    {
        std::vector<Vertex> vertices;
        std::vector<unsigned short> indices;

        const unsigned int cols = segX + 1;
        const unsigned int rows = segZ + 1;
        vertices.reserve(cols * rows);
        indices.reserve(segX * segZ * 6);

        for (unsigned int z = 0; z < rows; ++z) {
            float tz = static_cast<float>(z) / static_cast<float>(segZ);
            float posZ = (tz - 0.5f) * depth;
            for (unsigned int x = 0; x < cols; ++x) {
                float tx = static_cast<float>(x) / static_cast<float>(segX);
                float posX = (tx - 0.5f) * width;
                vertices.push_back({
                    { posX, 0.0f, posZ },    // position (XZ plane, y = 0)
                    { 0.0f, 1.0f, 0.0f },    // normal (up)
                    { tx, tz }               // uv
                });
            }
        }

        for (unsigned int z = 0; z < segZ; ++z) {
            for (unsigned int x = 0; x < segX; ++x) {
                unsigned int i0 = z * cols + x;
                unsigned int i1 = i0 + 1;
                unsigned int i2 = i0 + cols;
                unsigned int i3 = i2 + 1;

                indices.push_back(static_cast<unsigned short>(i0));
                indices.push_back(static_cast<unsigned short>(i2));
                indices.push_back(static_cast<unsigned short>(i3));

                indices.push_back(static_cast<unsigned short>(i3));
                indices.push_back(static_cast<unsigned short>(i1));
                indices.push_back(static_cast<unsigned short>(i0));
            }
        }

        return Mesh(vertices, indices);
    }
}