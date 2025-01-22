.section .text
.global _start
.data

_start:
        lui	sp, 0x7ffff
        addi    sp, sp, 0x000
        addi    sp,sp,-16
        sw      ra,12(sp)
        sw      s0,8(sp)
        addi    s0,sp,16
        li      a1,10
        # a0 start at the bottom of memory 
        # a0 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}
        li      a0, 0
        mv      t0, a0
        li      t2, 9
        sw      t2, 0(t0)
        addi    t0, t0, 4
        li      t2, 8
        sw      t2, 0(t0)
        addi    t0, t0, 4
        li      t2, 7
        sw      t2, 0(t0)
        addi    t0, t0, 4
        li      t2, 6
        sw      t2, 0(t0)
        addi    t0, t0, 4
        li      t2, 5
        sw      t2, 0(t0)
        addi    t0, t0, 4
        li      t2, 4
        sw      t2, 0(t0)
        addi    t0, t0, 4
        li      t2, 3
        sw      t2, 0(t0)
        addi    t0, t0, 4
        li      t2, 2
        sw      t2, 0(t0)
        addi    t0, t0, 4
        li      t2, 1
        sw      t2, 0(t0)
        addi    t0, t0, 4
        li      t2, 0
        sw      t2, 0(t0)
        addi    t0, t0, 4      
        jal     ra, bubble_sort
        li      a5,0
        mv      a0,a5
        lw      ra,12(sp)
        lw      s0,8(sp)
        addi    sp,sp,16
        li	gp, 1
        jr      ra

bubble_sort:
        addi    sp,sp,-48
        #sw      ra,44(sp)
        sw      s0,40(sp)
        addi    s0,sp,48
        sw      a0,-36(s0)
        sw      a1,-40(s0)
        sw      zero,-20(s0)
        j       .L2
.L8:
        sw      zero,-28(s0)
        sw      zero,-24(s0)
        j       .L3
.L5:
        lw      a5,-24(s0)
        slli    a5,a5,2
        lw      a4,-36(s0)
        add     a5,a4,a5
        lw      a4,0(a5)
        lw      a5,-24(s0)
        addi    a5,a5,1
        slli    a5,a5,2
        lw      a3,-36(s0)
        add     a5,a3,a5
        lw      a5,0(a5)
        ble     a4,a5,.L4
        lw      a5,-24(s0)
        addi    a5,a5,1
        slli    a5,a5,2
        lw      a4,-36(s0)
        add     a5,a4,a5
        lw      a5,0(a5)
        sw      a5,-32(s0)
        lw      a5,-24(s0)
        slli    a5,a5,2
        lw      a4,-36(s0)
        add     a4,a4,a5
        lw      a5,-24(s0)
        addi    a5,a5,1
        slli    a5,a5,2
        lw      a3,-36(s0)
        add     a5,a3,a5
        lw      a4,0(a4)
        sw      a4,0(a5)
        lw      a5,-24(s0)
        slli    a5,a5,2
        lw      a4,-36(s0)
        add     a5,a4,a5
        lw      a4,-32(s0)
        sw      a4,0(a5)
.L4:
        lw      a5,-24(s0)
        addi    a5,a5,1
        sw      a5,-24(s0)
.L3:
        lw      a4,-40(s0)
        lw      a5,-20(s0)
        sub     a5,a4,a5
        addi    a5,a5,-1
        lw      a4,-24(s0)
        blt     a4,a5,.L5
        lw      a5,-28(s0)
        bne     a5,zero,.L9
        lw      a5,-20(s0)
        addi    a5,a5,1
        sw      a5,-20(s0)
.L2:
        lw      a4,-20(s0)
        lw      a5,-40(s0)
        blt     a4,a5,.L8
        j       .L10
.L9:
        nop
.L10:
        nop
        #lw      ra,44(sp)
        lw      s0,40(sp)
        addi    sp,sp,48
        jr      ra
