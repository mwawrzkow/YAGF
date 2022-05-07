#version 330 core
out vec4 FragColor;

in vec4 ourColor;
in vec2 TexCoord;

// texture sampler
uniform sampler2D texture1;

void main()
{             
    vec4 texColor = texture(texture1, TexCoord) * ourColor;
    if(texColor.a < 0.1)
        discard;
    FragColor = texColor;
}