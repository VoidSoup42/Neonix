#include "Application.hpp"

namespace Neonix
{
    Application* Application::s_instance = nullptr;

    Application::Application(const ApplicationProps& props)
    {
        m_window = std::make_shared<Window>(props.title, props.windowSizeX, props.windowSizeY, props.vSync);
        s_instance = this;
    }

    Application::~Application()
    {
        s_instance = nullptr;
    }

    Application* Application::GetInstance()
    {
        return s_instance;
    }

    void Application::Run()
    {
        while (!m_window->ShouldClose())
        {
            m_window->Clear();

            for (const std::unique_ptr<Layer>& layer : m_layerStack)
            {
                layer->OnUpdate();
            }

            m_window->Update();
        }
    }
}