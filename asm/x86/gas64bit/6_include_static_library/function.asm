# first input; rdi: address to string
# second input, rsi, length of hte string
print:
    #save registers
    push        %rax
    push        %rdi
    push        %rsi
    push        %rdx
    # second input: %rsi:
    mov         %rsi,     %rdx        # the length of the string
    # first input: rdi
    mov         %rdi,     %rsi        # pointer to message
    # write to stdout
    mov         $1,       %rax        # syscall write
    mov         $1,       %rdi        # 1 is stdout

    syscall

    pop         %rdx
    pop         %rsi
    pop         %rdi
    pop         %rax
    ret         return

println:
    push        %rax
    push        %rdi
    push        %rsi
    push        %rdx

    pop         %rdx
    pop         %rsi
    pop         %rdi
    pop         %rax
    ret
    

exit:
    mov        $60,      %rax       # 60: exit code for
    syscall
