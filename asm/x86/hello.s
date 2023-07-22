; note: syscall for 64 bits and 32 bits are different
section .data
  msg db "Hello, World!"

section .text
  global _start
_start:
  mov     rax, 1         ; write
  mov     rdi, 1        ; file handler 1 is stdout
  mov     rsi, msg      ; address of string to output 
  mov     rdx, 13       ; number of bytes
  syscall              ; syscall for write
  mov     rax, 60     ; exit
  mov     rdi, 0      ; exit code8 0
  syscall            ; syscall for exit
