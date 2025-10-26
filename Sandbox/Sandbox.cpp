#include "Sandbox.hpp"

Sandbox::Sandbox()
    : m_cube(Neonix::create_plane(100.0f, 100.0f)),
      m_camera(80.0f, (float)16/9, 0.1f, 100.0f),
      m_cameraController(&m_camera)
{
    m_appInstance = Neonix::Application::GetInstance();

    Neonix::Material cubeMaterial;
    cubeMaterial.albedo = std::make_shared<Neonix::Texture>("/mnt/Data/Assets/Bricks101_4K-JPG/Bricks101_4K-JPG_Color.jpg");
    m_cube.SetMaterial(cubeMaterial);
}

void Sandbox::OnUpdate(float& deltaTime)
{
    m_cameraController.Update(deltaTime);
    m_renderer.Submit(m_cube);
    m_camera.SetAspectRatio((float)m_appInstance->GetWindow()->GetWidth() / (float)m_appInstance->GetWindow()->GetHeight());
    m_renderer.Render(m_camera);
}