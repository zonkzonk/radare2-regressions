r2 -nq malloc://1024 <<EOF
e asm.arch=avr
s 0x2d6
wx 0e940b10
wx 9093c007
?e --pi 1
pi 1
ao 1 >/dev/null
?e --ao 1, pi 1
pi 1
?e --pd 1
pd 1
?e --ao,pd 1
ao 1~jump
pd 1
pi 2
?e --
EOF
