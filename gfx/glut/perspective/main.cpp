#include <GL/glew.h> //must be before freeglut.h
#include <GL/freeglut.h>
#include <stdio.h>
#include <chrono>
#include <string>
// #include <cstring>
#include <fstream>
#include <iostream>
#include <stdlib.h>
// #include "readFile.h"
#include "readFile.cpp"
#include "ogldev_math_3d.h" // This header is from https://github.com/emeiri/ogldev

#define WDT 1000
#define HET 1000
#define FPS 30

// struct Vector3f{
// 	float x;
// 	float y;
// 	float z;
// };

const char* pVSFileName = "vs.glsl";
const char* pFSFileName = "fs.glsl";
GLint gCombineLocation;
// GLint gTranslationLocation;
// GLint gRotationLocation;
// GLint gScaleLocation;

GLuint VBO;
GLuint IBO;

float AS = (float)WDT/HET; // Aspect Ratio

// For Depth Test
// Note When a Vertex is passed to GPU, GPU will clip it if its z value is outside of -1, or 1.
float NearZ = 1.1f;
float FarZ = 1.8f;
float zRange = NearZ - FarZ;
float A = (-FarZ -NearZ)/zRange;
float B = 2.0f*FarZ*NearZ/zRange;

void timeSinceEpoch(long* out){
	auto now = std::chrono::system_clock::now();
	auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
	auto epoch = now_ms.time_since_epoch();
	auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);
	long duration = value.count();
	*out = duration;
}

struct Vertex{
	Vector3f pos;
	Vector3f color;

	Vertex(){};

	Vertex(float x, float y, float z){
		pos=Vector3f(x, y, z);
		float red = (float) rand()/(float)RAND_MAX;
		float green = (float) rand()/(float)RAND_MAX;
		float blue = (float) rand()/(float)RAND_MAX;
		color=Vector3f(red, green, blue);
	}
};

static void CreateVertexBuffer(){
	Vertex Vertices[8];
	Vertices[0] = Vertex(0.5, 0.5, 0.5);
	Vertices[1] = Vertex(-0.5, 0.5, -0.5);
	Vertices[2] = Vertex(-0.5, 0.5, 0.5);
	Vertices[3] = Vertex(0.5, -0.5, -0.5);
	Vertices[4] = Vertex(-0.5, -0.5,-0.5);
	Vertices[5] = Vertex(0.5, 0.5,-0.5);
	Vertices[6] = Vertex(0.5, -0.5, 0.5);
	Vertices[7] = Vertex(-0.5, -0.5, 0.5);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW); // The here it will out put 456: 19*6*4 (4 is the size of float)
}

static void CreateIndexBuffer(){
	unsigned int Indices[] {
		0,1,2,
		1,3,4,
		5,6,3,
		7,3,6,
		2,4,7,
		0,7,6,
		0,5,1,
		1,5,3,
		5,0,6,
		7,4,3,
		2,1,4,
		0,2,7,
	};

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices), Indices, GL_STATIC_DRAW);
}

static void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType){
	GLuint ShaderObj = glCreateShader(ShaderType);

	if (ShaderObj == 0){
		fprintf(stderr, "Error Creating Shader Typ %d\n", ShaderType);
		exit(0);
	}

	const GLchar* p[1];
	p[0] = pShaderText;

	GLint Lengths[1];
	Lengths[0] = strlen(pShaderText);

	glShaderSource(ShaderObj, 1, p, Lengths);

	glCompileShader(ShaderObj);

	GLint success;
	glGetShaderiv(ShaderObj, GL_COMPILE_STATUS, &success);

	if(!success){
		GLchar InfoLog[1024];
		glGetShaderInfoLog(ShaderObj, 1024, NULL, InfoLog);
		fprintf(stderr, "Error Compiling Shader Type %d: '%s'\n", ShaderType, InfoLog);
		exit(1);
	}

	glAttachShader(ShaderProgram, ShaderObj);
	printf("Shader %d Compilation Success!\n", ShaderType);
	return;
}

static void CompileShader(){
	GLuint ShaderProgram = glCreateProgram();
	
	if (ShaderProgram==0){
		fprintf(stderr, "Fail to Create Shader Program!\n");
		exit(1);
	}

	// char vs[8096], fs[8096];
	std::string vs, fs;
	if(!readFile(pVSFileName, vs)) {fprintf(stderr, "Fail to read vertex shader!"); exit(1);}
	printf("Vertex Shader Read Success!\n");
	// std::cout<<vs.c_str()<<std::endl;
	AddShader(ShaderProgram, vs.c_str(), GL_VERTEX_SHADER);

	if(!readFile(pFSFileName, fs)) {fprintf(stderr, "Fail to read vertex shader!"); exit(1);}
	printf("Fragment Shader Read Success!\n");
	AddShader(ShaderProgram, fs.c_str(), GL_FRAGMENT_SHADER);

	GLint Success=0;
	GLchar ErrorLog[1024]{0};

	glLinkProgram(ShaderProgram);

	glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &Success);
	if(!Success){
		glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stderr, "Failed to Link Shader Program! '%s'\n", ErrorLog);
		exit(1);
	}

	// This must be done after linking of the program
	// Uniform must be used in glsl so that its location is established by the compiler
	// This will be a runtime error


	gCombineLocation= glGetUniformLocation(ShaderProgram, "gCombine");
	if (gCombineLocation==-1) {
		fprintf(stderr, "Fail to Obtain Location of the Uniform Variable 'gCombine'\n");
		exit(1);
	}
	glValidateProgram(ShaderProgram);
	glGetProgramiv(ShaderProgram, GL_VALIDATE_STATUS, &Success);
	if(!Success){
		glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stderr, "Invalid Shader Program! '%s'\n", ErrorLog);
		exit(1);
	}

	glUseProgram(ShaderProgram);
	return;
}

int pre, now;
int counter;

static void RenderSceneCB(){
	now = time(NULL);	
	counter++;
	if ((now-pre)>0){
		printf("%s %d\n", "FPS: ", counter);
		pre = now;
		counter=0;
	}
	

	glClear(GL_COLOR_BUFFER_BIT);
	static float Angle = 0.0f; //Radians
	static float Delta = 0.03f;
	static float Scale = 1.0f;

	//Uniform

	// Scale += Delta;
	// if (Scale>=1||Scale<=-1) Delta = -Delta;

	Matrix4f Translation(
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,			
			0.0f, 0.0f, 1.0f, 2.0f,			
			0.0f, 0.0f, 0.0f, 1.0f			
			);

	Angle += 0.004;
	if(Angle>1.5708f||Angle<-1.5708f) Delta *=-1.0f; 

	Matrix4f Rotationz(
			cosf(Angle), 0.0f, -sinf(Angle), 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			sinf(Angle), 0.0f, cosf(Angle), 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);
	Matrix4f Rotationy(
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, cosf(2*Angle), -sinf(2*Angle), 0.0f,
			0.0f, sinf(2*Angle), cosf(2*Angle),0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);
	Matrix4f Rotationx(
			cosf(2*Angle), -sinf(2*Angle), 0.0f, 0.0f,
			sinf(2*Angle), cosf(2*Angle),0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);

	Matrix4f MScale(
			Scale, 0.0f, 0.0f, 0.0f,
			0.0f, Scale, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);

	float FOV = 90.0f;
	float tanHalfFOV = tanf(ToRadian(FOV/2.0f));
	float f = 1/tanHalfFOV; // Note the default range that gpu draws are from -1 to 1

	
	Matrix4f Projection(
			f/AS, 0.0f, 0.0f, 0.0f,
			0.0f, f, 0.0f, 0.0f,			
			0.0f, 0.0f, A, B,			
			0.0f, 0.0f, 1.0f, 0.0f			
			);


	Matrix4f Combine=Projection*Translation*Rotationz*Rotationx*Rotationy;

	glUniformMatrix4fv(gCombineLocation, 1, GL_TRUE, &Combine.m[0][0]);
	//  parameters: location of matrix; number of matrix, row-major(boolean), address to the first element)
	
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 6*sizeof(float),0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1,3, GL_FLOAT, GL_FALSE, 6*sizeof(float),(void*)(3*sizeof(float)));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	// 12 triangles: 36 Vertices
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glutPostRedisplay(); // this line flaged this function to be called by glutloop repeatedly.
	glutSwapBuffers();
}

void idle(int){
	glutPostRedisplay();
	glutTimerFunc(1000/FPS, idle, 1);
}

int main(int argc, char** argv){
	srandom(getpid());
	pre = time(NULL);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);

	int width = WDT, height = HET;

	glutInitWindowSize(width, height);
	int x = 200, y = 100;
	glutInitWindowPosition(x,y);

	int win = glutCreateWindow("My Window!");
	printf("WindowID %d\n", win);

	//Must be placed after initialization of glut 
	GLenum res = glewInit();
	if (res!=GLEW_OK){
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}

	GLclampf Red = 0.1f, Blue = 0.0f, Green = 0.0, Alpha = 0.0f;
	glClearColor(Red, Green, Blue, Alpha); // Set the color to be used when clearing the window

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	CreateVertexBuffer();
	CreateIndexBuffer();
	CompileShader();

	printf("%f\n", AS);
	glutDisplayFunc(RenderSceneCB); 
	// glutTimerFunc(1000/FPS, idle, 1); // For Setted FPS. To enable: comment out glutPostRedisplay in RenderSceneCB.
	glutMainLoop(); //This loop never return.

	return 0;
}
