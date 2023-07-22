SECTION .data
msg     db      "Hi! Hello, World", 0Ah ; 0Ah is hex for 10, is line break

SECTION .text
global  _start

_start:
    mov ebx, msg ; mov the address of the message string into ebx
    mov eax, ebx ; eax = ebx

nextchar:
    cmp byte [eax], 0 ; compare the byte pointed to by EAX against 0. end of line is 0
    jz finished ; jump of zero flag was setted to finished
    inc eax ; eax++
    jmp nextchar ; iterate
finished:
    sub eax, ebx ; pointer arithmetic

    mov edx, eax ; edx = eax
    mov ecx, msg
    mov ebx, 1
    mov eax, 4
    int 80h

    mov ebx, 0
    mov eax, 1
    int 80h
