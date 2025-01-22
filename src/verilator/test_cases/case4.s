.section .text
.global _start

_start:
        li      sp, 0x7ff
        li      t0, 69
        addi    sp, sp, -4
        sw      t0, 0(sp)
        lw      t1, 0(sp)
        nop
        addi    sp, sp, 4
        li      gp, 1