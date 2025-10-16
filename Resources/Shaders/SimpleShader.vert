#version 460 core

layout (location = 0) in vec3 aPos;    // Vertex position
layout (location = 1) in vec4 aColor;  // Vertex color

out vec4 vColor; // Pass color to fragment shader

void main()
{
    gl_Position = vec4(aPos, 1.0); // Transform position
    vColor = aColor;               // Pass color through
}
