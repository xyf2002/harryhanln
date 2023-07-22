%include "function.asm"

SECTION .text
global _start

_start:
  mov cx, 0  ; set ecs to 0

nextNumber:
  inc   rcx
  add   rax, rcx
  add   rax, 48
  push  rax
  mov   rax, rsp
  call  characterPrintLN
  pop   rax
  
  cmp   rcx, 10
  jne   nextNumber  ; jump if not equal

  call quit
