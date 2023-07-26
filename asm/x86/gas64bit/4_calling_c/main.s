    .global main
    .text
main:
    mov         $message,   %rdi
    call        puts
    ret

    .data
message:
    .ascii  "Hello, World!\n\0"
