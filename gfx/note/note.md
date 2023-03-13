# OpenGL 

## Creating a Screen

### Drawing to Screen

`glClear(GLbifield mask)` Clear the mask to preset values.

The three masks are `GL_COLOR_BUFFER_BIT, GL_DEPTH_BUFFER_BIT, and GL_STENCIL_BUFFER_BIT`

`GL_COLOR_BUFFER_BIT` is the buffer currently enabled for drawing color.

Use `glClearColor(r, g, b, a)` to set the default color to be rendered when `glClear()` is called.


## Commonly used APIs

### Front facing and Back facing

`glEnable(GL_CULL_FACE)` will enable opengl to cull (i.e., stop drawing) the face that is not facing the screen.

By default only render the triangles that are facing the screen, i.e. with counterclockwise vertices.

Use `glFrontFace(CW)` to make clockwise facing to the screen. (CCW for counterclockwise)

Use `glCullFace(GLenum mode)` to specified which facing are culled. Options are `GL_FRONT`, `GL_BACK`, and `GL_FRONT_AND_BACK`.


### GL Data Types

For more details, see [OpenGL Data Types](https://www.khronos.org/opengl/wiki/OpenGL_Type).

- `GLClampf` : a floating-point value clamped to the range [0,1].

### Enumerations

Vertex shader has the value 35633, and fragment shader has the value 35632.


## Programmable pipeline

Shader in OpenGL is written in glsl: a very expressable 

- Compose of fixed function unit and Programmable unit
- Vertex shadeer -> Tesselation Unit -> Geometry Shader -> Rasterizer (fixed) -> fragment shader -> Final frame


## glsl 

glsl is a shading language for OpenGL. It is a C-like language. glsl is case sensitive.

### Uniforms

Input data to the shader which stays uniform during the execution of any draw call.


## Vertex Shader 

GL will normalize vertices it receives. Thus, if the screen is not a square, the vertices will be stretched.

## fragment shader

### Interpolation

As vertex shader only pass in finite vertices, yet we would want color defined on all fragments of the picture, glsl will interpolate the color for all fragments between vertices. 

If triangle-draw is activated, gl will use Barycentric Coordinates method to interpolate the R, G, B colors independently.
