.global maxOfThree

.text
maxOfThree:
    mov         %rdi,        %rax         # result (rax) initally hods x
    cmp         %rsi,        %rax         # compare x and y
    cmovl       %rsi,        %rax         # if y > x, replace result with y
    cmp         %rdx,        %rax         # compare result and z
    cmovl       %rdx,        %rax         # if z > result, replace result with z
    ret

.section .note.GNU-stack,"",@progbits
