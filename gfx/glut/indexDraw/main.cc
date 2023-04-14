/*
        Copyright 2010 Etay Meiri
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <GL/glew.h> //must be before freeglut.h
#include <GL/freeglut.h>
#include <stdio.h>
#include <chrono>
#include <string>
#include <cstring>
#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
// #include "readFile.h"
#include "readFile.cpp"
#include "ogldev_math_3d.h" // This header is from https://github.com/emeiri/ogldev

#define WDT 1000
#define HET 1000

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

	Vertex(float x, float y){
		pos=Vector3f(x, y, 0.0f);
		float red = (float) rand()/(float)RAND_MAX;
		float green = (float) rand()/(float)RAND_MAX;
		float blue = (float) rand()/(float)RAND_MAX;
		color=Vector3f(red, green, blue);
	}
};

static void CreateVertexBuffer(){
	Vertex Vertices[33];

	// Center 
	Vertices[0] = Vertex(0.0f, 0.0f);
	// Top row 
	// for (int i = 0; i < 9; i++){
	// 	Vertices[i+1]=Vertex(-1.0f+0.25*(float)i, 1.0f);
	// }
	// // Bottom Row
	// for (int i = 0; i < 9; i++){
	// 	Vertices[i+10]=Vertex(-1.0f+0.25*(float)i, -1.0f);
	// }
	// for (int i = 0; i < 7; i++){
	// 	Vertices[i+19]=Vertex(-1.0f, -0.75f+0.25*(float)i);
	// }
	// for (int i = 0; i < 7; i++){
	// 	Vertices[i+26]=Vertex(1.0f, -0.75f+0.25*(float)i);
	// }

	for (int i = 0; i < 9; i++){
		Vertices[i+1]=Vertex(-2.0f+0.5*(float)i, 2.0f);
	}
	// Bottom Row
	for (int i = 0; i < 9; i++){
		Vertices[i+10]=Vertex(-2.0f+0.5*(float)i, -2.0f);
	}
	for (int i = 0; i < 7; i++){
		Vertices[i+19]=Vertex(-2.0f, -1.5+0.5*(float)i);
	}
	for (int i = 0; i < 7; i++){
		Vertices[i+26]=Vertex(2.0f, -1.5f+0.5*(float)i);
	}
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW); // The here it will out put 456: 19*6*4 (4 is the size of float)
}

static void CreateIndexBuffer(){
	unsigned int Indices[] {
		0,2,1,
		0,3,2,
		0,4,3,
		0,5,4,
		0,6,5,
		0,7,6,
		0,8,7,
		0,9,8,

		0,10,11,
		0,11,12,
		0,12,13,
		0,13,14,
		0,14,15,
		0,15,16,
		0,16,17,
		0,17,18,

		0,1,25,
		0,25,24,
		0,24,23,
		0,23,22,
		0,22,21,
		0,21,20,
		0,20,19,
		0,19,10,

		0,32,9,
		0,31,32,
		0,30,31,
		0,29,30,
		0,28,29,
		0,27,28,
		0,26,27,
		0,18,26
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

long now=100; long pre = 10;

static void RenderSceneCB(){
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
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
			0.0f, 0.0f, 1.0f, 0.0f,			
			0.0f, 0.0f, 0.0f, 1.0f			
			);

	Angle += 0.01;
	std::cout<<Angle<<std::endl;
	if(Angle>1.5708f||Angle<-1.5708f) Delta *=-1.0f; 
	Matrix4f Rotation(
			cosf(Angle), -sinf(Angle), 0.0f, 0.0f,
			sinf(Angle), cosf(Angle), 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 1.0f,
			0.0f, 0.0f, 0.0f, 1.0f);
	Matrix4f MScale(
			Scale, 0.0f, 0.0f, 0.0f,
			0.0f, Scale, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);

	Matrix4f Combine=Translation*Rotation*MScale;


	glUniformMatrix4fv(gCombineLocation, 1, GL_TRUE, &Combine.m[0][0]);
	//  parameters: location of matrix; number of matrix, row-major(boolean), address to the first element)
	
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 6*sizeof(float),0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1,3, GL_FLOAT, GL_FALSE, 6*sizeof(float),(void*)(3*sizeof(float)));

	glDrawElements(GL_TRIANGLES, 96, GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glutPostRedisplay(); // this line flaged this function to be called by glutloop repeatedly.
	glutSwapBuffers();
}

int main(int argc, char** argv){
	srandom(getpid());
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

	CreateVertexBuffer();
	CreateIndexBuffer();
	CompileShader();

	glutDisplayFunc(RenderSceneCB); 
	glutMainLoop(); //This loop never return.

	return 0;
}
