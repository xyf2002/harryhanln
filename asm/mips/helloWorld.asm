  .data
str: .asciiz "\nHello, World\n"

  .text
main:
  li $v0, 4
  la $a0, str 
  syscall

  li $v0, 10  ## terminate program
  syscall
