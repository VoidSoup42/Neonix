#include "Sandbox.hpp"
#include <glm/gtc/matrix_transform.hpp>

Sandbox::Sandbox() : m_cube(Neonix::create_cube()), m_shader("/home/sam/Documents/dev/Neonix/Resources/Shaders/SimpleShader.vert", "/home/sam/Documents/dev/Neonix/Resources/Shaders/SimpleShader.frag")
{
    glm::vec3 cameraPos   = {0.0f, 0.0f, 3.0f};
    glm::vec3 cameraTarget= {0.0f, 0.0f, 0.0f};
    glm::vec3 cameraUp    = {0.0f, 1.0f, 0.0f};
    m_view = glm::lookAt(cameraPos, cameraTarget, cameraUp);
    m_appInstance = Neonix::Application::GetInstance();
}

Sandbox::~Sandbox()
{
    delete m_appInstance;
}

void Sandbox::OnUpdate()
{
    glm::mat4 proj = glm::perspective((float)glm::radians(80.0), (float)m_appInstance->GetWindow()->GetWidth() / m_appInstance->GetWindow()->GetHeight(), 0.1f, 100.0f);

    m_shader.SetUniformMat4("u_proj", proj);
    m_shader.SetUniformMat4("u_view", m_view);
    
    m_renderer.Submit(m_cube);

    m_renderer.Render(m_shader);
}