#!/bin/sh

for a in . .. ../.. ; do [ -e $a/tests.sh ] && . $a/tests.sh ; done

NAME='adf analysis on an obfuscated executable'
BROKEN=
FILE=../../bins/pe/cmd_adf_sample0.exe
ARGS=
CMDS='
e asm.arch=x86
e asm.bits=32
e asm.os=linux
e anal.afterjmp=false
e ana
e anal.calls=false
e anal.cjmpref=false
e anal.jmpabove=true
e anal.jmpref=true
e anal.split=true
aaa
adf @ sym.testObf27.exe_VirtMe
.adf @ sym.testObf27.exe_VirtMe
adf @ 0x00560e67
.adf @ 0x00560e67
pi 10 @ 0x00560e67
'

