# Short Guide for using gcc

## gcc flags

### To Control Output

* `-o` : Specify the output file name. For example, `-o hello` to output the executable file `hello`
* `-c` : Compile and assemble, but do not link, output an object file
* `-S` : Compile only; do not assemble or link, output an assembly file
* `-E` : Preprocess only; do not compile, assemble or link, output a preprocessed file

### Linking 

* `-l` : Specify the library to link. For example, `-ltEngine` to link the library `libtEngine.so`
* `-L` : Specify the directory to search for libraries at link time. For example, `-L/usr/local/lib` to search for libraries in `/usr/local/lib`
* `-Wl,-rpath` : Specify the directory to search for libraries at run time. For example, `-Wl,-rpath=/usr/local/lib` to search for libraries in `/usr/local/lib` at run time

### Static Linking

* `-I` : Specify the directory to search for header files. For example, `-I/usr/local/include` to search for header files in `/usr/local/include`

### Flags required for Creating Shared Libraries 

* `-shared` : Create a shared library
* `-fPIC` : Create position-independent code (PIC) for use in a shared library


