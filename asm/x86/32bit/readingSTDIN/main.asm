%include "function.asm"

SECTION .data
msg1  db "Please enter your name ", 0Ah, 0h
msg2  db "Hello, ", 0h
msg3  db " !", 0h

; this section is to store unintialized data
; block started by symbol .bss
SECTION .bss
sinput: resb 255 ; reserver a 255 byte space in memory for user input
variableName2: resw 1 ; reserve a 2 byte space in memory for a word
variableName3: resd 1 ; reserve a 4 byte space in memory for a double word
variableName4: resq 1 ; reserve a 8 byte space in memory for a quad word
variableName5: rest 1 ; reserve a 10 byte space in memory for a ten byte

SECTION .text
global _start

; arguments are loaded into stack in reverse order. 
; the first argumet in stack is the number of arguments
; the second is the name of the program

_start:
  ; ptint message
  mov eax, msg1
  call sprint

  mov edx, 255 ; number of bytes to read
  mov ecx, sinput ; reserved space, buffer
  mov ebx, 0 ; 0 is stdin
  mov eax, 3 ; syscall, invoke sys_read
  int 80h 

  mov eax, msg2
  call sprint

  mov eax, sinput
  call sprint

  mov eax, msg3
  call sprint

  call quit
