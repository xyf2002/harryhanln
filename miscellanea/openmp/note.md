# OpenMP: parallel programming

## Quick start

Openmp shall be supported in linux by gcc by default. 

Compile with `-fopenmp`. Use `#include <omp.h>` in the beginning.

The number of thread used will be determined by `OMP_NUM_THREADS` shell variables.

```c
//main.c

#include<stdio.h>
#include<omp>

int main()
{
#pragma omp parallel
{
    printf("Yes!\n");
}
    return 0;
}
```

Run it with `OMP_NUM_THREADS=4 ./a.out`

## Data Sharing Attribute 

private shared firstprivate.

```c
//main.c

#include<stdio.h>
#include<omp>

int main()
{

int a = 1; //how will this a be handled by different thread?
#pragma omp parallel
{
    printf("Yes!\n");
}
    return 0;
}
```

Say there is a variable, a, initiailised before parallelism. Will this value be passed by reference? 

By default, the value is passed as shared. To disable this default use `default(none)` directive. You need to further specify the behaviour for each variable explicitly.

- `private(a)`: each thread get their own un-initialised copy of variable a.
- `firstprivate(a)`: each thread get their own copy of variable a, and the value is initialised to the value of the variable a before parallelism.
- `shared(a)`: each thread share the same variable a.

```c
//main.c

#include<stdio.h>
#include<omp>

int main()
{
int a = 1;
#pragma omp parallel default(none) private(a)
{
    printf("Yes!\n");
}
    return 0;
}
```

## Single and Master directive

- `single`: only one thread will execute the block of code. All other threads will skip this block of code and wait for the single thread to finish.
- `master`: only the master thread will execute the block of code.

```c
//main.c 

#include<stdio.h>
#include<omp>

int main()
{
int a = 1;

#pragma omp parallel default(none) private(a)
{
    printf("Yes!\n");
    #pragma omp single
    {
        printf("Only one thread will execute this block of code.\n");
    }
    #pragma omp master
    {
        printf("Only the master thread will execute this block of code.\n");
    }
}
    return 0;
}
```

## Barrier and critical directive

- `barrier`: all threads will wait for each other at this point.
- `critical`: only one thread will execute the block of code. All other threads will skip this block of code and wait for the single thread to finish.
```c 
//main.c 

#include<stdio.h> 
#include<omp.h> 

int main() 
{

int a = 1;

#pragma omp parallel default(none) private(a)
{
    printf("Yes!\n");
    #pragma omp barrier
    {
        printf("All threads will wait for each other at this point.\n");
    }
    #pragma omp critical
    {
        printf("Only one thread will execute this block of code.\n");
    }
}
    return 0;
}
```

## omp for 

`#pragma omp parallel for` is used to parallelise for loop. 

```c
