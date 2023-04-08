#!/bin/bash

CC=g++
CPPFLAGS=`pkg-config --cflags glew ImageMagick freetype2 glfw3`
CPPFLAGS="$CPPFLAGS -I../Include -I../Common/FreetypeGL  -I/home/hhyh/psu/lib/gfx/include"
LDFLAGS=`pkg-config --libs glew ImageMagick freetype2 glfw3`
LDFLAGS="$LDFLAGS -lglut ../Lib/libAntTweakBar.a -lX11"

$CC main.cpp ../Common/ogldev_util.cpp  ../Common/math_3d.cpp world_transform.cpp camera.cpp $CPPFLAGS $LDFLAGS -o tutorial14
