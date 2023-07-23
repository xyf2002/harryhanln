; find the length of the string
slen:
    push        rbx             ; use rbx as a temporary register
    mov         rbx,        rax

nextchar:
    cmp         byte[eax],  0
    jz          finished
    inc         rax
    jmp         nextchar

finished:
    ; return value is in rax
    sub         rax,        rbx
    pop         rbx
    ret

; string printing function
sprint:
    push        rax
    call        slen
    mov         rdx,        rax ; rdx = string length

    pop         rax

    mov         rdi,        1   ; 1, file handler for stdin
    mov         rsi,        rax ; address to message
    mov         rax,        1
    syscall
    ret
    
quit:
    mov         rax,        0x3c
    mov         rdi,        0
    syscall
    ret
