# Gnu DeBugger

## How to Use

- Compile the c++ source code with `-g` flag.
- Run the program with `gdb <path-to-executable>` command.
- Or enter `gdb` command and then `file <path-to-executable>` command.

The executable will be 'hosted' in gdb command line interface.

## Useful commands

- `help`: display help message:
    -`help x`: help message for examine
- `run` run the executable. `run` can be followed with inputs.
- `continue` continue the execution. `c` for short.
- `break` set break point. `break +<line-number>` or `break <function-name>`.
- `next` execute the next line. `n` for short. 
- `list` list the source code. `l` for short. `l +<line-number>` or `l-<line-number>`, or `l + <line-number>`, or `l <function-name>`.
- `print` print the value of a variable. `p` for short.
    * p &variable : prints the address of the variable
    * `p/x`: print in hexadecimal
- `x`: examine the value arround address. Examine has many formats, see help x
    * `x/10b $sp` examine the next 10 bytes around stack pointer
    * `x/20wx 0x7fffffffdd90` examine the nex 20 words (4 byte each), show in hexdecimal
- `step` step into the function. `s` for short.
- `info` print the information. `i` for short. info is very versatile
    * `info local`: print all local variables
    * `info frame`: give information about current stack frame
- `up` go up the stack. `u` for short.
- `backtrace` print the call stack. `bt` for short.
- `display` display the value of a variable each time the program stops. `d` for short.
- `undisplay` remove the display. 
- `delete` delete the break point. `d` for short.
- `whatis` print the type of a variable. 


## Debuggin Options 

### Tell GDB to Stop

#### Break Points

- `break` set break point. `break +<line-number>` or `break <function-name>`.
When the program is executed by run, gdb shows the next line to be executed:

```gdb
Breakpoint 1, main () at add.cpp:6
6	    int j = 7;
```

Here, breakpoint at 6 means line 6 has not been executed.

#### Useful Commends:

- `info breakpoints` print all of the breakpoints.
- `clear` clear the breakpoint. `clear <line-number>` or `clear <function-name>`.


#### Watch Points

- `watch` watch the value of a variable. `watch <variable-name>`. gdb will stop when the value of the variable is changed.

#### Delete

- `delete <index>` delete the breakpoint at index. To see index, use `info breakpoints`.
- `delete` to delete all.

### Miscellanous

#### Backtrace

- `backtrace` print the call stack. `bt` for short.
- `step` steps in the function
- `finish` finish the function

#### Reverse execution

Use `target record-full` to record all execution. Then use `reverse-next` (among others) to reverse the execution.

#### Change the value of a variable 

- `set variable <variable-name> = <value>` change the value of a variable. 
