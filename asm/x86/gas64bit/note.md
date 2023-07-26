# GAS 64-bit instruction set

## Registers and Basic Syntaxes

All registers must be prefixed with a `%` sign; all immediate values must be prefixed with a `$` sign.

### Registers

- `rax` - accumulator
- `rbx` - base
- `rcx` - counter
- `rdx` - data
- `rsi` - source index
- `rdi` - destination index
- `rbp` - base pointer
- `rsp` - stack pointer (it stores the address of te top of the stack)
- `r8` to `r15` - general purpose registers

## Instruction Set 

### Arithmetic

- `mov $1, %rax` - move 1 into rax
- `mov %rax, %rbx` - move rax into rbx
- `add $1, %rax` - add 1 to rax
- `sub $1, %rax` - subtract 1 from rax

### Control Flow

- `jmp label` - unconditionally jump to label
- `cmp %rax, %rbx` - compare rax and rbx
- `je label` - jump to label if equal
- `jne label` - jump to label if not equal
- `jg label` - jump to label if `rbx > rax`
- `jge label` - jump to label if greater or equal `rbx >= rax`
- `jl label` - jump to label if less `rbx < rax`
- `jle label` - jump to label if `rbx <= rax`

### Calling Convention

- Store the arguments to function into the following register in order:
  - `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9` for integers and pointers.
  - `xmm0`, `xmm1`, `xmm2`, `xmm3`, `xmm4`, `xmm5`, `xmm6`, `xmm7` for floating point numbers.

- Additional parameters are pushed onto stack, which are removed by the caller after the call.
- The return value is stored in `rax` or `xmm0` for floating point numbers.
- The registers that needs to be preserved are `rbx`, `rbp`, `r12`, `r13`, `r14`, and `r15`. All other can be modified.

### Stack

- `push %rax` - push rax onto the Stack
- `pop %rax` - pop rax off the Stack
- `call label` - push the address of the next instruction onto the Stack and jump to label
- `ret` - pop the address off the Stack and jump to it

### Memory access: pointer reference and dereference

- `mov (%rax), %rbx` - move the value at the address in rax into rbx
- `mov %rax, (%rbx)` - move the value in rax into the address in rbx
- `movb $1, (%rax)` - move one byte holding the value 1 into the address in rax

