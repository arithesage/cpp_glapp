/**
 * Basic vertex shader.
 *
 * Renders a vertex in the specified position.
 */
#version 330 core

// The coordinates where the vertex will be rendered
layout (location = 0) in vec3 vPos;

// The color that will be sent to the fragment shader
// for paint the vertex's associated pixels
layout (location = 1) in vec4 vColor;

// The color will be sent to this variable of the fragment shader
out vec4 vertexColor;

void main ()
{
    gl_Position = vec4 (vPos.x, vPos.y, vPos.z, 1.0);
    vertexColor = vColor;
}

