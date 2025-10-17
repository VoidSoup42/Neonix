#version 460 core

in vec4 vColor; // Received from vertex shader
out vec4 FragColor;

void main()
{
    FragColor = vec4(0.0, 1.0, 0.0, 1.0);
}
