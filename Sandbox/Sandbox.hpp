#pragma once

#include <Neonix.hpp>

class Sandbox : public Neonix::Layer
{
public:
    Sandbox();
    ~Sandbox() override;

    void OnUpdate() override;

private:
    Neonix::Application* m_appInstance;
    Neonix::Renderer m_renderer;
    Neonix::Renderable m_cube;
    Neonix::Shader m_shader;
    Neonix::Camera m_camera;
};
