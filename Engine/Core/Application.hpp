#pragma once

#include "../Graphics/Layer.hpp"
#include "Window.hpp"
#include <memory>
#include <vector>

namespace Neonix
{
    struct ApplicationProps
    {
        const char* title;
        uint32_t windowSizeX;
        uint32_t windowSizeY;
        bool vSync;
    };

    class Application
    {
    public:
        Application(const ApplicationProps& props);
        ~Application();

        // requires(std::is_base_of<Layer, TLayer>)
        template<typename TLayer>
        void PushLayer()
        {
            m_layerStack.push_back(std::make_unique<TLayer>());
        }

        void Run();

    private:
        std::shared_ptr<Window> m_window;
        std::vector<std::unique_ptr<Layer>> m_layerStack;
    };
}