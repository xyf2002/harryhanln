#version 330 core

layout (location = 0) in vec3 Position; // Like c, Name of variable is positioned last preceded by type, attribute

void main()
{
	// gl_Position = vec4(Position, 1.0);
	gl_Position = vec4(0.5*Position.x,0.5*Position.y,Position.z, 1.0);
}

