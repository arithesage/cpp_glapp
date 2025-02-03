#version 330 core

//in vec4 vertexColor;
in vec2 uv;

out vec4 fragColor;

uniform sampler2D tex;


void main ()
{
    fragColor = texture (tex, uv) * vec4 (1.0, 1.0, 1.0, 1.0);
}

