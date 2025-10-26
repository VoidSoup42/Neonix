#include "Sandbox.hpp"

Sandbox::Sandbox()
    : m_plane(Neonix::create_plane(100.0f, 100.0f)),
      m_sphere(Neonix::create_sphere()),
      m_camera(80.0f, (float)16/9, 0.1f, 100.0f),
      m_cameraController(&m_camera)
{
    m_appInstance = Neonix::Application::GetInstance();
    m_appInstance->GetWindow()->ClearColor({0.53f, 0.81f, 0.92f, 1.0f});
    
    Neonix::Material planeMaterial;
    planeMaterial.albedo = std::make_shared<Neonix::Texture>("/mnt/Data/Assets/Ground003_2K-JPG/Ground003_2K-JPG_Color.jpg");
    m_plane.SetMaterial(planeMaterial);

    m_sphere.Translate({0.0f, 1.0f, 0.0f});
    m_sphere.SetMaterial(planeMaterial);

}

void Sandbox::OnUpdate(float& deltaTime)
{
    m_cameraController.Update(deltaTime);
    m_renderer.Submit(m_sphere);
    m_renderer.Submit(m_plane);
    m_camera.SetAspectRatio((float)m_appInstance->GetWindow()->GetWidth() / (float)m_appInstance->GetWindow()->GetHeight());
    m_renderer.Render(m_camera);
}