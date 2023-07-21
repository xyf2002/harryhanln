# MIPS Architecture & Assembly Language

## Quickstart

## Assemblage and Execution on x86 environment

MARS (Mips assembler and runtime simulator) can be used to assemble and run mips assembly language on x86 environment. 
Simply run

```shell
mars filename.asm 
```

### 32 Registers

32-bit MIPS has 32 fast registers, prefixed by `$`:

- $s0-$s7: for local storage
- $t0-$t9: for local storage
- $zero (same as $0): stores 0, can not be modified
- $a0-$a3: passing arguments to procedures
- $v0-$v1: for syscall and procedure return value
- $gp: pointer to global data
- $fp: frame pointer
- $sp: stack pointer
- $ra: return address of syscall
- $at, or `$1`, reserved for assembler for temporary values
- $k0-1 reserved for OS kernel

Each register holds 32 bits of value with an address of 5 bit.

To perform arithmetic operation, all value must be loaded into register.

### Operation 

- `add $t0, $s0, $s1` : $t0 = $s0 + $s1
- `sub $t0, $s0, $s1` : $t0 = $s0 - $s1
- `mul $t0, $s0, $s1` : $t0 = $s0 * $s1
- `div $t0, $s0, $s1` : $t0 = $s0 / $s1


### Initialise registers

- `addi $t0, $zero, 10` : $t0 = 10 (equivalent to `li $t0, 10`)

### Psuedo-instructions

Psuedo-instructions are not real instructions, but are translated into real instructions by the assembler.

- `move $t0, $s0` : $t0 = $s0 
- `la $t0, label` : $t0 = address of label
- `rem` 

### Branches

- Two real branches: `beq` and `bne` (equal, not equal)
- psuedo-instructions: `bgt`, `blt`, `bge`, `ble` (greater than, less than, greater equal, less equal)

```MIPS
beq $s0, $s1, EQ
add $t0, $s0, $s1
EA: MUL $t0, $s0, 2
```

#### if, if-else

### function

- `jal label` : (jump and link) jump to label and store return address in $ra, use for begin function call
- `jr $ra` : jump to address stored in $ra, use for return funciton call
- Arguments are passed in $a0-$a3, return value is stored in $v0-$v1
- Registers shall be spilled to stack before function call.
- Convention: function may use registers $t0-$t9, $a0-$a3, $v0-$v1but must keep $s0-$s7, $ra untouched

#### Push to stack

- `addi $sp, $sp, -4` : move stack pointer to next address
- `sw $t0, 0($sp)` : store $t0 to stack
- `lw $t0, 0($sp)` : load $t0 from stack
- `addi $sp, $sp, 4` : move stack pointer to previous address

#### How to use stack in function call

Stack help us to avoid register spill and save register value for function call.

To use stack for function call, following the procedure

- store required variable in stack (including returning address)
- when a function call is to return, the stack must be reseted to the state it is received
- reusing the variable stored in stack by order.

