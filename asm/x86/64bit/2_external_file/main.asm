%include    "function.asm"

SECTION .data
    msg1        db          "Hello, brave new world!", 0xA, 0

SECTION .text
    global  _start

_start:
    mov         eax,        msg1
    call        sprint
    call        quit
