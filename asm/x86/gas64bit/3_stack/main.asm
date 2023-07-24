    .global _start
    
    .text
_start:
    # write to stdout
    mov        $1,       %rax        # syscall write
    mov        $1,       %rdi        # 1 is stdout
    push       $10
    sub        $1,       %rsp
    movb       $10,      (%rsp)     # move one byte containing 10 to the memory address rsp
    mov        %rsp,     %rsi        # pointer to message

    mov        $2,      %rdx        # the length of the string
    syscall

    mov        $60,      %rax

    push       $2
    push       $8
    pop        %rdi
    pop        %rdi
    syscall
    

    .data
message:
    .ascii  "Hello, World!\n\0"

