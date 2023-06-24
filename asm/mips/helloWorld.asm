  .data
str: .asciiz "\nHello, World\n"

  .text
main:
  ## Translate the following c code to MIPS
  ## void main(){
  ##  int i = 516;
  ##  int j = i*(i+1)/2
  ##  i = i + j;
  ##  }
  addi $t0, $0, 516 
  add $t1, $t0, 1
  mul $t1, $t0, $t1
  div $t1, $t1, 2
  add $t0, $t0, $t1

  ## syscall to print int to screen
  ## Load value of $t0 into $a0
  add $a0, $0, $t0
  li $v0, 1
  syscall

  li $v0, 4
  la $a0, str 
  syscall

  li $v0, 10  ## terminate program
  syscall
