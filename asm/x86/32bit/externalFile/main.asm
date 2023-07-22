%include  "function.asm"

SECTION .data
msg1  db  "Hello, Brave New World!", 0Ah, 0h ; strings need to be null terminated
msg2  db  "This is how to reuse function", 0Ah, 0h ; strings need to be null terminated
msg3 db   "A line without linefeed"

SECTION .text
global  _start

_start:
  mov   eax, msg1
  call sprint

  mov   eax, msg2
  call sprint

  call quit

