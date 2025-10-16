#pragma once
#include "Renderable.hpp"
#include "Shader.hpp"
#include <vector>

namespace Neonix
{
    class SimpleRenderer
    {
    public:
        SimpleRenderer() = default;

        void Submit(Renderable& object);
        void Render(Shader& shader);
    
    private:
        std::vector<Renderable> m_renderQueue;
    };
}