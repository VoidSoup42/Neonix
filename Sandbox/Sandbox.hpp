#pragma once

#include <Neonix.hpp>

class Sandbox : public Neonix::Layer
{
public:
    Sandbox();
    void OnUpdate(float& deltaTime) override;

private:
    Neonix::Application* m_appInstance;
    Neonix::Renderer m_renderer;
    Neonix::Mesh m_cube;
    Neonix::Camera m_camera;
};
