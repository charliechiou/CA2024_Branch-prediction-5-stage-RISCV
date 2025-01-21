#include "verilated.h"
#include "VPIPELINE.h"
#include "verilated_vcd_c.h"

void tick(VPIPELINE* dut)
{
    dut->clock = 0;
    dut->eval();
    dut->clock = 1;
    dut->eval();
}

int main(int argc, char** argv, char** env)
{
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    VPIPELINE* dut = new VPIPELINE;
    dut->reset = 1;
    for (int i = 0; i < 5; i++) {
        tick(dut);
    }
    dut->reset = 0;
    int cycle_count = 0;
    int branch_count = 0;
    int flush_count = 0;
    for (size_t i = 0; i < 600; i++)
    {
        tick(dut);
        cycle_count++;
        if(dut->PIPELINE__DOT__control_module_io_branch)
        {
            branch_count++;
            flush_count = dut->PIPELINE__DOT__Branch_M_io_br_taken & dut->PIPELINE__DOT__control_module_io_branch 
            ? flush_count + 1: flush_count;
        }
        // printf("0x%08X\n", dut->PIPELINE__DOT__PC__DOT__PC);
        // if(i % 50 == 0)printf("gp register = 0x%08X\n", dut->PIPELINE__DOT__RegFile__DOT__regfile_3);
        if(dut->PIPELINE__DOT__RegFile__DOT__regfile_3 == 1)
        {
            printf("gp register = 0x%08X\n", dut->PIPELINE__DOT__RegFile__DOT__regfile_3);
            printf("passed, cycle count : %d\n", cycle_count);
            printf("number of branch instructions : %d, predictor hit : %d\n", branch_count, branch_count - flush_count);
            
            return 0;            
        }
    }
    
    printf("failed\n");
    return 0;
}