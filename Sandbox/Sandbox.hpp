#pragma once

#include <Neonix.hpp>
#include "CameraController.hpp"

class Sandbox : public Neonix::Layer
{
public:
    Sandbox();
    void OnUpdate(float& deltaTime) override;

private:
    Neonix::Application* m_appInstance;
    Neonix::Renderer m_renderer;
    Neonix::Camera m_camera;
    CameraController m_cameraController;

    Neonix::Mesh m_plane;
    Neonix::Mesh m_sphere;
};
