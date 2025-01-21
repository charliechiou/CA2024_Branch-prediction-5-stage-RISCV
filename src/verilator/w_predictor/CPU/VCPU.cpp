// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCPU.h for the primary calling header

#include "VCPU.h"
#include "VCPU__Syms.h"

//==========

void VCPU::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VCPU::eval\n"); );
    VCPU__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VCPU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("CPU.v", 1586, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VCPU::_eval_initial_loop(VCPU__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("CPU.v", 1586, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VCPU::_sequent__TOP__2(VCPU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU::_sequent__TOP__2\n"); );
    VCPU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__CPU__DOT__DataMemory__DOT__Dmemory__v0;
    SData/*11:0*/ __Vdlyvdim0__CPU__DOT__DataMemory__DOT__Dmemory__v0;
    IData/*31:0*/ __Vdly__CPU__DOT__PC__DOT__PC;
    IData/*31:0*/ __Vdlyvval__CPU__DOT__DataMemory__DOT__Dmemory__v0;
    // Body
    __Vdly__CPU__DOT__PC__DOT__PC = vlTOPp->CPU__DOT__PC__DOT__PC;
    __Vdlyvset__CPU__DOT__DataMemory__DOT__Dmemory__v0 = 0U;
    vlTOPp->CPU__DOT__IF_ID___DOT__io_pred_out_REG 
        = vlTOPp->CPU__DOT__predictor_io_prediction;
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__predictor__DOT__currentState = 3U;
    } else {
        if (vlTOPp->CPU__DOT__control_module_io_branch) {
            vlTOPp->CPU__DOT__predictor__DOT__currentState 
                = ((IData)(vlTOPp->CPU__DOT__predictor__DOT___T)
                    ? ((IData)(vlTOPp->CPU__DOT__Branch_M_io_actual)
                        ? 2U : 3U) : ((IData)(vlTOPp->CPU__DOT__predictor__DOT___T_1)
                                       ? ((IData)(vlTOPp->CPU__DOT__Branch_M_io_actual)
                                           ? 1U : 3U)
                                       : (IData)(vlTOPp->CPU__DOT__predictor__DOT___GEN_1)));
        }
    }
    vlTOPp->CPU__DOT__ID_EX___DOT__io_rs1_data_out_REG 
        = ((IData)(vlTOPp->CPU__DOT__Structural_io_fwd_rs1)
            ? ((IData)(vlTOPp->CPU__DOT__Structural_io_fwd_rs1)
                ? vlTOPp->CPU__DOT__RegFile_io_w_data
                : 0U) : vlTOPp->CPU__DOT__RegFile_io_rdata1);
    vlTOPp->CPU__DOT__ID_EX___DOT__io_IFID_pc4_out_REG 
        = vlTOPp->CPU__DOT__IF_ID___DOT__Pc4_In;
    vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_memRd_out_REG 
        = vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_memRd_out_REG;
    vlTOPp->CPU__DOT__ID_EX___DOT__io_func3_out_REG 
        = (7U & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                 >> 0xcU));
    vlTOPp->CPU__DOT__ID_EX___DOT__io_func7_out_REG 
        = (1U & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                 >> 0x1eU));
    vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_AluOp_out_REG 
        = ((IData)(vlTOPp->CPU__DOT__HazardDetect_io_ctrl_forward)
            ? 0U : ((0x33U == (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                     ? 0U : ((0x13U == (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                              ? 1U : ((0x23U == (0x7fU 
                                                 & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                       ? 5U : ((3U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                ? 4U
                                                : (
                                                   (0x63U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                    ? 2U
                                                    : 
                                                   ((0x6fU 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                     ? 3U
                                                     : 
                                                    ((0x67U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                      ? 3U
                                                      : 
                                                     ((0x37U 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                       ? 6U
                                                       : 
                                                      ((0x17U 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                        ? 7U
                                                        : 0U))))))))));
    vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_OpA_out_REG 
        = ((0x33U == (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
            ? 0U : ((0x13U == (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                     ? 0U : ((0x23U == (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                              ? 0U : ((3U == (0x7fU 
                                              & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                       ? 0U : ((0x63U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                ? 0U
                                                : (
                                                   (0x6fU 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                    ? 1U
                                                    : 
                                                   ((0x67U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                     ? 1U
                                                     : 
                                                    ((0x37U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                      ? 3U
                                                      : 
                                                     ((0x17U 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                       ? 2U
                                                       : 0U)))))))));
    vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_OpB_out_REG 
        = ((~ (IData)(vlTOPp->CPU__DOT__HazardDetect_io_ctrl_forward)) 
           & ((0x33U != (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
              & ((0x13U == (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                 | ((0x23U == (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                    | ((3U == (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                       | ((0x63U != (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                          & ((0x6fU != (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                             & ((0x67U != (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                & (IData)(vlTOPp->CPU__DOT__control_module__DOT___GEN_5)))))))));
    vlTOPp->CPU__DOT__ID_EX___DOT__io_imm_out_REG = 
        ((2U == (IData)(vlTOPp->CPU__DOT__control_module_io_extend))
          ? (0xfffff000U & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
          : vlTOPp->CPU__DOT___ImmValue_T_3);
    __Vdly__CPU__DOT__PC__DOT__PC = ((IData)(vlTOPp->reset)
                                      ? 0U : ((IData)(vlTOPp->CPU__DOT__HazardDetect_io_pc_forward)
                                               ? vlTOPp->CPU__DOT__IF_ID___DOT__Pc4_In
                                               : ((1U 
                                                   == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                                   ? 
                                                  (((IData)(vlTOPp->CPU__DOT__Branch_M_io_flush) 
                                                    & (IData)(vlTOPp->CPU__DOT__control_module_io_branch))
                                                    ? 
                                                   ((IData)(vlTOPp->CPU__DOT__Branch_M_io_actual)
                                                     ? vlTOPp->CPU__DOT__IF_ID___DOT__S_pc
                                                     : vlTOPp->CPU__DOT__IF_ID___DOT__Pc4_In)
                                                    : vlTOPp->CPU__DOT___PC_io_in_T_5)
                                                   : 
                                                  ((2U 
                                                    == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                                    ? 
                                                   (((((0x80000000U 
                                                        & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                                        ? 0x7ffU
                                                        : 0U) 
                                                      << 0x15U) 
                                                     | ((0x100000U 
                                                         & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                            >> 0xbU)) 
                                                        | ((0xff000U 
                                                            & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr) 
                                                           | ((0x800U 
                                                               & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                                  >> 9U)) 
                                                              | (0x7feU 
                                                                 & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                                    >> 0x14U)))))) 
                                                    + vlTOPp->CPU__DOT__IF_ID___DOT__S_pc)
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                                     ? 
                                                    (0xfffffffeU 
                                                     & (((2U 
                                                          == (IData)(vlTOPp->CPU__DOT__control_module_io_extend))
                                                          ? 
                                                         (0xfffff000U 
                                                          & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                                          : vlTOPp->CPU__DOT___ImmValue_T_3) 
                                                        + 
                                                        ((0xaU 
                                                          == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                          ? vlTOPp->CPU__DOT__RegFile_io_w_data
                                                          : 
                                                         ((9U 
                                                           == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                           ? vlTOPp->CPU__DOT__DataMemory_io_dataOut
                                                           : 
                                                          ((8U 
                                                            == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                            ? vlTOPp->CPU__DOT__RegFile_io_w_data
                                                            : 
                                                           ((7U 
                                                             == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                             ? vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG
                                                             : 
                                                            ((6U 
                                                              == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                              ? (IData)(vlTOPp->CPU__DOT__ALU__DOT___GEN_10)
                                                              : 
                                                             ((5U 
                                                               == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                               ? vlTOPp->CPU__DOT__RegFile_io_rdata1
                                                               : 
                                                              ((4U 
                                                                == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                                ? vlTOPp->CPU__DOT__RegFile_io_rdata1
                                                                : 
                                                               ((3U 
                                                                 == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                                 ? vlTOPp->CPU__DOT__RegFile_io_rdata1
                                                                 : 
                                                                ((2U 
                                                                  == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                                  ? vlTOPp->CPU__DOT__RegFile_io_rdata1
                                                                  : 
                                                                 ((1U 
                                                                   == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                                   ? vlTOPp->CPU__DOT__RegFile_io_rdata1
                                                                   : 
                                                                  ((0U 
                                                                    == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                                    ? vlTOPp->CPU__DOT__RegFile_io_rdata1
                                                                    : 0U)))))))))))))
                                                     : vlTOPp->CPU__DOT___PC_io_in_T_5)))));
    vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_alu_out_REG 
        = vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG;
    if (vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_memWr_out_REG) {
        vlTOPp->CPU__DOT__DataMemory__DOT____Vlvbound1 
            = vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rs2_out_REG;
        if ((0x800U >= (0xfffU & vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG))) {
            __Vdlyvval__CPU__DOT__DataMemory__DOT__Dmemory__v0 
                = vlTOPp->CPU__DOT__DataMemory__DOT____Vlvbound1;
            __Vdlyvset__CPU__DOT__DataMemory__DOT__Dmemory__v0 = 1U;
            __Vdlyvdim0__CPU__DOT__DataMemory__DOT__Dmemory__v0 
                = (0xfffU & vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG);
        }
    }
    vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_dataMem_out_REG 
        = vlTOPp->CPU__DOT__DataMemory_io_dataOut;
    vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_memToReg_out_REG 
        = vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_memToReg_out_REG;
    vlTOPp->CPU__DOT__ID_EX___DOT__io_rs1_out_REG = vlTOPp->CPU__DOT__RegFile_io_rs1;
    vlTOPp->CPU__DOT__ID_EX___DOT__io_rs2_out_REG = vlTOPp->CPU__DOT__RegFile_io_rs2;
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_26 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0x1aU == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_26 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_29 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0x1dU == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_29 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_27 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0x1bU == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_27 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_28 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0x1cU == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_28 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_30 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0x1eU == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_30 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_22 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0x16U == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_22 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_31 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0x1fU == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_31 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_23 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0x17U == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_23 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_24 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0x18U == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_24 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_25 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0x19U == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_25 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_9 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((9U == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_9 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_7 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((7U == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_7 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_11 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0xbU == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_11 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_2 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((2U == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_2 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_10 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0xaU == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_10 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_21 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0x15U == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_21 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_1 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((1U == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_1 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_19 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0x13U == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_19 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_5 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((5U == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_5 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_13 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0xdU == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_13 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_20 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0x14U == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_20 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_6 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((6U == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_6 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_14 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0xeU == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_14 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_8 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((8U == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_8 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_0 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0U == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_0 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_3 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((3U == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_3 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_12 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0xcU == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_12 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_4 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((4U == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_4 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_15 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0xfU == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_15 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_16 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0x10U == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_16 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_17 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0x11U == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_17 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__RegFile__DOT__regfile_18 = 0U;
    } else {
        if (((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
             & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)))) {
            if ((0x12U == (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) {
                vlTOPp->CPU__DOT__RegFile__DOT__regfile_18 
                    = vlTOPp->CPU__DOT__RegFile_io_w_data;
            }
        }
    }
    if (__Vdlyvset__CPU__DOT__DataMemory__DOT__Dmemory__v0) {
        vlTOPp->CPU__DOT__DataMemory__DOT__Dmemory[__Vdlyvdim0__CPU__DOT__DataMemory__DOT__Dmemory__v0] 
            = __Vdlyvval__CPU__DOT__DataMemory__DOT__Dmemory__v0;
    }
    vlTOPp->CPU__DOT__predictor__DOT___T = (3U == (IData)(vlTOPp->CPU__DOT__predictor__DOT__currentState));
    vlTOPp->CPU__DOT__predictor__DOT___T_1 = (2U == (IData)(vlTOPp->CPU__DOT__predictor__DOT__currentState));
    vlTOPp->CPU__DOT__predictor_io_prediction = ((0U 
                                                  == (IData)(vlTOPp->CPU__DOT__predictor__DOT__currentState)) 
                                                 | (1U 
                                                    == (IData)(vlTOPp->CPU__DOT__predictor__DOT__currentState)));
    vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_memRd_out_REG 
        = vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_MemRd_out_REG;
    vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4 = ((0U 
                                                   == (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_AluOp_out_REG))
                                                   ? 
                                                  (((IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_func7_out_REG) 
                                                    << 3U) 
                                                   | (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_func3_out_REG))
                                                   : 
                                                  ((1U 
                                                    == (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_AluOp_out_REG))
                                                    ? (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_func3_out_REG)
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_AluOp_out_REG))
                                                     ? 
                                                    (0x10U 
                                                     | (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_func3_out_REG))
                                                     : 
                                                    ((3U 
                                                      == (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_AluOp_out_REG))
                                                      ? 0x1fU
                                                      : 0U))));
    if (vlTOPp->reset) {
        vlTOPp->CPU__DOT__IF_ID___DOT__S_pc = 0U;
        vlTOPp->CPU__DOT__IF_ID___DOT__Pc4_In = 0U;
    } else {
        vlTOPp->CPU__DOT__IF_ID___DOT__S_pc = ((IData)(vlTOPp->CPU__DOT__HazardDetect_io_pc_forward)
                                                ? vlTOPp->CPU__DOT__btb_io_target
                                                : (
                                                   (1U 
                                                    == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                                    ? 
                                                   (((IData)(vlTOPp->CPU__DOT__Branch_M_io_flush) 
                                                     & (IData)(vlTOPp->CPU__DOT__control_module_io_branch))
                                                     ? 0U
                                                     : vlTOPp->CPU__DOT__btb_io_target)
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                                     ? 0U
                                                     : 
                                                    ((3U 
                                                      == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                                      ? 0U
                                                      : vlTOPp->CPU__DOT__btb_io_target))));
        vlTOPp->CPU__DOT__IF_ID___DOT__Pc4_In = ((IData)(vlTOPp->CPU__DOT__HazardDetect_io_pc_forward)
                                                  ? 
                                                 ((IData)(4U) 
                                                  + vlTOPp->CPU__DOT__PC__DOT__PC)
                                                  : 
                                                 ((1U 
                                                   == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                                   ? 
                                                  (((IData)(vlTOPp->CPU__DOT__Branch_M_io_flush) 
                                                    & (IData)(vlTOPp->CPU__DOT__control_module_io_branch))
                                                    ? 0U
                                                    : 
                                                   ((IData)(4U) 
                                                    + vlTOPp->CPU__DOT__PC__DOT__PC))
                                                   : 
                                                  ((2U 
                                                    == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                                    ? 0U
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                                     ? 0U
                                                     : 
                                                    ((IData)(4U) 
                                                     + vlTOPp->CPU__DOT__PC__DOT__PC)))));
    }
    vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG 
        = (IData)(vlTOPp->CPU__DOT__ALU__DOT___GEN_10);
    vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_memWr_out_REG 
        = vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_MemWr_out_REG;
    vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rs2_out_REG 
        = ((0U == (IData)(vlTOPp->CPU__DOT__Forwarding_io_forward_b))
            ? vlTOPp->CPU__DOT__ID_EX___DOT__io_rs2_data_out_REG
            : vlTOPp->CPU__DOT___GEN_42);
    vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_memToReg_out_REG 
        = vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_MemToReg_out_REG;
    vlTOPp->CPU__DOT___GEN_45 = ((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_memToReg_out_REG)
                                  ? vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_dataMem_out_REG
                                  : 0U);
    vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG 
        = vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_reg_w_out_REG;
    vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG 
        = vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG;
    vlTOPp->CPU__DOT__PC__DOT__PC = __Vdly__CPU__DOT__PC__DOT__PC;
    vlTOPp->CPU__DOT__d = ((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_memToReg_out_REG)
                            ? vlTOPp->CPU__DOT___GEN_45
                            : vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_alu_out_REG);
    vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_MemRd_out_REG 
        = ((~ (IData)(vlTOPp->CPU__DOT__HazardDetect_io_ctrl_forward)) 
           & ((0x33U != (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
              & (IData)(vlTOPp->CPU__DOT__control_module__DOT___GEN_51)));
    vlTOPp->CPU__DOT__DataMemory_io_dataOut = ((IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_memRd_out_REG)
                                                ? (
                                                   (0x800U 
                                                    >= 
                                                    (0xfffU 
                                                     & vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG))
                                                    ? 
                                                   vlTOPp->CPU__DOT__DataMemory__DOT__Dmemory
                                                   [
                                                   (0xfffU 
                                                    & vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG)]
                                                    : 0U)
                                                : 0U);
    vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_MemWr_out_REG 
        = ((~ (IData)(vlTOPp->CPU__DOT__HazardDetect_io_ctrl_forward)) 
           & ((0x33U != (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
              & ((0x13U != (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                 & (0x23U == (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)))));
    vlTOPp->CPU__DOT__ID_EX___DOT__io_rs2_data_out_REG 
        = ((IData)(vlTOPp->CPU__DOT__Structural_io_fwd_rs2)
            ? ((IData)(vlTOPp->CPU__DOT__Structural_io_fwd_rs2)
                ? vlTOPp->CPU__DOT__RegFile_io_w_data
                : 0U) : vlTOPp->CPU__DOT__RegFile_io_rdata2);
    vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_MemToReg_out_REG 
        = ((~ (IData)(vlTOPp->CPU__DOT__HazardDetect_io_ctrl_forward)) 
           & ((0x33U != (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
              & (IData)(vlTOPp->CPU__DOT__control_module__DOT___GEN_51)));
    vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_reg_w_out_REG 
        = vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_Reg_W_out_REG;
    vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG 
        = vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG;
    vlTOPp->CPU__DOT__RegFile_io_w_data = ((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_memToReg_out_REG)
                                            ? vlTOPp->CPU__DOT___GEN_45
                                            : vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_alu_out_REG);
    vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_Reg_W_out_REG 
        = ((~ (IData)(vlTOPp->CPU__DOT__HazardDetect_io_ctrl_forward)) 
           & ((0x33U == (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
              | ((0x13U == (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                 | ((0x23U != (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                    & ((3U == (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                       | ((0x63U != (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                          & ((0x6fU == (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                             | ((0x67U == (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                | (IData)(vlTOPp->CPU__DOT__control_module__DOT___GEN_5)))))))));
    vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG = 
        (0x1fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                  >> 7U));
    vlTOPp->CPU__DOT__Forwarding__DOT___T_11 = (((IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_reg_w_out_REG) 
                                                 & (0U 
                                                    != (IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG))) 
                                                & ((IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
                                                   == (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rs2_out_REG)));
    vlTOPp->CPU__DOT__Forwarding__DOT___T_4 = (((IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_reg_w_out_REG) 
                                                & (0U 
                                                   != (IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG))) 
                                               & ((IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
                                                  == (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rs1_out_REG)));
    vlTOPp->CPU__DOT__Forwarding__DOT___T_44 = ((((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
                                                  & (0U 
                                                     != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) 
                                                 & ((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
                                                    == (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rs2_out_REG))) 
                                                & (~ (IData)(vlTOPp->CPU__DOT__Forwarding__DOT___T_11)));
    vlTOPp->CPU__DOT__Forwarding__DOT___GEN_3 = (((IData)(vlTOPp->CPU__DOT__Forwarding__DOT___T_4) 
                                                  & ((IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
                                                     == (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rs2_out_REG)))
                                                  ? 2U
                                                  : 
                                                 ((IData)(vlTOPp->CPU__DOT__Forwarding__DOT___T_11)
                                                   ? 0U
                                                   : 
                                                  ((IData)(vlTOPp->CPU__DOT__Forwarding__DOT___T_4)
                                                    ? 2U
                                                    : 0U)));
    vlTOPp->CPU__DOT__Forwarding__DOT___T_32 = (((((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
                                                   & (0U 
                                                      != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) 
                                                  & ((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
                                                     == (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rs1_out_REG))) 
                                                 & ((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
                                                    == (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rs2_out_REG))) 
                                                & (~ 
                                                   ((IData)(vlTOPp->CPU__DOT__Forwarding__DOT___T_4) 
                                                    & ((IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
                                                       == (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rs2_out_REG)))));
    vlTOPp->CPU__DOT__IF_ID___DOT__S_instr = ((IData)(vlTOPp->reset)
                                               ? 0U
                                               : ((IData)(vlTOPp->CPU__DOT__HazardDetect_io_pc_forward)
                                                   ? vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data
                                                   : 
                                                  ((1U 
                                                    == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                                    ? 
                                                   (((IData)(vlTOPp->CPU__DOT__Branch_M_io_flush) 
                                                     & (IData)(vlTOPp->CPU__DOT__control_module_io_branch))
                                                     ? 0U
                                                     : vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data)
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                                     ? 0U
                                                     : 
                                                    ((3U 
                                                      == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                                      ? 0U
                                                      : vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data)))));
    if (vlTOPp->CPU__DOT__Forwarding__DOT___T_32) {
        vlTOPp->CPU__DOT__Forwarding_io_forward_a = 1U;
        vlTOPp->CPU__DOT__Forwarding_io_forward_b = 1U;
    } else {
        vlTOPp->CPU__DOT__Forwarding_io_forward_a = 
            ((IData)(vlTOPp->CPU__DOT__Forwarding__DOT___T_44)
              ? (IData)(vlTOPp->CPU__DOT__Forwarding__DOT___GEN_3)
              : (((((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
                    & (0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) 
                   & ((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
                      == (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rs1_out_REG))) 
                  & (~ (IData)(vlTOPp->CPU__DOT__Forwarding__DOT___T_4)))
                  ? 1U : (IData)(vlTOPp->CPU__DOT__Forwarding__DOT___GEN_3)));
        vlTOPp->CPU__DOT__Forwarding_io_forward_b = 
            ((IData)(vlTOPp->CPU__DOT__Forwarding__DOT___T_44)
              ? 1U : (((IData)(vlTOPp->CPU__DOT__Forwarding__DOT___T_4) 
                       & ((IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
                          == (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rs2_out_REG)))
                       ? 2U : ((IData)(vlTOPp->CPU__DOT__Forwarding__DOT___T_11)
                                ? 2U : 0U)));
    }
    vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data 
        = vlTOPp->CPU__DOT__InstMemory__DOT__imem[(0xfffU 
                                                   & (vlTOPp->CPU__DOT__PC__DOT__PC 
                                                      >> 2U))];
    vlTOPp->CPU__DOT__ALU_io_in_A = ((1U == (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_OpA_out_REG))
                                      ? vlTOPp->CPU__DOT__ID_EX___DOT__io_IFID_pc4_out_REG
                                      : ((0U == (IData)(vlTOPp->CPU__DOT__Forwarding_io_forward_a))
                                          ? vlTOPp->CPU__DOT__ID_EX___DOT__io_rs1_data_out_REG
                                          : ((1U == (IData)(vlTOPp->CPU__DOT__Forwarding_io_forward_a))
                                              ? vlTOPp->CPU__DOT__d
                                              : ((2U 
                                                  == (IData)(vlTOPp->CPU__DOT__Forwarding_io_forward_a))
                                                  ? vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG
                                                  : vlTOPp->CPU__DOT__ID_EX___DOT__io_rs1_data_out_REG))));
    vlTOPp->CPU__DOT___GEN_42 = ((1U == (IData)(vlTOPp->CPU__DOT__Forwarding_io_forward_b))
                                  ? vlTOPp->CPU__DOT__d
                                  : ((2U == (IData)(vlTOPp->CPU__DOT__Forwarding_io_forward_b))
                                      ? vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG
                                      : 0U));
    vlTOPp->CPU__DOT__btb_io_target = ((0x63U == (0x7fU 
                                                  & vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data))
                                        ? (vlTOPp->CPU__DOT__PC__DOT__PC 
                                           + ((((0x80000000U 
                                                 & vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data)
                                                 ? 0x7ffffU
                                                 : 0U) 
                                               << 0xdU) 
                                              | ((0x1000U 
                                                  & (vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data 
                                                     >> 0x13U)) 
                                                 | ((0x800U 
                                                     & (vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data 
                                                        << 4U)) 
                                                    | ((0x7e0U 
                                                        & (vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data 
                                                           >> 0x14U)) 
                                                       | (0x1eU 
                                                          & (vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data 
                                                             >> 7U)))))))
                                        : ((IData)(4U) 
                                           + vlTOPp->CPU__DOT__PC__DOT__PC));
    vlTOPp->CPU__DOT__control_module__DOT___GEN_5 = 
        ((0x37U == (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
         | (0x17U == (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)));
    vlTOPp->CPU__DOT__control_module__DOT___GEN_51 
        = ((0x13U != (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
           & ((0x23U != (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
              & (3U == (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))));
    vlTOPp->CPU__DOT__control_module_io_next_pc_sel 
        = ((0x33U == (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
            ? 0U : ((0x13U == (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                     ? 0U : ((0x23U == (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                              ? 0U : ((3U == (0x7fU 
                                              & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                       ? 0U : ((0x63U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                ? 1U
                                                : (
                                                   (0x6fU 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                    ? 2U
                                                    : 
                                                   ((0x67U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                     ? 3U
                                                     : 0U)))))));
    vlTOPp->CPU__DOT__HazardDetect_io_pc_forward = 
        ((IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_MemRd_out_REG) 
         & (((IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG) 
             == (0x1fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                          >> 0xfU))) | ((IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG) 
                                        == (0x1fU & 
                                            (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                             >> 0x14U)))));
    vlTOPp->CPU__DOT__HazardDetect_io_ctrl_forward 
        = ((IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_MemRd_out_REG) 
           & (((IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG) 
               == (0x1fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                            >> 0xfU))) | ((IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG) 
                                          == (0x1fU 
                                              & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                 >> 0x14U)))));
    vlTOPp->CPU__DOT__Structural_io_fwd_rs1 = ((IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_reg_w_out_REG) 
                                               & ((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
                                                  == 
                                                  (0x1fU 
                                                   & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                      >> 0xfU))));
    vlTOPp->CPU__DOT__Structural_io_fwd_rs2 = ((IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_reg_w_out_REG) 
                                               & ((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
                                                  == 
                                                  (0x1fU 
                                                   & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                      >> 0x14U))));
    vlTOPp->CPU__DOT__control_module_io_extend = ((0x33U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                   ? 0U
                                                   : 
                                                  ((0x13U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                    ? 0U
                                                    : 
                                                   ((0x23U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                     ? 1U
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                      ? 0U
                                                      : 
                                                     ((0x63U 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                       ? 0U
                                                       : 
                                                      ((0x6fU 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                        ? 0U
                                                        : 
                                                       ((0x67U 
                                                         == 
                                                         (0x7fU 
                                                          & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                         ? 0U
                                                         : 
                                                        ((0x37U 
                                                          == 
                                                          (0x7fU 
                                                           & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                          ? 2U
                                                          : 
                                                         ((0x17U 
                                                           == 
                                                           (0x7fU 
                                                            & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                           ? 2U
                                                           : 0U)))))))));
    vlTOPp->CPU__DOT__Branch_Forward__DOT___T_37 = 
        ((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
         == (0x1fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                      >> 0xfU)));
    vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_5 = 
        (((0U != (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG)) 
          & (~ (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_MemRd_out_REG))) 
         & ((((IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG) 
              == (0x1fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                           >> 0xfU))) & ((IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG) 
                                         == (0x1fU 
                                             & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                >> 0x14U)))) 
            | ((IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG) 
               == (0x1fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                            >> 0xfU)))));
    vlTOPp->CPU__DOT__control_module_io_branch = ((0x33U 
                                                   != 
                                                   (0x7fU 
                                                    & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                                  & ((0x13U 
                                                      != 
                                                      (0x7fU 
                                                       & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                                     & ((0x23U 
                                                         != 
                                                         (0x7fU 
                                                          & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                                        & ((3U 
                                                            != 
                                                            (0x7fU 
                                                             & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                                           & (0x63U 
                                                              == 
                                                              (0x7fU 
                                                               & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))))));
    vlTOPp->CPU__DOT__RegFile_io_rs2 = ((((0x33U == 
                                           (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                          | (0x23U 
                                             == (0x7fU 
                                                 & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))) 
                                         | (0x63U == 
                                            (0x7fU 
                                             & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)))
                                         ? (0x1fU & 
                                            (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                             >> 0x14U))
                                         : 0U);
    vlTOPp->CPU__DOT__RegFile_io_rs1 = (((((((0x33U 
                                              == (0x7fU 
                                                  & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                             | (0x13U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))) 
                                            | (0x23U 
                                               == (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))) 
                                           | (3U == 
                                              (0x7fU 
                                               & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))) 
                                          | (0x63U 
                                             == (0x7fU 
                                                 & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))) 
                                         | (0x67U == 
                                            (0x7fU 
                                             & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)))
                                         ? (0x1fU & 
                                            (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                             >> 0xfU))
                                         : 0U);
    vlTOPp->CPU__DOT__Branch_Forward__DOT___T_13 = 
        ((IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
         == (0x1fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                      >> 0x14U)));
    vlTOPp->CPU__DOT__Branch_Forward__DOT___T_12 = 
        ((IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
         == (0x1fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                      >> 0xfU)));
    vlTOPp->CPU__DOT__Branch_Forward__DOT___T_5 = ((IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG) 
                                                   == 
                                                   (0x1fU 
                                                    & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                       >> 0x14U)));
    vlTOPp->CPU__DOT__Branch_Forward__DOT___T_4 = ((IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG) 
                                                   == 
                                                   (0x1fU 
                                                    & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                       >> 0xfU)));
    vlTOPp->CPU__DOT__ALU_io_in_B = ((IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_OpB_out_REG)
                                      ? vlTOPp->CPU__DOT__ID_EX___DOT__io_imm_out_REG
                                      : ((0U == (IData)(vlTOPp->CPU__DOT__Forwarding_io_forward_b))
                                          ? vlTOPp->CPU__DOT__ID_EX___DOT__io_rs2_data_out_REG
                                          : vlTOPp->CPU__DOT___GEN_42));
    vlTOPp->CPU__DOT___PC_io_in_T_5 = ((0x63U == (0x7fU 
                                                  & vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data))
                                        ? ((IData)(vlTOPp->CPU__DOT__predictor_io_prediction)
                                            ? vlTOPp->CPU__DOT__btb_io_target
                                            : ((IData)(4U) 
                                               + vlTOPp->CPU__DOT__PC__DOT__PC))
                                        : ((IData)(4U) 
                                           + vlTOPp->CPU__DOT__PC__DOT__PC));
    vlTOPp->CPU__DOT___ImmValue_T_3 = ((1U == (IData)(vlTOPp->CPU__DOT__control_module_io_extend))
                                        ? ((((0x80000000U 
                                              & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                              ? 0xfffffU
                                              : 0U) 
                                            << 0xcU) 
                                           | ((0xfe0U 
                                               & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                    >> 7U))))
                                        : ((0U == (IData)(vlTOPp->CPU__DOT__control_module_io_extend))
                                            ? ((((0x80000000U 
                                                  & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                                  ? 0xfffffU
                                                  : 0U) 
                                                << 0xcU) 
                                               | (0xfffU 
                                                  & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                     >> 0x14U)))
                                            : 0U));
    vlTOPp->CPU__DOT__RegFile__DOT___GEN_53 = ((0x15U 
                                                == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_21
                                                : (
                                                   (0x14U 
                                                    == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                    ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_20
                                                    : 
                                                   ((0x13U 
                                                     == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                     ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_19
                                                     : 
                                                    ((0x12U 
                                                      == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                      ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_18
                                                      : 
                                                     ((0x11U 
                                                       == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                       ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_17
                                                       : 
                                                      ((0x10U 
                                                        == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                        ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_16
                                                        : 
                                                       ((0xfU 
                                                         == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                         ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_15
                                                         : 
                                                        ((0xeU 
                                                          == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                          ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_14
                                                          : 
                                                         ((0xdU 
                                                           == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                           ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_13
                                                           : 
                                                          ((0xcU 
                                                            == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                            ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_12
                                                            : 
                                                           ((0xbU 
                                                             == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                             ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_11
                                                             : 
                                                            ((0xaU 
                                                              == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                              ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_10
                                                              : 
                                                             ((9U 
                                                               == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                               ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_9
                                                               : 
                                                              ((8U 
                                                                == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                                ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_8
                                                                : 
                                                               ((7U 
                                                                 == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                                 ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_7
                                                                 : 
                                                                ((6U 
                                                                  == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                                  ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_6
                                                                  : 
                                                                 ((5U 
                                                                   == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                                   ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_5
                                                                   : 
                                                                  ((4U 
                                                                    == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                                    ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_4
                                                                    : 
                                                                   ((3U 
                                                                     == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                                     ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_3
                                                                     : 
                                                                    ((2U 
                                                                      == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                                      ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_2
                                                                      : 
                                                                     ((1U 
                                                                       == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                                       ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_1
                                                                       : vlTOPp->CPU__DOT__RegFile__DOT__regfile_0)))))))))))))))))))));
    vlTOPp->CPU__DOT__RegFile__DOT___GEN_21 = ((0x15U 
                                                == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_21
                                                : (
                                                   (0x14U 
                                                    == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                    ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_20
                                                    : 
                                                   ((0x13U 
                                                     == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                     ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_19
                                                     : 
                                                    ((0x12U 
                                                      == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                      ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_18
                                                      : 
                                                     ((0x11U 
                                                       == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                       ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_17
                                                       : 
                                                      ((0x10U 
                                                        == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                        ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_16
                                                        : 
                                                       ((0xfU 
                                                         == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                         ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_15
                                                         : 
                                                        ((0xeU 
                                                          == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                          ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_14
                                                          : 
                                                         ((0xdU 
                                                           == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                           ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_13
                                                           : 
                                                          ((0xcU 
                                                            == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                            ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_12
                                                            : 
                                                           ((0xbU 
                                                             == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                             ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_11
                                                             : 
                                                            ((0xaU 
                                                              == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                              ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_10
                                                              : 
                                                             ((9U 
                                                               == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                               ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_9
                                                               : 
                                                              ((8U 
                                                                == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                                ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_8
                                                                : 
                                                               ((7U 
                                                                 == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                                 ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_7
                                                                 : 
                                                                ((6U 
                                                                  == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                                  ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_6
                                                                  : 
                                                                 ((5U 
                                                                   == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                                   ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_5
                                                                   : 
                                                                  ((4U 
                                                                    == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                                    ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_4
                                                                    : 
                                                                   ((3U 
                                                                     == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                                     ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_3
                                                                     : 
                                                                    ((2U 
                                                                      == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                                      ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_2
                                                                      : 
                                                                     ((1U 
                                                                       == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                                       ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_1
                                                                       : vlTOPp->CPU__DOT__RegFile__DOT__regfile_0)))))))))))))))))))));
    vlTOPp->CPU__DOT__Branch_Forward__DOT___T_49 = 
        ((0U != (IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG)) 
         & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_12));
    vlTOPp->CPU__DOT__Branch_Forward__DOT___T_20 = 
        (1U & (~ (((0U != (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG)) 
                   & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_4)) 
                  & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_5))));
    vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_6 = 
        (((0U != (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG)) 
          & (~ (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_MemRd_out_REG))) 
         & ((((IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG) 
              == (0x1fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                           >> 0xfU))) & ((IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG) 
                                         == (0x1fU 
                                             & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                >> 0x14U)))) 
            | ((~ (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_4)) 
               & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_5))));
    vlTOPp->CPU__DOT__Branch_Forward__DOT___T_17 = 
        ((0U != (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG)) 
         & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_4));
    vlTOPp->CPU__DOT__ALU__DOT___result_T_2 = (vlTOPp->CPU__DOT__ALU_io_in_A 
                                               + vlTOPp->CPU__DOT__ALU_io_in_B);
    vlTOPp->CPU__DOT__ALU__DOT___result_T_8 = (VL_LTS_III(1,32,32, vlTOPp->CPU__DOT__ALU_io_in_A, vlTOPp->CPU__DOT__ALU_io_in_B)
                                                ? 1U
                                                : 0U);
    vlTOPp->CPU__DOT__ALU__DOT___result_T_12 = ((vlTOPp->CPU__DOT__ALU_io_in_A 
                                                 < vlTOPp->CPU__DOT__ALU_io_in_B)
                                                 ? 1U
                                                 : 0U);
    vlTOPp->CPU__DOT__ALU__DOT___GEN_6 = (((4U == (0x1fU 
                                                   & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))) 
                                           | (4U == 
                                              (0x1fU 
                                               & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))))
                                           ? (vlTOPp->CPU__DOT__ALU_io_in_A 
                                              ^ vlTOPp->CPU__DOT__ALU_io_in_B)
                                           : (((5U 
                                                == 
                                                (0x1fU 
                                                 & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))) 
                                               | (5U 
                                                  == 
                                                  (0x1fU 
                                                   & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))))
                                               ? (vlTOPp->CPU__DOT__ALU_io_in_A 
                                                  >> 
                                                  (0x1fU 
                                                   & vlTOPp->CPU__DOT__ALU_io_in_B))
                                               : ((
                                                   (6U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))) 
                                                   | (6U 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))))
                                                   ? 
                                                  (vlTOPp->CPU__DOT__ALU_io_in_A 
                                                   | vlTOPp->CPU__DOT__ALU_io_in_B)
                                                   : 
                                                  (((7U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))) 
                                                    | (7U 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))))
                                                    ? 
                                                   (vlTOPp->CPU__DOT__ALU_io_in_A 
                                                    & vlTOPp->CPU__DOT__ALU_io_in_B)
                                                    : 
                                                   ((8U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4)))
                                                     ? 
                                                    (vlTOPp->CPU__DOT__ALU_io_in_A 
                                                     - vlTOPp->CPU__DOT__ALU_io_in_B)
                                                     : 
                                                    (((0xdU 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))) 
                                                      | (0xdU 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))))
                                                      ? 
                                                     VL_SHIFTRS_III(32,32,5, vlTOPp->CPU__DOT__ALU_io_in_A, 
                                                                    (0x1fU 
                                                                     & vlTOPp->CPU__DOT__ALU_io_in_B))
                                                      : 
                                                     (((0x1fU 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))) 
                                                       | (0x1fU 
                                                          == 
                                                          (0x1fU 
                                                           & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))))
                                                       ? vlTOPp->CPU__DOT__ALU_io_in_A
                                                       : 0U)))))));
    vlTOPp->CPU__DOT__RegFile_io_rdata2 = ((0U == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                            ? 0U : 
                                           ((0x1fU 
                                             == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                             ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_31
                                             : ((0x1eU 
                                                 == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                 ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_30
                                                 : 
                                                ((0x1dU 
                                                  == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                  ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_29
                                                  : 
                                                 ((0x1cU 
                                                   == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                   ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_28
                                                   : 
                                                  ((0x1bU 
                                                    == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                    ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_27
                                                    : 
                                                   ((0x1aU 
                                                     == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                     ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_26
                                                     : 
                                                    ((0x19U 
                                                      == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                      ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_25
                                                      : 
                                                     ((0x18U 
                                                       == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                       ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_24
                                                       : 
                                                      ((0x17U 
                                                        == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                        ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_23
                                                        : 
                                                       ((0x16U 
                                                         == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs2))
                                                         ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_22
                                                         : vlTOPp->CPU__DOT__RegFile__DOT___GEN_53)))))))))));
    vlTOPp->CPU__DOT__RegFile_io_rdata1 = ((0U == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                            ? 0U : 
                                           ((0x1fU 
                                             == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                             ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_31
                                             : ((0x1eU 
                                                 == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                 ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_30
                                                 : 
                                                ((0x1dU 
                                                  == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                  ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_29
                                                  : 
                                                 ((0x1cU 
                                                   == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                   ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_28
                                                   : 
                                                  ((0x1bU 
                                                    == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                    ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_27
                                                    : 
                                                   ((0x1aU 
                                                     == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                     ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_26
                                                     : 
                                                    ((0x19U 
                                                      == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                      ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_25
                                                      : 
                                                     ((0x18U 
                                                       == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                       ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_24
                                                       : 
                                                      ((0x17U 
                                                        == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                        ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_23
                                                        : 
                                                       ((0x16U 
                                                         == (IData)(vlTOPp->CPU__DOT__RegFile_io_rs1))
                                                         ? vlTOPp->CPU__DOT__RegFile__DOT__regfile_22
                                                         : vlTOPp->CPU__DOT__RegFile__DOT___GEN_21)))))))))));
    if (((0U != (IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG)) 
         & (~ (IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_memRd_out_REG)))) {
        vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_13 
            = (((((IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
                  == (0x1fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                               >> 0xfU))) & ((IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
                                             == (0x1fU 
                                                 & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                    >> 0x14U)))) 
                & (~ (((0U != (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG)) 
                       & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_4)) 
                      & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_5))))
                ? 2U : (((IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_12) 
                         & (~ (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_17)))
                         ? (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_6)
                         : (((IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_13) 
                             & (~ ((0U != (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG)) 
                                   & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_5))))
                             ? 2U : (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_6))));
        vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_12 
            = (((((IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
                  == (0x1fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                               >> 0xfU))) & ((IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
                                             == (0x1fU 
                                                 & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                    >> 0x14U)))) 
                & (~ (((0U != (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG)) 
                       & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_4)) 
                      & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_5))))
                ? 2U : (((IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_12) 
                         & (~ (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_17)))
                         ? 2U : (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_5)));
    } else {
        vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_13 
            = vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_6;
        vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_12 
            = vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_5;
    }
    vlTOPp->CPU__DOT__ALU__DOT___GEN_8 = (((2U == (0x1fU 
                                                   & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))) 
                                           | (2U == 
                                              (0x1fU 
                                               & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))))
                                           ? ((0xfffffffcU 
                                               & ((- (IData)(
                                                             (1U 
                                                              & ((IData)(vlTOPp->CPU__DOT__ALU__DOT___result_T_8) 
                                                                 >> 1U)))) 
                                                  << 2U)) 
                                              | (IData)(vlTOPp->CPU__DOT__ALU__DOT___result_T_8))
                                           : (((3U 
                                                == 
                                                (0x1fU 
                                                 & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))) 
                                               | (3U 
                                                  == 
                                                  (0x1fU 
                                                   & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))))
                                               ? ((0xfffffffcU 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & ((IData)(vlTOPp->CPU__DOT__ALU__DOT___result_T_12) 
                                                                     >> 1U)))) 
                                                      << 2U)) 
                                                  | (IData)(vlTOPp->CPU__DOT__ALU__DOT___result_T_12))
                                               : vlTOPp->CPU__DOT__ALU__DOT___GEN_6));
    if (vlTOPp->CPU__DOT__control_module_io_branch) {
        vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_28 
            = (((0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)) 
                & (~ (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_memRd_out_REG)))
                ? ((((((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
                       == (0x1fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                    >> 0xfU))) & ((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
                                                  == 
                                                  (0x1fU 
                                                   & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                      >> 0x14U)))) 
                     & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_20)) 
                    & (~ (((0U != (IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG)) 
                           & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_12)) 
                          & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_13))))
                    ? 3U : ((((IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_37) 
                              & (~ (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_17))) 
                             & (~ (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_49)))
                             ? (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_13)
                             : (((((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
                                   == (0x1fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                >> 0x14U))) 
                                  & (~ ((0U != (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG)) 
                                        & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_5)))) 
                                 & (~ ((0U != (IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG)) 
                                       & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_13))))
                                 ? 3U : (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_13))))
                : (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_13));
        vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1 
            = (((0U != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)) 
                & (~ (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_memRd_out_REG)))
                ? ((((((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
                       == (0x1fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                    >> 0xfU))) & ((IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
                                                  == 
                                                  (0x1fU 
                                                   & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                      >> 0x14U)))) 
                     & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_20)) 
                    & (~ (((0U != (IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG)) 
                           & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_12)) 
                          & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_13))))
                    ? 3U : ((((IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_37) 
                              & (~ (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_17))) 
                             & (~ (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_49)))
                             ? 3U : (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_12)))
                : (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_12));
    } else {
        vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_28 = 0U;
        vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1 
            = ((IData)(vlTOPp->CPU__DOT__control_module_io_branch)
                ? 0U : ((((0U != (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG)) 
                          & (~ (IData)(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_MemRd_out_REG))) 
                         & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_4))
                         ? 6U : (((((0U != (IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG)) 
                                    & (~ (IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_memRd_out_REG))) 
                                   & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_12)) 
                                  & (~ (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_17)))
                                  ? 7U : (((((0U != (IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG)) 
                                             & (IData)(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_memRd_out_REG)) 
                                            & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_12)) 
                                           & (~ (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_17)))
                                           ? 9U : (
                                                   (((((0U 
                                                        != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)) 
                                                       & (~ (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_memRd_out_REG))) 
                                                      & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_37)) 
                                                     & (~ (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_17))) 
                                                    & (~ (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_49)))
                                                    ? 8U
                                                    : 
                                                   ((((((0U 
                                                         != (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)) 
                                                        & (IData)(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_memRd_out_REG)) 
                                                       & (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_37)) 
                                                      & (~ (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_17))) 
                                                     & (~ (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___T_49)))
                                                     ? 0xaU
                                                     : 0U))))));
    }
    vlTOPp->CPU__DOT__ALU__DOT___GEN_10 = (0x7fffffffffffffffULL 
                                           & (((((((0U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))) 
                                                   | (0U 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4)))) 
                                                  | (0U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4)))) 
                                                 | (0U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4)))) 
                                                | (0U 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4)))) 
                                               | (0U 
                                                  == 
                                                  (0x1fU 
                                                   & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))))
                                               ? (((QData)((IData)(
                                                                   (0x7fffffffU 
                                                                    & (- (IData)(
                                                                                (1U 
                                                                                & (vlTOPp->CPU__DOT__ALU__DOT___result_T_2 
                                                                                >> 0x1fU))))))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(vlTOPp->CPU__DOT__ALU__DOT___result_T_2)))
                                               : ((
                                                   (1U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))) 
                                                   | (1U 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))))
                                                   ? 
                                                  ((QData)((IData)(vlTOPp->CPU__DOT__ALU_io_in_A)) 
                                                   << 
                                                   (0x1fU 
                                                    & vlTOPp->CPU__DOT__ALU_io_in_B))
                                                   : 
                                                  (((QData)((IData)(
                                                                    (0x7fffffffU 
                                                                     & (- (IData)(
                                                                                (1U 
                                                                                & (vlTOPp->CPU__DOT__ALU__DOT___GEN_8 
                                                                                >> 0x1fU))))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlTOPp->CPU__DOT__ALU__DOT___GEN_8))))));
    vlTOPp->CPU__DOT___Branch_M_io_arg_y_T_7 = ((3U 
                                                 == (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_28))
                                                 ? vlTOPp->CPU__DOT__RegFile_io_w_data
                                                 : 
                                                ((2U 
                                                  == (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_28))
                                                  ? vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG
                                                  : 
                                                 ((1U 
                                                   == (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_28))
                                                   ? (IData)(vlTOPp->CPU__DOT__ALU__DOT___GEN_10)
                                                   : 
                                                  ((0U 
                                                    == (IData)(vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_28))
                                                    ? vlTOPp->CPU__DOT__RegFile_io_rdata2
                                                    : 0U))));
    vlTOPp->CPU__DOT__Branch_M_io_arg_x = ((0xaU == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                            ? vlTOPp->CPU__DOT__RegFile_io_rdata1
                                            : ((9U 
                                                == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                ? vlTOPp->CPU__DOT__RegFile_io_rdata1
                                                : (
                                                   (8U 
                                                    == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                    ? vlTOPp->CPU__DOT__RegFile_io_rdata1
                                                    : 
                                                   ((7U 
                                                     == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                     ? vlTOPp->CPU__DOT__RegFile_io_rdata1
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                      ? vlTOPp->CPU__DOT__RegFile_io_rdata1
                                                      : 
                                                     ((5U 
                                                       == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                       ? vlTOPp->CPU__DOT__RegFile_io_w_data
                                                       : 
                                                      ((4U 
                                                        == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                        ? vlTOPp->CPU__DOT__DataMemory_io_dataOut
                                                        : 
                                                       ((3U 
                                                         == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                         ? vlTOPp->CPU__DOT__RegFile_io_w_data
                                                         : 
                                                        ((2U 
                                                          == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                          ? vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG
                                                          : 
                                                         ((1U 
                                                           == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                           ? (IData)(vlTOPp->CPU__DOT__ALU__DOT___GEN_10)
                                                           : 
                                                          ((0U 
                                                            == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                            ? vlTOPp->CPU__DOT__RegFile_io_rdata1
                                                            : 0U)))))))))));
    vlTOPp->CPU__DOT__Branch_M_io_actual = ((IData)(vlTOPp->CPU__DOT__control_module_io_branch) 
                                            & ((7U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                    >> 0xcU)))
                                                ? (vlTOPp->CPU__DOT__Branch_M_io_arg_x 
                                                   >= vlTOPp->CPU__DOT___Branch_M_io_arg_y_T_7)
                                                : (
                                                   (6U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                        >> 0xcU)))
                                                    ? 
                                                   (vlTOPp->CPU__DOT__Branch_M_io_arg_x 
                                                    < vlTOPp->CPU__DOT___Branch_M_io_arg_y_T_7)
                                                    : 
                                                   ((5U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                         >> 0xcU)))
                                                     ? 
                                                    VL_GTES_III(1,32,32, vlTOPp->CPU__DOT__Branch_M_io_arg_x, vlTOPp->CPU__DOT___Branch_M_io_arg_y_T_7)
                                                     : 
                                                    ((4U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                          >> 0xcU)))
                                                      ? 
                                                     VL_LTS_III(1,32,32, vlTOPp->CPU__DOT__Branch_M_io_arg_x, vlTOPp->CPU__DOT___Branch_M_io_arg_y_T_7)
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                           >> 0xcU)))
                                                       ? 
                                                      (vlTOPp->CPU__DOT__Branch_M_io_arg_x 
                                                       != vlTOPp->CPU__DOT___Branch_M_io_arg_y_T_7)
                                                       : 
                                                      ((0U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                            >> 0xcU))) 
                                                       & (vlTOPp->CPU__DOT__Branch_M_io_arg_x 
                                                          == vlTOPp->CPU__DOT___Branch_M_io_arg_y_T_7))))))));
    vlTOPp->CPU__DOT__predictor__DOT___GEN_1 = ((1U 
                                                 == (IData)(vlTOPp->CPU__DOT__predictor__DOT__currentState))
                                                 ? 
                                                ((IData)(vlTOPp->CPU__DOT__Branch_M_io_actual)
                                                  ? 0U
                                                  : 2U)
                                                 : 
                                                ((0U 
                                                  == (IData)(vlTOPp->CPU__DOT__predictor__DOT__currentState))
                                                  ? 
                                                 ((IData)(vlTOPp->CPU__DOT__Branch_M_io_actual)
                                                   ? 0U
                                                   : 1U)
                                                  : (IData)(vlTOPp->CPU__DOT__predictor__DOT__currentState)));
    vlTOPp->CPU__DOT__Branch_M_io_flush = ((IData)(vlTOPp->CPU__DOT__IF_ID___DOT__io_pred_out_REG) 
                                           ^ (IData)(vlTOPp->CPU__DOT__Branch_M_io_actual));
}

void VCPU::_eval(VCPU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU::_eval\n"); );
    VCPU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

VL_INLINE_OPT QData VCPU::_change_request(VCPU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU::_change_request\n"); );
    VCPU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VCPU::_change_request_1(VCPU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU::_change_request_1\n"); );
    VCPU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VCPU::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
