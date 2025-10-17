#pragma once

#include "Renderable.hpp"
#include "Shader.hpp"
#include <deque>

namespace Neonix
{
    class SimpleRenderer2D
    {
    public:
        SimpleRenderer2D() = default;

        void Submit(Renderable& object);
        void Render(Shader& shader);
    
    private:
        std::deque<const Renderable*> m_renderQueue;
    };
}