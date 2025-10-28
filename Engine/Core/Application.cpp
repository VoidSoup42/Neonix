#include "Application.hpp"
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

namespace Neonix
{
    Application* Application::s_instance = nullptr;

    Application::Application(const ApplicationProps& props)
    {
        m_window = std::make_shared<Window>(props.title, props.windowSizeX, props.windowSizeY, props.vSync);
        s_instance = this;

        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(m_window->GetGLFWWindow(), true);
        ImGui_ImplOpenGL3_Init();
    }

    Application::~Application()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        s_instance = nullptr;
    }

    Application* Application::GetInstance()
    {
        return s_instance;
    }

    void Application::Run()
    {
        float deltaTime = 0.0f; // Time between current frame and last frame
        float lastFrame = 0.0f;
        while (!m_window->ShouldClose())
        {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            float currentFrame = glfwGetTime();
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;
            
            m_window->Clear();

            for (const std::unique_ptr<Layer>& layer : m_layerStack)
            {
                layer->OnUpdate(deltaTime);
            }

            for (const std::unique_ptr<Layer>& layer : m_layerStack)
            {
                layer->OnImGuiRender();
            }

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            m_window->Update();
        }
    }
}