.section .text
.global _start

_start:
    addi    a0,zero, -79   # multiplier
    addi    a1,zero, 2   # multiplicand
    addi    t2,zero, 0   # result
loop:
    addi    t0,zero,  1   # check if lsb = 0
    beq     a1, zero, done
    and     t0, a1, t0
    beq     t0, zero, next
    add     t2, a0, t2
next:
    srli    a1, a1, 1
    slli    a0, a0, 1
    j       loop
done:
    li  gp, 1