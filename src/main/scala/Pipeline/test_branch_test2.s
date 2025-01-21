.section .text
.global _start

_start:
    # initialize
    # ==========================
    # Test 2: Not Taken
    # ==========================
not_taken:
    li t0, 0         
    li t1, 10         
not_taken_loop:
    addi t0, t0, 1    
    bne t0, t1, not_taken_loop  
    
done:
    li gp, 1
