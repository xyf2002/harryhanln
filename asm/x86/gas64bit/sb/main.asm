
    .global _start  # make start visible to linker
    
    .text

_start:

    mov        $1,       %rax
    mov        $1,       %rdi
    mov        $message, %rsi
    mov        $14,      %rdx 
    syscall
    jmp foo
foo:
    
    mov        $60,      %rax
    ; xor        %rdi,     %rdi
    mov        $1,       %rdi
    # echo $? produces 0 (the return value of the program)
    syscall
    
message:

    .ascii  "Hello, World!\n"

