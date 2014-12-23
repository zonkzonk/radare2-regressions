#!/bin/sh
for a in . .. ../.. ; do [ -e $a/tests.sh ] && . $a/tests.sh ; done


NAME='Rasm2'
CMDS="!rasm2 -a x86 -b 64 -d '5589e583ec2083f8000f8507000000b800000000eb05b80100000083c4205dc3' "
EXPECT='push rbp
mov ebp, esp
sub esp, 0x20
cmp eax, 0
jne 0x16
mov eax, 0
jmp 0x1b
mov eax, 1
add esp, 0x20
pop rbp
ret
'
run_test

NAME='Rasm2 #1167'
CMDS="!rasm2 -a x86 -b 64 'cmp rax,rbx' "
EXPECT='4839d8
'
run_test

NAME='Rasm2 #1167 2'
CMDS="!rasm2 -a x86 -b 64 'test rax, rbx' "
EXPECT='4885d8
'
run_test

NAME='Rasm2 #1190'
CMDS="!rasm2 -a x86 -b 32 'mov [0x33], eax'
!rasm2 -a x86 -b 32 'mov eax, 33'
!rasm2 -a x86 -b 32 'mov eax, 0x33'
"
EXPECT='890533000000
b821000000
b833000000
'
run_test

NAME='Rasm2 #1190 (detect syntax error - case 1)'
CMDS="!rasm2 -a x86 -b 32 'mov hello, eax'"
EXPECT_ERR="Cannot assemble 'mov hello, eax' at line 3
invalid
"
run_test

NAME='Rasm2 #1190 (detect syntax error - case 2)'
CMDS="!rasm2 -a x86 -b 32 'mov 33, eax'"
EXPECT_ERR="Cannot assemble 'mov hello, eax' at line 3
invalid
"
run_test

NAME='Rasm2 #1190 (detect syntax error - case 3)'
CMDS="!rasm2 -a x86 -b 32 'mov eax, hello'"
BROKEN=1
EXPECT_ERR="Cannot assemble 'mov hello, eax' at line 3
invalid
"
run_test
