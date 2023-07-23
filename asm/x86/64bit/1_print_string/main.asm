SECTION .data
msg     db      "Hi! Hello, World!", 0xA, 0x0

SECTION .text
global _start

_start:
    mov rbx, msg ; rbx = msg, note msg is a pointer to the string
    mov rax, rbx ; rax = rbx

nextchar:
    cmp byte [rax], 0
    jz finished
    inc rax
    jmp nextchar

finished:
    sub rax, rbx

    mov rdx, rax
    mov rdi, 1
    mov rax, 0x1
    mov rsi, msg
    syscall

    mov     rax,    0x3c
    mov     rdi,    0
    syscall
