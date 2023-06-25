# Variable is a labeled chunck of memory
  .data:
c: .byte 1  # char c = 0x12;
a: .byte 0 1   # char a [2] = {0, 1};
b: .space 50   # char b[50];
newLine: .asciiz "\n"

 .text:
la $t0, a # load address: t0 = &a[0]

lb $a0, 0($t0) # load buffer, t1 = a[0]
li $v0, 1  # load immediately
syscall

li $t2, 10
sb $t2, 1($t0)  # store buffer a[1] = t2;

# Print newline
li $v0, 4
la $a0, newLine
syscall

lb $a0, 1($t0) # t1 = a[0]
li $v0, 1
syscall

# Print newline
li $v0, 4
la $a0, newLine
syscall

# looping through array
li $t0, 0
la $s0, b

loop: bge $t0, 50, end
sb $t0, 0($s0)

# Print array
lb $a0, 0($s0)  #pointer arithmetic 
li $v0, 1
syscall
# Print newline
li $v0, 4
la $a0, newLine
syscall

add $t0, $t0, 1
add $s0, $s0, 1
j loop
end:
