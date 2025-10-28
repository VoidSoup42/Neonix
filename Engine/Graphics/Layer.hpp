#pragma once

namespace Neonix
{
    class Layer
    {
    public:
        virtual ~Layer() {};
        virtual void OnUpdate(float& deltaTime) {};
        virtual void OnImGuiRender() {};
    };
}