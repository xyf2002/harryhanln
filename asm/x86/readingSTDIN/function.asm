; find the length of the string
slen:
  push  ebx
  mov   ebx, eax

nextchar:
  cmp byte [eax], 0
  jz  finished
  inc eax
  jmp nextchar

finished:
  sub eax, ebx  ; store the return value in eax
  pop ebx
  ret

; string printing function
sprint:
  push edx
  push ecx
  push ebx
  push eax

  call slen 
  mov edx, eax ; eax is the retune value from slen 

  pop eax  ;restore eax to original input
  mov ecx, eax 
  mov ebx, 1
  mov eax, 4
  int 80h

  pop ebx
  pop ecx
  pop edx
  ret  ; return to original position

sprintLF:
  call sprint  ; first, print the lines
  push eax ; save eax to stack
  mov eax, 0Ah ; 0Ah is newline in asci
  push eax  ; push it to stack
  mov eax, esp ; esp stores the stack pointer
  call sprint ; print the new line
  pop eax
  pop eax
  ret
quit:
  mov ebx, 0
  mov eax, 1
  int 80h
  ret
