#version 460 core

out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D u_albedo;

void main()
{
    FragColor = texture(u_albedo, TexCoord);
}
