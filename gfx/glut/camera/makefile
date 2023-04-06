CC=g++
FLAGS=-I$(HOME)/psu/lib/gfx/include -I$(HOME)/psu/lib/gfx/glut/Include -pedantic -Wall -Wextra -std=c++11 -lGLU -lGL -lGLEW -lglut -lX11
OUT=a.out

all: main.o camera.o world_transform.o
	$(CC) main.o camera.o world_transform.o -o $(OUT) $(FLAGS)

main.o: main.cpp camera.h world_transform.h
	$(CC) -c main.cpp $(FLAGS)

camera.o: camera.cpp camera.h 
	$(CC) -c camera.cpp $(FLAGS)

world_transform.o: world_transform.cpp world_transform.h
	$(CC) -c world_transform.cpp $(FLAGS)

clean:
	rm -f $(OUT) main.o camera.o world_transform.o
