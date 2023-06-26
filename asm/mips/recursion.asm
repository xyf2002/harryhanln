  .data 
newLine: .asciiz "\n"

  .text
main:

addi $a0, $0, 5
jal factorial

add $a0, $0, $v0
jal printInt

# end the program
addi $v0, $0, 10
syscall

printNewLine:
li $v0, 4
la $a0, newLine
syscall
jr $ra

# Implement the factorial function
# int factorial(int n){
#   if (n == 0) return 1;
#   return (factorial(n-1)*n);
# }

# factorial function takes one input in a0 and return a0! at v0
factorial:
bne $a0, 0, recurse
addi $v0, $0, 1
jr $ra
recurse:
# load address to stack
addi $sp, $sp, -8
sw $ra, 4($sp)
add $t0, $a0, $0
# load to stack
sw $t0, 0($sp)
# next input
add $a0, $a0, -1
# recursive call
jal factorial
# get the initial input from stack
lw $t1, 0($sp) 
# get the return address
lw $ra, 4($sp) 
# resetting stack
addi $sp, $sp, 8
# get the return value 
mul $v0, $v0, $t1 
# return to calling address
jr $ra

printInt: 
# print value
li $v0 1
syscall
# pushing to stack
addi $sp, $sp, -4
sw $ra, 0($sp)
# function call
jal printNewLine
# popping from stack
lw $ra, 0($sp)
addi $sp, $sp, 4

jr $ra

