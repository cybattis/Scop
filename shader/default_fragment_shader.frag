#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_diffuse2;

uniform float mixValue;

void main()
{
//    FragColor = ourColor;
    FragColor = mix(texture(texture_diffuse1, TexCoord), texture(texture_diffuse2, TexCoord), mixValue);
}
