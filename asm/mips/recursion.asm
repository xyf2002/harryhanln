  .data 
newLine: .asciiz "\n"

# Implement the factorial function
# int factorial(int n){
#   if (n == 0) return 1;
#   return (factorial(n-1)*n);
# }
  .text
main:

jal printNewLine

# end the program
addi $v0, $0, 10
syscall

printNewLine:
li $v0, 4
la $a0, newLine
syscall
jr $ra
