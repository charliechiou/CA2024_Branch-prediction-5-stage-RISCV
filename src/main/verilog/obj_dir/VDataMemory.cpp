// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDataMemory.h for the primary calling header

#include "VDataMemory.h"
#include "VDataMemory__Syms.h"

//==========

void VDataMemory::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VDataMemory::eval\n"); );
    VDataMemory__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VDataMemory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("DataMemory.v", 20, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VDataMemory::_eval_initial_loop(VDataMemory__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("DataMemory.v", 20, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VDataMemory::_sequent__TOP__1(VDataMemory__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDataMemory::_sequent__TOP__1\n"); );
    VDataMemory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__DataMemory__DOT__Dmemory_ext__DOT__Memory__v0;
    SData/*9:0*/ __Vdlyvdim0__DataMemory__DOT__Dmemory_ext__DOT__Memory__v0;
    IData/*31:0*/ __Vdlyvval__DataMemory__DOT__Dmemory_ext__DOT__Memory__v0;
    // Body
    __Vdlyvset__DataMemory__DOT__Dmemory_ext__DOT__Memory__v0 = 0U;
    if (vlTOPp->io_mem_write) {
        __Vdlyvval__DataMemory__DOT__Dmemory_ext__DOT__Memory__v0 
            = vlTOPp->io_dataIn;
        __Vdlyvset__DataMemory__DOT__Dmemory_ext__DOT__Memory__v0 = 1U;
        __Vdlyvdim0__DataMemory__DOT__Dmemory_ext__DOT__Memory__v0 
            = (0x3ffU & vlTOPp->io_addr);
    }
    if (__Vdlyvset__DataMemory__DOT__Dmemory_ext__DOT__Memory__v0) {
        vlTOPp->DataMemory__DOT__Dmemory_ext__DOT__Memory[__Vdlyvdim0__DataMemory__DOT__Dmemory_ext__DOT__Memory__v0] 
            = __Vdlyvval__DataMemory__DOT__Dmemory_ext__DOT__Memory__v0;
    }
}

VL_INLINE_OPT void VDataMemory::_settle__TOP__2(VDataMemory__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDataMemory::_settle__TOP__2\n"); );
    VDataMemory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_dataOut = ((IData)(vlTOPp->io_mem_read)
                           ? ((IData)(vlTOPp->io_mem_read)
                               ? vlTOPp->DataMemory__DOT__Dmemory_ext__DOT__Memory
                              [(0x3ffU & vlTOPp->io_addr)]
                               : 0U) : 0U);
}

void VDataMemory::_eval(VDataMemory__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDataMemory::_eval\n"); );
    VDataMemory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_settle__TOP__2(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

VL_INLINE_OPT QData VDataMemory::_change_request(VDataMemory__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDataMemory::_change_request\n"); );
    VDataMemory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VDataMemory::_change_request_1(VDataMemory__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDataMemory::_change_request_1\n"); );
    VDataMemory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VDataMemory::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDataMemory::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_mem_read & 0xfeU))) {
        Verilated::overWidthError("io_mem_read");}
    if (VL_UNLIKELY((io_mem_write & 0xfeU))) {
        Verilated::overWidthError("io_mem_write");}
}
#endif  // VL_DEBUG
