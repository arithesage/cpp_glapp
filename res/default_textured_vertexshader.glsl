/**
 * Basic vertex shader.
 *
 * Renders a vertex in the specified position.
 */
#version 330 core

// The coordinates where the vertex will be rendered
layout (location = 0) in vec3 vPos;

// The color that will be sent to the fragment shader
// for paint the vertex's associated pixels.
//
// In this case, the corresponding texture pixel color.
layout (location = 1) in vec4 vColor;

// The associated UV coordinate with this vertex
layout (location = 2) in vec2 vUV;

// The color will be sent to this variable of the fragment shader
out vec4 vertexColor;

// And the UV coordinate will be sent to this one
out vec2 uv;

void main ()
{
    gl_Position = vec4 (vPos.x, vPos.y, vPos.z, 1.0);    
    vertexColor = vColor;
    uv = vUV;
}

