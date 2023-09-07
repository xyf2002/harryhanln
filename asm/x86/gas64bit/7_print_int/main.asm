.include "function.asm"

    .global _start
    
    .text
_start:
    mov         $message,   %rdi
    mov         $15,        %rsi
    call        print
    
    call exit
    

    .data
message:
    .ascii  "Hello, World!\n\0"

