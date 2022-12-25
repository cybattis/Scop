#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

uniform float mixValue;

vec4 revert = vec4(-1.0f, 1.0f, 1.0f, 1.0f);
vec2 revertedTexCoord = TexCoord * revert.xy + revert.zw;

void main()
{
//    FragColor = texture(ourTexture, TexCoord) * vec4(ourColor, 1.0);
    FragColor = mix(texture(texture1, TexCoord), texture(texture2, revertedTexCoord), mixValue);
}
