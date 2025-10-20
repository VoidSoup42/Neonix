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
        float deltaTime = 0.0f; // Time between current frame and last frame
        float lastFrame = 0.0f; // Time of last frame
        while (!m_window->ShouldClose())
        {
            float currentFrame = glfwGetTime(); // Get current time in seconds
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;
            
            m_window->Clear();

            for (const std::unique_ptr<Layer>& layer : m_layerStack)
            {
                layer->OnUpdate(deltaTime);
            }

            m_window->Update();
        }
    }
}