# OpenGL with freeglut

## Dependencies

On Debian, freeglut is available in apt: `apt install freeglut3-dev`
Other required dependencies include glew. 

## Use freeglut with cpp

Header: `#include <GL/freeglut.h>`

To build, first find out what flag is required for glew: `pkg --config --libs glew`

The cpp files can be built and linked with `gcc`, passing into the flags requried for glew and the flag for `-lglut`.

On ubuntu, the compile/link command with gcc is `g++ main.cpp -lGLU -lGL -lGLEW -lglut -lX11`

## Create a Window

