#version 460 core

out vec4 FragColor;
in vec2 TexCoord;

uniform float u_uvScaleX;
uniform float u_uvScaleY;

uniform sampler2D u_albedo;

void main()
{
    FragColor = texture(u_albedo, vec2(TexCoord.x * u_uvScaleX, TexCoord.y * u_uvScaleY));
}
