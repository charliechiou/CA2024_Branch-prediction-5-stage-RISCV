.section .text
.global _start

_start:
    # initialize
    li t0, 0          
    li t1, 10         

    # ==========================
    # Test 1: Always Taken
    # ==========================
always_taken:
    addi t0, t0, 1    # t0 += 1
    beq t0, t1, branch_end  
    beq zero, zero, always_taken     

branch_end:
    li gp, 1
