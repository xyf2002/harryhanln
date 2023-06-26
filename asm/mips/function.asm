# MIPS assembly
# run on x86 with MARS
	.data
newLine: .asciiz "\n"

  .text
main:
addi $a0, $0, 10
# a0 will be destroyed in function, must be loaded into memory (stack)
addi $sp, $sp, -4 # move stack pointer down
# stack pointer points to address
sw $a0, 0($sp) # a0 stored in stack

jal printNewLine  # jump to printNewLine and store current line in register $ra 

lw $a0, 0($sp) # load a0 from stack
addi $sp, $sp, 4 # move stack pointer up (pop stack)

li $a0, 1
jal printInt

li $a0, 1000
jal printInt

# terminate the program
li $v0 10
syscall

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

printNewLine:
addi $v0, $0, 4
la $a0, newLine
syscall
jr $ra # jump to register $ra
