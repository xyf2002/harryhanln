# How to Used a Shared Library in C/C++

## Creating a Shared Library

Say there is a filed nanmed `mmath.c`. Use the gcc command

`gcc -o libmmath.so -fPIC -shared mmath.c`

Place this library (or its symbolic link) in an appropriate directory.

It can be placed in the system directory `/usr/lib`. Run `ldconfig -n /usr/lib` before using it.

## Use the Shared Library

During compilation, the compiler will search for all function and variables declared, either in the same file, or from the linked symbolic libraries. 
To use the function defined in the symbolic library, the same function need to be declared in the source code, usually by including a header file.

Say we have a file `example.c` that uses the shared library `libmmath.so`. If `libmmath.so` is placed in the system directory, `example.c` can be compiled and linked simply by `gcc example.c -lmmath`. Although the name of the shared object file is `libmmath.so`, the invoked flag is `-lmmath`, without `lib` or `/.so`.

If the shared `libmmath.so` is not in the system directory but in the directory, but instead is in `$HOME/lib`, it needs to be compiled and linked with the command `gcc example.c -L$HOME/lib -lmmath -Wl,-rpath=$HOME/lib`.

`-L$HOME/lib` specifies where to find the library at compile/link time. `-Wl,-rpath` specifies where to find it at run time.

Or, alternatively, we can specify the `LD_LIBRARY_PATH` environment variable to include `$HOME/lib` and then compile and link with `gcc example.c -lmmath`.
