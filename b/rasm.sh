#!/bin/sh

SRC="
main:
        push rbp
        mov rbp, rsp
        sub rsp, 0x20
        cmp eax, 0
        jnz fine
fine:
        mov eax, 0
        jmp end
fail:
        mov eax, 1
end:
        add rsp, 0x20
        pop rbp
        ret
"
BIN=5589e583ec2083f8000f850c000000b800000000eb05b80100000083c4205dc3

rasm() {
	rasm2 -f $1
}

runtest() {
	printf "     $1\t$2"
	O=`eval $2 "$1"`
	if [ "$O" = "$3" ]; then
		echo "\r OK"
		return 0
	else
		echo "  *** FAIL because '$3' not '$O' ***"
		return 1
	fi
}

runtest test.rasm rasm $BIN
exit $?
