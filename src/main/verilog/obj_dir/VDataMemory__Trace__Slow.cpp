// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VDataMemory__Syms.h"


//======================

void VDataMemory::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VDataMemory::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VDataMemory__Syms* __restrict vlSymsp = static_cast<VDataMemory__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VDataMemory::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VDataMemory::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VDataMemory__Syms* __restrict vlSymsp = static_cast<VDataMemory__Syms*>(userp);
    VDataMemory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VDataMemory::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VDataMemory__Syms* __restrict vlSymsp = static_cast<VDataMemory__Syms*>(userp);
    VDataMemory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clock", false,-1);
        tracep->declBit(c+2,"reset", false,-1);
        tracep->declBus(c+3,"io_addr", false,-1, 31,0);
        tracep->declBus(c+4,"io_dataIn", false,-1, 31,0);
        tracep->declBit(c+5,"io_mem_read", false,-1);
        tracep->declBit(c+6,"io_mem_write", false,-1);
        tracep->declBus(c+7,"io_dataOut", false,-1, 31,0);
        tracep->declBit(c+1,"DataMemory clock", false,-1);
        tracep->declBit(c+2,"DataMemory reset", false,-1);
        tracep->declBus(c+3,"DataMemory io_addr", false,-1, 31,0);
        tracep->declBus(c+4,"DataMemory io_dataIn", false,-1, 31,0);
        tracep->declBit(c+5,"DataMemory io_mem_read", false,-1);
        tracep->declBit(c+6,"DataMemory io_mem_write", false,-1);
        tracep->declBus(c+7,"DataMemory io_dataOut", false,-1, 31,0);
        tracep->declBus(c+8,"DataMemory Dmemory_ext R0_addr", false,-1, 9,0);
        tracep->declBit(c+5,"DataMemory Dmemory_ext R0_en", false,-1);
        tracep->declBit(c+1,"DataMemory Dmemory_ext R0_clk", false,-1);
        tracep->declBus(c+9,"DataMemory Dmemory_ext R0_data", false,-1, 31,0);
        tracep->declBus(c+8,"DataMemory Dmemory_ext W0_addr", false,-1, 9,0);
        tracep->declBit(c+6,"DataMemory Dmemory_ext W0_en", false,-1);
        tracep->declBit(c+1,"DataMemory Dmemory_ext W0_clk", false,-1);
        tracep->declBus(c+4,"DataMemory Dmemory_ext W0_data", false,-1, 31,0);
    }
}

void VDataMemory::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VDataMemory::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VDataMemory__Syms* __restrict vlSymsp = static_cast<VDataMemory__Syms*>(userp);
    VDataMemory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VDataMemory::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VDataMemory__Syms* __restrict vlSymsp = static_cast<VDataMemory__Syms*>(userp);
    VDataMemory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->clock));
        tracep->fullBit(oldp+2,(vlTOPp->reset));
        tracep->fullIData(oldp+3,(vlTOPp->io_addr),32);
        tracep->fullIData(oldp+4,(vlTOPp->io_dataIn),32);
        tracep->fullBit(oldp+5,(vlTOPp->io_mem_read));
        tracep->fullBit(oldp+6,(vlTOPp->io_mem_write));
        tracep->fullIData(oldp+7,(vlTOPp->io_dataOut),32);
        tracep->fullSData(oldp+8,((0x3ffU & vlTOPp->io_addr)),10);
        tracep->fullIData(oldp+9,(((IData)(vlTOPp->io_mem_read)
                                    ? vlTOPp->DataMemory__DOT__Dmemory_ext__DOT__Memory
                                   [(0x3ffU & vlTOPp->io_addr)]
                                    : 0U)),32);
    }
}
