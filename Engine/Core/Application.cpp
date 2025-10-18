#include "Application.hpp"

namespace Neonix
{
    Application::Application(const ApplicationProps& props)
    {
        m_window = std::make_shared<Window>(props.title, props.windowSizeX, props.windowSizeY, props.vSync);
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        while (!m_window->ShouldClose())
        {

            for (const std::unique_ptr<Layer>& layer : m_layerStack)
            {
                layer->OnUpdate();
            }

            m_window->Update();
        }
    }
}