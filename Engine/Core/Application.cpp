#include "Application.hpp"

namespace Neonix
{
    // Define the static instance storage
    Application* Application::s_instance = nullptr;

    Application::Application(const ApplicationProps& props)
    {
        m_window = std::make_shared<Window>(props.title, props.windowSizeX, props.windowSizeY, props.vSync);
        s_instance = this;
    }

    Application::~Application()
    {
        // Clear the static instance pointer. Do not delete s_instance; it points to this object.
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