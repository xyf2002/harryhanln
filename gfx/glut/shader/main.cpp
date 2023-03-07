#include <GL/glew.h> //must be before freeglut.h
#include <GL/freeglut.h>
#include <stdio.h>
#include <chrono>
#include <string>
#include <cstring>
#include <fstream>
#include <string>
#include <iostream>
// #include "readFile.h"
#include "readFile.cpp"

// struct Vector3f{
// 	float x;
// 	float y;
// 	float z;
// };

const char* pVSFileName = "vs.glsl";
const char* pFSFileName = "fs.glsl";

struct Vector3f
{
    union {
        float x;
        float r;
    };

    union {
        float y;
        float g;
    };

    union {
        float z;
        float b;
    };

    Vector3f() {}

    Vector3f(float _x, float _y, float _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
};

GLuint VBO;

void timeSinceEpoch(long* out){
	auto now = std::chrono::system_clock::now();
	auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
	auto epoch = now_ms.time_since_epoch();
	auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);
	long duration = value.count();
	*out = duration;
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
	// char * vs = "#version 330 core\n"
	// "layout (location = 0) in vec3 Position;\n"
	// 	"void main(){\n"
	// 	"gl_Position=vec4(0.5*Position.x, 0.5*Position.y, Position.z, 1.0);\n"
	// 	"}\n"
	// ;
	if(!readFile(pVSFileName, vs)) {fprintf(stderr, "Fail to read vertex shader!"); exit(1);}
	printf("Vertex Shader Read Success!\n");
	std::cout<<vs.c_str()<<std::endl;
	AddShader(ShaderProgram, vs.c_str(), GL_VERTEX_SHADER);

	if(!readFile(pFSFileName, fs)) {fprintf(stderr, "Fail to read vertex shader!"); exit(1);}
	AddShader(ShaderProgram, fs.c_str(), GL_FRAGMENT_SHADER);
	printf("Fragment Shader Read Success!\n");

	GLint Success=0;
	GLchar ErrorLog[1024]{0};

	glLinkProgram(ShaderProgram);

	glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &Success);
	if(!Success){
		glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stderr, "Failed to Link Shader Program! '%s'\n", ErrorLog);
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

long now=100; long pre = 10;

static void RenderSceneCB(){
	static GLclampf r = 0.0f, g= 0, b=0, a=0, c=0.001;
	timeSinceEpoch(&now);

	// glClearColor(r,g,b,a);
	// r+=c; g+=c; b+=c;
	if (r>=1.0f) r =0.0f;
	if (g>=1.0f) g =0.0f;
	if (b>=1.0f) b =0.0f;
	glClear(GL_COLOR_BUFFER_BIT);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 0,0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
	glutPostRedisplay(); // this line flaged this function to be called by glutloop repeatedly.
	glutSwapBuffers();
	// if ((now-pre)>0){
	// 	printf("%ld\n", 1000/(now-pre));
	// }
	// pre = now;
}

static void CreateVertexBuffer(){
	glEnable(GL_CULL_FACE); // Only render the triangles that are anticlockwise (i.e., facing to the screen)
	// by default, counterclockwise means front facing, anticlockwise means back facing.
	glFrontFace(GL_CCW); // CCW: counterclockwise, CW: clockwise. Default CCW.
	glCullFace(GL_BACK);
	Vector3f Vertices[3]; // Struct with x,y,z
	Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
	Vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);
	Vertices[1] = Vector3f(1.0f, -1.0f, 0.0f);
	// float Vertices [9] {-1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, -1.0f, 0.0f};
	
	
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*9, Vertices, GL_STATIC_DRAW); // the third attribute is a pointer, 
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);

	int width = 1920, height = 1080;

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

	GLclampf Red = 0.5f, Blue = 0.0f, Green = 0.0, Alpha = 0.0f;
	glClearColor(Red, Green, Blue, Alpha); // Set the color to be used when clearing the window

	CreateVertexBuffer();
	CompileShader();

	glutDisplayFunc(RenderSceneCB); 
	glutMainLoop(); //This loop never return.

	return 0;
}
