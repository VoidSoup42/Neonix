#include "Sandbox.hpp"

Sandbox::Sandbox()
    : m_cube(Neonix::create_cube()),
      m_shader(
          "/home/sam/Documents/dev/Neonix/Resources/Shaders/SimpleShader.vert",
          "/home/sam/Documents/dev/Neonix/Resources/Shaders/SimpleShader.frag"),
      m_camera(80.0f, 16/9, 0.1f, 100.0f)
{
    m_appInstance = Neonix::Application::GetInstance();
}

Sandbox::~Sandbox()
{
    delete m_appInstance;
}

void Sandbox::OnUpdate()
{
    m_renderer.Submit(m_cube);

    m_camera.SetAspectRatio(
        static_cast<float>(m_appInstance->GetWindow()->GetWidth()) /
        static_cast<float>(m_appInstance->GetWindow()->GetHeight())
    );

    m_renderer.Render(m_shader, m_camera);
}