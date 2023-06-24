  .data
helloWorld: .asciiz "Hello, World!\n"
ANOTHERLOOP: .asciiz "ANOTHER LOOP\n"
str1: .asciiz "\n\nTranslate if, else:\n"
newline: .asciiz "\n"
isLeap: .asciiz " is Leap Year!\n"

.text
main:
  addi $t0, $0, 11  
  bne $t0, $zero, JP  ## if $t0 == 0, jump to JP
  # For branch instructionm the constant field is not an address
  # but offset
  # To use branch target, the target must be less than 32767 instructions away
  addi $t0, $t0, 10
JP:
  # print number
  add $a0, $t0, $zero
  li $v0, 1
  syscall

  # print("\n\nTranslate if, else:\n")
  li $v0, 4
  la $a0, str1
  syscall

  # if(v1 % 4 == 0){
  #   if(v1 %100 !=0)
  #     v0 = 1; //leap year
  #   else if (v1 % 400 == 0)
  #     v0 = 1;
  #   else 
  #     v0 = 0;
  # }
  # else{ v0 = 0;}
  
  # v0 is the returned value
  addi $v1, $0, 2104
  addi $t3, $0, 4
  addi $t4, $0, 100
  addi $t5, $0, 400

  # outer if
  rem $s0, $v1, $t3  #rem is psuedo-instruction
  bne $s0, 0, OUTELSE
  
  # inner if
  rem $s0, $v1, $t4  
  beq $s0, 0, INNERELSE
  addi $v0, $0, 1
  j DONE 

INNERELSE:
  rem $s0, $v1, $t5  #rem is psuedo-instruction
  bne $s0, 0, ELSEIF
  add $v0, $0, 1
  j DONE
  
ELSEIF:
  add $v0, $0, 0
  j DONE

OUTELSE:
  addi $v0, $0, 0
  j DONE

DONE:
  # Print number 
  add $a0, $v0, $zero
  li $v0, 1
  syscall

  # WHILE LOOP
  # int a = 0
  # while(a++ < 5)
  # printf("Hello, World!\n");

  add $t0, $0, 0
  add $t1, $0, 5
WHILEBEGIN:
  blt $t0, $t1, WHILE
  j DONEWHILE
WHILE:
  addi $t0, $t0, 1
  li $v0, 4
  la $a0, helloWorld
  syscall
  j WHILEBEGIN
DONEWHILE:
  add $a0, $t0, $zero
  li $v0, 1
  syscall

  # WHILE, another method:
  add $t0, $0, 0
  add $t1, $0, 5
LOOP: bge $t0, $t1, ENDLOOP
  addi $t0, $t0, 1
  li $v0, 4
  la $a0, ANOTHERLOOP
  syscall
  j LOOP
ENDLOOP:

  li $v0, 10  ## terminate program
  syscall
