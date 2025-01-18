#include "VDataMemory.h"        
#include "verilated.h"         
#include "verilated_vcd_c.h"   
#include <stdint.h>
#include <iostream>

// clock
void tick(VDataMemory* dut, VerilatedVcdC* tfp, int tickcount) {
    dut->clock = 0;  // negedge
    dut->eval();
    if (tfp) tfp->dump(tickcount * 10 - 5);  // dump negedge result
    dut->clock = 1;  // posedge
    dut->eval();
    if (tfp) tfp->dump(tickcount * 10);  // dump posedge result
    if (tfp) tfp->flush();
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);  
    Verilated::traceEverOn(true);       
    VDataMemory* dut = new VDataMemory; 

    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);  // 99 for tracing all signals
    tfp->open("DataMemory.vcd");

    // init
    dut->reset = 1;
    int tickcount = 0;
    tick(dut, tfp, ++tickcount);  
    dut->reset = 0;
    for(int i = 0; i < 30; i++)
    {
        // write into memory
        uint32_t addr = rand() % 1024;
        int data = rand();
        dut->io_mem_write = 1;       
        dut->io_mem_read = 0;        
        dut->io_addr = addr;           
        dut->io_dataIn = data;         
        tick(dut, tfp, ++tickcount);           

        // read from memory
        dut->io_mem_write = 0;       
        dut->io_mem_read = 1;        
        dut->io_addr = addr;           
        tick(dut, tfp, ++tickcount);           

        // verify output
        if (dut->io_dataOut == data) {
            printf("Test passed: Read value is %d\n", dut->io_dataOut);
        } else {
            printf("Test failed: Expected %d, ", data);
            printf("but got %d\n", dut->io_dataOut);
        }
    }

    dut->final();
    if (tfp) tfp->close();
    delete dut;
    delete tfp;

    return 0;
}
