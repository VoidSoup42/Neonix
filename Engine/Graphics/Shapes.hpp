#pragma once

#include "Mesh.hpp"

namespace Neonix
{
    inline std::vector<unsigned short> cube_indices = {
        0, 1, 2, 2, 3, 0,         // Front
        4, 5, 6, 6, 7, 4,         // Back
        8, 9,10,10,11, 8,         // Left
       12,13,14,14,15,12,         // Right
       16,17,18,18,19,16,         // Top
       20,21,22,22,23,20          // Bottom
    };

    inline Mesh create_cube(float width = 1.0f, float height = 1.0f, float depth = 1.0f)
    {
        float w = width * 0.5f;
        float h = height * 0.5f;
        float d = depth * 0.5f;

        std::vector<Vertex> vertices = {
            // Front face (+Z)
            {{-w, -h,  d}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
            {{ w, -h,  d}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
            {{ w,  h,  d}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
            {{-w,  h,  d}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},

            // Back face (-Z)
            {{ w, -h, -d}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f}},
            {{-w, -h, -d}, {0.0f, 0.0f, -1.0f}, {1.0f, 0.0f}},
            {{-w,  h, -d}, {0.0f, 0.0f, -1.0f}, {1.0f, 1.0f}},
            {{ w,  h, -d}, {0.0f, 0.0f, -1.0f}, {0.0f, 1.0f}},

            // Left face (-X)
            {{-w, -h, -d}, {-1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
            {{-w, -h,  d}, {-1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
            {{-w,  h,  d}, {-1.0f, 0.0f, 0.0f}, {1.0f, 1.0f}},
            {{-w,  h, -d}, {-1.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},

            // Right face (+X)
            {{ w, -h,  d}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
            {{ w, -h, -d}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
            {{ w,  h, -d}, {1.0f, 0.0f, 0.0f}, {1.0f, 1.0f}},
            {{ w,  h,  d}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},

            // Top face (+Y)
            {{-w,  h,  d}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}},
            {{ w,  h,  d}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
            {{ w,  h, -d}, {0.0f, 1.0f, 0.0f}, {1.0f, 1.0f}},
            {{-w,  h, -d}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f}},

            // Bottom face (-Y)
            {{-w, -h, -d}, {0.0f, -1.0f, 0.0f}, {0.0f, 0.0f}},
            {{ w, -h, -d}, {0.0f, -1.0f, 0.0f}, {1.0f, 0.0f}},
            {{ w, -h,  d}, {0.0f, -1.0f, 0.0f}, {1.0f, 1.0f}},
            {{-w, -h,  d}, {0.0f, -1.0f, 0.0f}, {0.0f, 1.0f}}
        };
        return Mesh(vertices, cube_indices);
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
                    { posX, 0.0f, posZ },        // position
                    { 0.0f, 1.0f, 0.0f },        // normal
                    { tx * width, tz * depth }   // uv
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

    inline Mesh create_sphere(float radius = 1.0f, unsigned int segments = 32)
    {
        std::vector<Vertex> vertices;
        std::vector<unsigned short> indices;

        // Calculate vertices
        for (unsigned int y = 0; y <= segments; ++y) {
            float phi = static_cast<float>(M_PI) * static_cast<float>(y) / static_cast<float>(segments);
            float sinPhi = std::sin(phi);
            float cosPhi = std::cos(phi);

            for (unsigned int x = 0; x <= segments; ++x) {
                float theta = 2.0f * static_cast<float>(M_PI) * static_cast<float>(x) / static_cast<float>(segments);
                float sinTheta = std::sin(theta);
                float cosTheta = std::cos(theta);

                float px = radius * sinPhi * cosTheta;
                float py = radius * cosPhi;
                float pz = radius * sinPhi * sinTheta;

                // Normal is just the normalized position for a sphere
                float nx = sinPhi * cosTheta;
                float ny = cosPhi;
                float nz = sinPhi * sinTheta;

                // UV coordinates
                float u = static_cast<float>(x) / static_cast<float>(segments);
                float v = static_cast<float>(y) / static_cast<float>(segments);

                vertices.push_back({{px, py, pz}, {nx, ny, nz}, {u, v}});
            }
        }

        // Calculate indices
        for (unsigned int y = 0; y < segments; ++y) {
            for (unsigned int x = 0; x < segments; ++x) {
                unsigned int current = y * (segments + 1) + x;
                unsigned int next = current + 1;
                unsigned int bottom = current + (segments + 1);
                unsigned int bottomNext = bottom + 1;

                indices.push_back(static_cast<unsigned short>(current));
                indices.push_back(static_cast<unsigned short>(bottom));
                indices.push_back(static_cast<unsigned short>(next));

                indices.push_back(static_cast<unsigned short>(next));
                indices.push_back(static_cast<unsigned short>(bottom));
                indices.push_back(static_cast<unsigned short>(bottomNext));
            }
        }

        return Mesh(vertices, indices);
    }
}