#include "Sandbox.hpp"

Sandbox::Sandbox()
    : m_cube(Neonix::create_cube()),
      m_shader(
          "/home/sam/Documents/dev/Neonix/Resources/Shaders/SimpleShader.vert",
          "/home/sam/Documents/dev/Neonix/Resources/Shaders/SimpleShader.frag"),
      m_camera(80.0f, (float)16/9, 0.1f, 100.0f)
{
    m_appInstance = Neonix::Application::GetInstance();

    m_appInstance->GetWindow()->ClearColor({ 1.0f, 1.0f, 1.0f, 1.0f });

    Neonix::Material cubeMaterial;

    cubeMaterial.albedo = std::make_shared<Neonix::Texture>("/mnt/Data/Assets/Bricks101_4K-JPG/Bricks101_4K-JPG_Color.jpg");

    m_cube.SetMaterial(cubeMaterial);
}

Sandbox::~Sandbox()
{
    m_appInstance = nullptr;
}

void Sandbox::OnUpdate()
{
    m_renderer.Submit(m_cube);

    m_camera.SetAspectRatio((float)m_appInstance->GetWindow()->GetWidth() / (float)m_appInstance->GetWindow()->GetHeight());

    m_renderer.Render(m_shader, m_camera);
}