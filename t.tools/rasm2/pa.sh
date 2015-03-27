#!/bin/sh
for a in . .. ../.. ; do [ -e $a/tests.sh ] && . $a/tests.sh ; done


NAME='r2 asm with pa'
CMDS="e asm.arch=x86
e asm.bits=32
f TEST=33
pa mov eax, TEST
"
EXPECT="b821000000
"
run_test

NAME='r2 asm with pa'
CMDS="e asm.arch=x86
e asm.bits=32
f TEST=33
pa mov eax, 33
"
EXPECT="b821000000
"
run_test
