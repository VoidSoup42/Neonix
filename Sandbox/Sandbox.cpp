#include "Sandbox.hpp"

Sandbox::Sandbox()
    : m_plane(Neonix::create_plane(15.0f, 15.0f, 1, 1)),
      m_camera(80.0f, (float)16/9, 0.1f, 100.0f),
      m_cameraController(&m_camera),
      m_cube01(Neonix::create_cube()),
      m_cube02(Neonix::create_cube()),
      m_cube03(Neonix::create_cube())
{
    m_appInstance = Neonix::Application::GetInstance();
    m_appInstance->GetWindow()->ClearColor({0.73f, 0.81f, 0.92f, 1.0f});
    
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