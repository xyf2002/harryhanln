#version 330 core

layout (location = 0) in vec3 Position; // Like c, Name of variable is positioned last preceded by type, attribute

// uniform float gScale; //Initialize to 0
// uniform is the third storage qualifier, it is used to pass data from the CPU to the GPU
// Other attributes include in, out, 

// uniform mat4 gTranslation;
// uniform mat4 gRotation;
// uniform mat4 gScale;
uniform mat4 gCombine;
// mat4: internal data type, 4x4 matrix
out vec4 Color;
const vec4 colors [3]=vec4[3](vec4(1,0,0,1), vec4(0,1,0,1), vec4(0,0,1,1));

void main()
{
	// gl_Position = vec4(Position, 1.0);
	// gl_Position = gTranslation*gRotation *gScale* vec4(Position, 1.0);
	gl_Position = gCombine* vec4(Position, 1.0); //gl_Position is also an internal veriable.
	Color = colors[gl_VertexID]; // gl_VertexID is a system variable.
}

