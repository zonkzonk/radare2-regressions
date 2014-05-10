#!/bin/sh

SRC="
\nmain:
\n        push rbp
\n        mov rbp, rsp
\n        sub rsp, 0x20
\n        cmp eax, 0
\n        jnz fail
\nfine:
\n        mov eax, 0
\n        jmp end
\nfail:
\n        mov eax, 1
\nend:
\n        add rsp, 0x20
\n        pop rbp
\n        ret
"
BIN=5589e583ec2083f8000f8507000000b800000000eb05b80100000083c4205dc3

rasm() {
	rasm2 -f $1
}

runtest() {
	printf "     $1\t$2"
	O=`eval $2 "$1"`
	if [ "$O" = "$3" ]; then
		echo "\r OK"
		TESTS_SUCCESS=$((${TESTS_SUCCESS}+1))
		return 0
	else
		TESTS_FAILED=$((${TESTS_FAILED}+1))
		echo "  *** FAIL because '$3' not '$O' ***"
		return 1
	fi
}

echo $SRC > test.rasm
runtest test.rasm rasm $BIN
rm -f test.rasm
TESTS_TOTAL=$((${TESTS_TOTAL}+1))
