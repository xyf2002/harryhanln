# x86 assembly language

## Function calling convention

From left to right, pass as many parameters as will fit in registers. The order in which registers are allocated, are: 

- The order is 
* `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9` for integers and pointers.
* `xmm0`, `xmm1`, `xmm2`, `xmm3`, `xmm4`, `xmm5`, `xmm6`, `xmm7` for floating point numbers.

- Additional parameters are pushed onto stack, which are removed by the caller after the call.
- 


