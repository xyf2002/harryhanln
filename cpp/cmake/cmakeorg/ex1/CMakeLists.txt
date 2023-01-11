cmake_minimum_required(VERSION 3.0)
project(HelloWorld)
add_executable(HelloWorld main.cpp)

project(HelloWorld, VERSION 1.0)
#:configure_file(HelloWorldConfig.h.in HelloWorldConfig.h)
target_include_directories(HelloWorld PUBLIC
						   "${PROJECT_BINARY_DIR}"
						   )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
