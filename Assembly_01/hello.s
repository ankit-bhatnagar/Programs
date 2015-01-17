.global _start

_start:
    pushl %ebp
    movl %esp, %ebp
    # code
    movl $01, %eax
    leave
    ret
