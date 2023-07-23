%include "function.asm"

SECTION .data
    address1: db 50, 10, 0
SECTION .text
    global _start
_start:
    mov         rax,        address1
    mov         address1,   51
    call        sprint
    call        quit
    

