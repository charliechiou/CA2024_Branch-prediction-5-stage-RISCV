// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDataMemory.h for the primary calling header

#include "VDataMemory.h"
#include "VDataMemory__Syms.h"

//==========

VL_CTOR_IMP(VDataMemory) {
    VDataMemory__Syms* __restrict vlSymsp = __VlSymsp = new VDataMemory__Syms(this, name());
    VDataMemory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VDataMemory::__Vconfigure(VDataMemory__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VDataMemory::~VDataMemory() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VDataMemory::_eval_initial(VDataMemory__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDataMemory::_eval_initial\n"); );
    VDataMemory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VDataMemory::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDataMemory::final\n"); );
    // Variables
    VDataMemory__Syms* __restrict vlSymsp = this->__VlSymsp;
    VDataMemory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VDataMemory::_eval_settle(VDataMemory__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDataMemory::_eval_settle\n"); );
    VDataMemory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void VDataMemory::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDataMemory::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_addr = VL_RAND_RESET_I(32);
    io_dataIn = VL_RAND_RESET_I(32);
    io_mem_read = VL_RAND_RESET_I(1);
    io_mem_write = VL_RAND_RESET_I(1);
    io_dataOut = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            DataMemory__DOT__Dmemory_ext__DOT__Memory[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
