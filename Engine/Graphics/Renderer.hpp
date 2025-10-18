#pragma once

#include "Renderable.hpp"
#include "Shader.hpp"
#include "Camera.hpp"
#include <deque>

namespace Neonix
{
    class Renderer
    {
    public:
        Renderer() = default;

        void Submit(const Renderable& object);
        void Render(Shader& shader, Camera& camera);
    
    private:
        std::deque<const Renderable*> m_renderQueue;
    };
}