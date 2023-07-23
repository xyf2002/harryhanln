# x86 assembly language

## Registers

In x86-84, these integer registers are 64 bit wide.

- `rax`, aka `r0`; `rcx`, aka `r1`; `rdx`, aka `r2`; `rbx`, aka `r3`; `rsp`, aka `r4` (stack pointer); `rbp`, aka `r5`; `rsi`, aka `r6`; `rdi`, aka `r7`; and `r8` to `r15`, are general purpose registers. 

The lowest 32-bit of these registers are:

- `eax`, aka `r0d`; `ecx`, aka `r1d`; `edx`, aka `r2d`; `ebx`, aka `r3d`; `esp`, aka `r4d`; `ebp`, aka `r5d`; `esi`, aka `r6d`; `edi`, aka `r7d`; and `r8d` to `r15d`

The lowest 16-bit of these registers are:

- `ax`, aka `r0w`; `cx`, aka `r1w`; `dx`, aka `r2w`; `bx`, aka `r3w`; `sp`, aka `r4w`; `bp`, aka `r5w`; `si`, aka `r6w`; `di`, aka `r7w`; and `r8w` to `r15w`

And the lowest 8-bit of these registers are:

- `al`, aka `r0b`; `cl`, aka `r1b`; `dl`, aka `r2b`; `bl`, aka `r3b`; `spl`, aka `r4b`; `bpl`, aka `r5b`; `sil`, aka `r6b`; `dil`, aka `r7b`; and `r8b` to `r15b`

Bits 15 through 8 of `r0` to `r3` are `AH`, `CH`, `DH`, and `BH`, respectively.

There are 16 XMM registers, each 128-bit wide. They are named `xmm0` to `xmm15`.

__Importantly__ `rsp`, aka `r4`, is stack pointer.

## Instructions Set For NASM syntax

### Arithmetic

- `add dest, src` adds `src` to `dest` and stores the result in `dest`.
- `sub dest, src` subtracts `src` from `dest` and stores the result in `dest`.
- `inc dest` increments `dest` by 1.
- `dec dest` decrements `dest` by 1.
- `mul src` multiplies `src` with `rax` and stores the result in `rax`.
- `div src` divides `rax` by `src` and stores the quotient in `rax` and remainder in `rdx`.

### Syscall

- `syscall` executes the system call specified by `rax` and stores the result in `rax`.


## Function calling convention

- Store the arguments to function into the following register in order:
  - `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9` for integers and pointers.
  - `xmm0`, `xmm1`, `xmm2`, `xmm3`, `xmm4`, `xmm5`, `xmm6`, `xmm7` for floating point numbers.

- Additional parameters are pushed onto stack, which are removed by the caller after the call.
- The return value is stored in `rax` or `xmm0` for floating point numbers.
- The registers that needs to be preserved are `rbx`, `rbp`, `r12`, `r13`, `r14`, and `r15`. All other can be modified.


