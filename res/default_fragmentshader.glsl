/**
 * Basic fragment shader.
 * Every pixel will have the color sent to vertexColor.
 */
#version 330 core

// Will receive the color to be used for painting from the
// default_vertexshader.
in vec4 vertexColor;

// The color that will be used for the pixel
out vec4 fragColor;

void main ()
{
    fragColor = vertexColor;
}

