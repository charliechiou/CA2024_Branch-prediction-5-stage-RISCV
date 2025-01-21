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
    # ==========================
    # Test 2: Not Taken
    # ==========================
not_taken:
    li t0, 0         
    li t1, 10         
not_taken_loop:
    addi t0, t0, 1    
    bne t0, t1, not_taken_loop  

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
