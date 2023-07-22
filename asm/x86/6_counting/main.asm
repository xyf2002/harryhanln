%include "function.asm"

SECTION .text
global _start

_start:
  mov cx, 0  ; set ecs to 0

nextNumber:
  inc   ecx
  add   eax, ecx
  add   eax, 48
  push  eax
  mov   eax, esp
  call  characterPrintLN
  pop   eax
  
  cmp   ecx, 10
  jne   nextNumber  ; jump if not equal

  call quit
