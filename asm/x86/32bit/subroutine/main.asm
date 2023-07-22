SECTION .data
msg   db  "Hello, world!", 0Ah

SECTION .text
global  _start

_start:

  mov   eax, msg
  call  strlen

  ; printing to screen
  mov   edx, eax  ; get length of the string
  mov   ecx, msg
  mov   ebx, 1
  mov   eax, 4
  int   80h 

  mov   ebx, 0
  mov   eax, 1
  int   80h

strlen:
  push  ebx      ; push value of ebx to stack
  mov   ebx, eax ; ebx = eax

nextchar:
  cmp   byte [eax], 0 ; compare byte at address eax with 0
  jz    finished     ; if equal, jump to finished
  inc   eax         ; increment eax
  jmp   nextchar   ; jump to nextchar

finished:
  sub   eax, ebx
  pop   ebx      ; restore ebx, incrementing the stack pointer
  ret            ; return to caller
