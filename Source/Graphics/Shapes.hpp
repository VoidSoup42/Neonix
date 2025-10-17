#pragma once

#include "Renderable.hpp"

namespace Neonix
{
    inline std::vector<Vertex> quad_vertices = {
        { {-0.5f, -0.5f,  0.0f}, {0.0f, 0.0f, 0.0f, 1.0f} }, // Bottom Left
        { { 0.5f, -0.5f,  0.0f}, {1.0f, 0.0f, 0.0f, 1.0f} }, // Bottom Right
        { { 0.5f,  0.5f,  0.0f}, {1.0f, 1.0f, 0.0f, 1.0f} }, // Top Right
        { {-0.5f,  0.5f,  0.0f}, {0.0f, 1.0f, 0.0f, 1.0f} }  // Top Left
    };

    inline std::vector<unsigned short> quad_indices = {
        0, 1, 2,
        2, 3, 0
    };

    inline Renderable create_quad()
    {
        return Renderable(quad_vertices, quad_indices);
    }
}