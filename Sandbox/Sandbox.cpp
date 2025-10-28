#include "Sandbox.hpp"

Sandbox::Sandbox()
    : m_plane(Neonix::create_plane(15.0f, 15.0f, 1, 1)),
      m_camera(80.0f, (float)16/9, 0.1f, 100.0f),
      m_cameraController(&m_camera),
      m_cube01(Neonix::create_cube()),
      m_cube02(Neonix::create_cube()),
      m_cube03(Neonix::create_cube()),
      m_clearColor(0.73f, 0.81f, 0.92f)
{
    m_appInstance = Neonix::Application::GetInstance();
    
    Neonix::Material planeMaterial;
    planeMaterial.uvScaleX = 2.0f;
    planeMaterial.uvScaleY = 2.0f;
    planeMaterial.albedo = std::make_shared<Neonix::Texture>("../../Resources/Textures/kenney_prototype-textures/PNG/Green/texture_09.png");
    m_plane.SetMaterial(planeMaterial);

    m_cube01.Translate({-2.0f, 0.5f, -2.0f});
    m_cube02.Translate({2.0f, 0.5f, 1.0f});
    m_cube03.Translate({-2.0f, 0.5f, 2.0f});

    Neonix::Material gridMaterial;
    gridMaterial.albedo = std::make_shared<Neonix::Texture>("../../Resources/Textures/kenney_prototype-textures/PNG/Purple/texture_01.png");

    m_cube01.SetMaterial(gridMaterial);
    m_cube02.SetMaterial(gridMaterial);
    m_cube03.SetMaterial(gridMaterial);
}

void Sandbox::OnUpdate(float& deltaTime)
{
    m_camera.SetAspectRatio((float)m_appInstance->GetWindow()->GetWidth() / (float)m_appInstance->GetWindow()->GetHeight());
    m_cameraController.Update(deltaTime);
    m_renderer.Submit(m_plane);
    m_renderer.Submit(m_cube01);
    m_renderer.Submit(m_cube02);
    m_renderer.Submit(m_cube03);
    m_renderer.Render(m_camera);
}

void Sandbox::OnImGuiRender()
{
    static int location = 0;
    ImGuiIO& io = ImGui::GetIO();
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav;
    if (location >= 0)
    {
        const float PAD = 10.0f;
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImVec2 work_pos = viewport->WorkPos;
        ImVec2 work_size = viewport->WorkSize;
        ImVec2 window_pos, window_pos_pivot;
        window_pos.x = (location & 1) ? (work_pos.x + work_size.x - PAD) : (work_pos.x + PAD);
        window_pos.y = (location & 2) ? (work_pos.y + work_size.y - PAD) : (work_pos.y + PAD);
        window_pos_pivot.x = (location & 1) ? 1.0f : 0.0f;
        window_pos_pivot.y = (location & 2) ? 1.0f : 0.0f;
        ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always, window_pos_pivot);
        window_flags |= ImGuiWindowFlags_NoMove;
    }
    else if (location == -2)
    {
        ImGui::SetNextWindowPos(ImGui::GetMainViewport()->GetCenter(), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
        window_flags |= ImGuiWindowFlags_NoMove;
    }
    ImGui::SetNextWindowBgAlpha(0.35f); // Transparent background
    if (ImGui::Begin("overlay", nullptr, window_flags))
    {
        ImGui::Text("Properties");
        ImGui::Separator();

        ImGui::Text("FPS: %.1f", io.Framerate);

        ImGui::Text("Clear Color");
        ImGui::SameLine();
        ImGui::ColorEdit3("##ClearColor", m_clearColor, ImGuiColorEditFlags_NoInputs);

        glm::vec3 camPos = m_cameraController.GetPosition();
        ImGui::Text("Camera Position: %.1f, %.1f, %.1f", camPos.x, camPos.y, camPos.z);

        m_appInstance->GetWindow()->ClearColor({m_clearColor[0], m_clearColor[1], m_clearColor[2], 1.0f});
        
        if (ImGui::BeginPopupContextWindow())
        {
            if (ImGui::MenuItem("Custom",       NULL, location == -1)) location = -1;
            if (ImGui::MenuItem("Center",       NULL, location == -2)) location = -2;
            if (ImGui::MenuItem("Top-left",     NULL, location == 0)) location = 0;
            if (ImGui::MenuItem("Top-right",    NULL, location == 1)) location = 1;
            if (ImGui::MenuItem("Bottom-left",  NULL, location == 2)) location = 2;
            if (ImGui::MenuItem("Bottom-right", NULL, location == 3)) location = 3;
            ImGui::EndPopup();
        }
    }
    ImGui::End();
}