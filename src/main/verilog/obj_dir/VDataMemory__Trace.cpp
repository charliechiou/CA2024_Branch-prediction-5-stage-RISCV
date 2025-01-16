// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VDataMemory__Syms.h"


void VDataMemory::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VDataMemory__Syms* __restrict vlSymsp = static_cast<VDataMemory__Syms*>(userp);
    VDataMemory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VDataMemory::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VDataMemory__Syms* __restrict vlSymsp = static_cast<VDataMemory__Syms*>(userp);
    VDataMemory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->clock));
        tracep->chgBit(oldp+1,(vlTOPp->reset));
        tracep->chgIData(oldp+2,(vlTOPp->io_addr),32);
        tracep->chgIData(oldp+3,(vlTOPp->io_dataIn),32);
        tracep->chgBit(oldp+4,(vlTOPp->io_mem_read));
        tracep->chgBit(oldp+5,(vlTOPp->io_mem_write));
        tracep->chgIData(oldp+6,(vlTOPp->io_dataOut),32);
        tracep->chgSData(oldp+7,((0x3ffU & vlTOPp->io_addr)),10);
        tracep->chgIData(oldp+8,(((IData)(vlTOPp->io_mem_read)
                                   ? vlTOPp->DataMemory__DOT__Dmemory_ext__DOT__Memory
                                  [(0x3ffU & vlTOPp->io_addr)]
                                   : 0U)),32);
    }
}

void VDataMemory::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VDataMemory__Syms* __restrict vlSymsp = static_cast<VDataMemory__Syms*>(userp);
    VDataMemory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
