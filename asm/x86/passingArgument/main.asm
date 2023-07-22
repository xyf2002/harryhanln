%include "function.asm"

SECTION .text
global _start

; arguments are loaded into stack in reverse order. 
; the first argumet in stack is the number of arguments
; the second is the name of the program

_start:
  pop ecx

nextArg:
  cmp ecx, 0h
  jz noMoreArgs
  pop eax
  call sprintLF
  dec ecx
  jmp nextArg

noMoreArgs:
  call quit
