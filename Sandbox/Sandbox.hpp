#pragma once

#include "Graphics/Renderable.hpp"
#include "Graphics/Renderer.hpp"
#include "Graphics/Shapes.hpp"
#include "Graphics/Layer.hpp"
#include "Core/Application.hpp"

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
    glm::mat4 m_view;
};
