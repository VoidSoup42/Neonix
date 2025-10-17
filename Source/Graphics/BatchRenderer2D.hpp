#pragma once

#include "Shader.hpp"

namespace Neonix
{
    class BatchRenderer
    {
    public:
        BatchRenderer();

    private:
        Shader m_shader;
        
    };
}