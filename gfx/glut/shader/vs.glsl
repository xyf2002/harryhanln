#version 330 core

layout (location = 0) in vec3 Position; // Like c, Name of variable is positioned last preceded by type, attribute

uniform float gScale; //Initialize to 0
// uniform is the third storage qualifier, it is used to pass data from the CPU to the GPU
// Other attributes include in, out, 

void main()
{
	// gl_Position = vec4(Position, 1.0);
	gl_Position = vec4(gScale*Position.x, gScale*Position.y, Position.z, 1.0);
}

