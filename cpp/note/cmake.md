# Cmake

## Quick Usage for Cmake
1. Enter source directory and create `CMakeLists.txt` file.
The minimum required lines in `CMakeLists.txt` is 
```
cmake_minimum_required(VERSION 3.20)
project(projectname)
add_executable(projectname main.cpp)
```
2. Create a build directory
3. `cmake -S <path to source> -B <Path to build>`. This command will build the source file in the directory `<Path to build>`.
4. Enter `build` directory; `make` command will build and create executable.

### How Cmake works

Cmake is dependent on the dependency manager make. When invoking the command `make` in the source directory, make will build and generate the executable based on the file named `Makefile`. 

When invoking the command `cmake -S <path to source> -B <Path to build>`, cmake will generate the `Makefile` in the build directory based on the file `CMakeLists.txt` in the soucre directory.

### Install into `$PATH`

After using cmake the struture of the source file may be rather complicated; running the executable file everytime by typing the whole path to it may not be convenient. 

Installing the executable solves the problem. 

First, add the line into `CMakeLists.txt`: `install(TARGETS <targetname> DESTINATION <destinationPath>)`.
Then Build the source, then run `make install`. 

Refresh the terminal by `source ~/.bashrc`

This command will install the executable in the destination diretory. If the destination directory is in the `$PATH`, it can be directed invoked in the command line.

### Adding Library

#### What is cpp Library? How to use it? 

A cpp library, in simple terms, is some code that can be linked to other cpp code. Recall the process of producing a executable for cpp: 1) All cpp codes are compiled by compiler; 2) linked by linker; 3) produce executable. A library can be precompiled, or just the source cpp code. 

A header file (extension ends in `.h`) is a special. It is not directly compiled or linked; intead, the compiler replaces the code `#include "...h"` with the actual contents of the header file. 

In cpp there are several kinds of library: static, dynamic, etc.
Compiled binaries of static library has `.a`(archive) extention on Linux, `.lib` extention on Windows. Static library functions as if it is part of the source code.
Compiled dynamic libraries has `.so` (shared object) extention on Linux, `.dll` (dynamic link library) extention on Windows. 

#### Write and Build the Library

To write a library is just like to write any cpp file (except, perhaps, there is no `main` file nor an executable directly produced by the library). To write a library and build with cmake:
1. Write the cpp files (extension end in `.cpp`)
2. In `CMakeLists.txt`, tell cmake it is a library and there will be be executable produced from it by adding the line:
`add_library(<projectname> <sourcecode>)`
3. Create and enter	`build` folder, run `cmake ../` and `make` to compile the libraries and build the binaries.  

For tutorial, see youtube video:
https://www.youtube.com/watch?v=DDHCEE_PHOU

Also see example in `/study/coding/ln/cpp/cmake/ctt/src/libDemo/cpp`

#### Link and Use the Library

To link the library add the following two lines in the `CMakeLists.txt` file:
```
target_link_directories(<project_name> PRIVATE $<path to library binaries>)
target_link_libraries(<project_name> <name_of_library_binary_without_.a_or_lib>)
```

See example in `/study/coding/ln/cpp/cmake/ctt/src/test/cpp`





