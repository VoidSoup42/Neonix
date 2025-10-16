#include "Core/Window.hpp"
#include "Core/Input.hpp"
#include "Graphics/Renderable.hpp"
#include "Graphics/SimpleRenderer.hpp"
#include "Graphics/Shader.hpp"
#include <iostream>

int main()
{
    using namespace Neonix;

    Window window("Neonix", 1600, 900);

    std::vector<Vertex> vertices = {
        { {-0.5f, -0.5f,  0.0f}, {0.0f, 0.0f, 0.0f, 1.0f} }, // Bottom Left
        { { 0.5f, -0.5f,  0.0f}, {1.0f, 0.0f, 0.0f, 1.0f} }, // Bottom Right
        { { 0.5f,  0.5f,  0.0f}, {1.0f, 1.0f, 0.0f, 1.0f} }, // Top Right
        { {-0.5f,  0.5f,  0.0f}, {0.0f, 1.0f, 0.0f, 1.0f} }  // Top Left
    };

    std::vector<unsigned short> indices = {
        0, 1, 2,
        2, 3, 0
    };

    SimpleRenderer renderer;

    Shader shader("../Resources/Shaders/SimpleShader.vert", "../Resources/Shaders/SimpleShader.frag");

    Renderable quad(vertices, indices);

    renderer.Submit(quad);

    while (!window.ShouldClose())
    {
        window.Clear();

        renderer.Render(shader);

        window.Update();
    }

    return 0;
}