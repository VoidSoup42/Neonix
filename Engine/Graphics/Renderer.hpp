#pragma once

#include "Mesh.hpp"
#include "Shader.hpp"
#include "Camera.hpp"
#include <deque>

namespace Neonix
{
    class Renderer
    {
    public:
        Renderer() = default;

        void Submit(const Mesh& object);
        void Render(Camera& camera);
    
    private:
        std::deque<const Mesh*> m_renderQueue;
    };
}