#version 460 core

in vec4 vColor; // Received from vertex shader
out vec4 FragColor;

void main()
{
    FragColor = vColor; // Set output color
}
