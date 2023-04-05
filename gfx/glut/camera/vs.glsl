#version 330 core

layout (location = 0) in vec3 Position; // Like c, Name of variable is positioned last preceded by type, attribute
layout (location = 1) in vec3 inColor; 

uniform mat4 gCombine;

out vec4 Color;


void main()
{
	gl_Position = gCombine* vec4(Position, 1.0); //gl_Position is also an internal veriable.
	Color = vec4(inColor, 0.0f); // gl_VertexID is a system variable.
}

