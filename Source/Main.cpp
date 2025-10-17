#include "Core/Window.hpp"
#include "Core/Input.hpp"
#include "Graphics/Renderer.hpp"
#include "Graphics/Shader.hpp"
#include "Graphics/Shapes.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

int main()
{
    using namespace Neonix;
    using namespace glm;

    Window window("Neonix", 1600, 900);
    
    vec3 cameraPos   = {0.0f, 0.0f, 3.0f};
    vec3 cameraTarget= {0.0f, 0.0f, 0.0f};
    vec3 cameraUp    = {0.0f, 1.0f, 0.0f};
    mat4 view = lookAt(cameraPos, cameraTarget, cameraUp);

    Renderer renderer;

    Shader shader("../Resources/Shaders/SimpleShader.vert", "../Resources/Shaders/SimpleShader.frag");

    Renderable cube = create_cube();

    
    while (!window.ShouldClose())
    {
        window.Clear();
        
        float aspect = window.GetWidth() / (float)window.GetHeight();
        mat4 proj = perspective((float)radians(80.0), aspect, 0.1f, 100.0f);

        shader.SetUniformMat4("u_proj", proj);
        shader.SetUniformMat4("u_view", view);

        double mouseX, mouseY;
        Input::GetMousePosition(mouseX, mouseY);

        if (Input::IsMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
        {
            window.ClearColor({0.78, 0.1, 0.1, 1.0});
        }
        else
        {
            window.ClearColor({0.0, .0, .0, 1});
        }

        renderer.Submit(cube);
        renderer.Render(shader);
        

        window.Update();
    }

    return 0;
}