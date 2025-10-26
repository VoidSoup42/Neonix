#version 460 core

out vec4 FragColor;
in vec2 TexCoord;

uniform float u_uvScaleX;
uniform float u_uvScaleY;

uniform bool u_useAlbedo;
uniform vec4 u_diffuseColor;
uniform sampler2D u_albedo;

void main()
{
    vec2 scaledUV = vec2(TexCoord.x * u_uvScaleX, TexCoord.y * u_uvScaleY);
    vec4 albedoColor = u_useAlbedo ? texture(u_albedo, scaledUV) : u_diffuseColor;
    FragColor = albedoColor;
}
