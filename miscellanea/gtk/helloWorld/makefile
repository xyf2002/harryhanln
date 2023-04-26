FLAGS=$(shell pkg-config gtkmm-3.0 --cflags --libs)
# FLAGS=`pkg-config gtkmm-3.0 --cflags --libs` -std=c++11
all: helloWorld.out

helloWorld.out: main.o helloWorld.o 
	g++ -o helloWorld.out main.o helloWorld.o $(FLAGS)

helloWorld.o: helloWorld.cc helloWorld.hh
	g++ -o helloWorld.o -c helloWorld.cc $(FLAGS)

main.o: main.cc helloWorld.hh
	g++ -o main.o -c main.cc $(FLAGS)

clean:
	rm -f *.o *.out
