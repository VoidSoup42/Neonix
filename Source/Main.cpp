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


    
    mat4 view(1.0f);

    Renderer renderer;

    Shader shader("../Resources/Shaders/SimpleShader.vert", "../Resources/Shaders/SimpleShader.frag");

    Renderable quad = create_quad();

    
    while (!window.ShouldClose())
    {
        window.Clear();
        
        mat4 proj = ortho(-8.0f, 8.0f, -4.5f, 4.5f, -10.0f, 10.0f);
        shader.SetUniformMat4("u_proj", proj);
        shader.SetUniformMat4("u_view", view);

        renderer.Submit(quad);
        renderer.Render(shader);
        

        window.Update();
    }

    return 0;
}