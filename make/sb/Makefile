objects := $(patsubst %.c,%.o,$(wildcard *.c))

all : $(objects)
	cc -o print $(objects)

clean :
	rm -f print $(objects)
