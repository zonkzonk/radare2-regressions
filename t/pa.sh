#!/bin/sh
[ -e tests.sh ] && . ./tests.sh || . ../tests.sh


NAME='r2 asm with pa'
CMDS="e asm.arch=x86
e asm.bits=32
f TEST=33
pa mov eax, TEST
"
BROKEN=1
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
