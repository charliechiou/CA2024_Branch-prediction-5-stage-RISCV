#include "verilated.h"
#include "VCPU.h"
#include "verilated_vcd_c.h"

void tick(VCPU* dut)
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
    VCPU* dut = new VCPU;
    dut->reset = 1;
    for (int i = 0; i < 5; i++) {
        tick(dut);
    }
    dut->reset = 0;
    int cycle_count = 0;
    int branch_count = 0;
    int flush_count = 0;
    for (size_t i = 0; i < 1500; i++)
    {
        tick(dut);
        cycle_count++;
        if(dut->CPU__DOT__control_module_io_branch)
        {
            branch_count++;
            flush_count = dut->CPU__DOT__Branch_M_io_flush ? flush_count + 1: flush_count;
        }
        // printf("0x%08X\n", dut->CPU__DOT__PC__DOT__PC);
        // printf("t0 : %d, t1 : %d\n", dut->CPU__DOT__RegFile__DOT__regfile_5, dut->CPU__DOT__RegFile__DOT__regfile_5);
        // if(i % 50 == 0)printf("gp register = 0x%08X\n", dut->CPU__DOT__RegFile__DOT__regfile_3);
        if(dut->CPU__DOT__RegFile__DOT__regfile_3 == 1)
        {
            printf("gp register = 0x%08X\n", dut->CPU__DOT__RegFile__DOT__regfile_3);
            printf("passed, cycle count : %d\n", cycle_count);
            printf("number of branch instructions : %d, predictor hit : %d\n", branch_count, branch_count - flush_count);
            
            return 0;            
        }
    }
    
    printf("failed\n");
    return 0;
}