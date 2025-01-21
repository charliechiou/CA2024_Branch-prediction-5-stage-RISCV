.section .text
.global _start

_start:
    # ==========================
    # Test 3: Alternating
    # ==========================
alternating:
    li t0, 0          
    li t1, 10         
    li t2, 0          
alternating_loop:
    addi t0, t0, 1    
    beq t2, zero, alt_taken   
    j alt_not_taken            
alt_taken:
    li t2, 1          
    j alternating_loop
alt_not_taken:
    li t2, 0          
    bne t0, t1, alternating_loop

done:
    li gp, 1
