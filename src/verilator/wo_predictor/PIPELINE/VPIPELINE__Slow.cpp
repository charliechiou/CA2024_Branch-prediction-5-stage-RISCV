// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPIPELINE.h for the primary calling header

#include "VPIPELINE.h"
#include "VPIPELINE__Syms.h"

//==========

VL_CTOR_IMP(VPIPELINE) {
    VPIPELINE__Syms* __restrict vlSymsp = __VlSymsp = new VPIPELINE__Syms(this, name());
    VPIPELINE* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VPIPELINE::__Vconfigure(VPIPELINE__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VPIPELINE::~VPIPELINE() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VPIPELINE::_initial__TOP__1(VPIPELINE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPIPELINE::_initial__TOP__1\n"); );
    VPIPELINE* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*287:0*/ __Vtemp1[9];
    // Body
    vlTOPp->io_out = 0U;
    __Vtemp1[0U] = 0x2e686578U;
    __Vtemp1[1U] = 0x74707574U;
    __Vtemp1[2U] = 0x742f6f75U;
    __Vtemp1[3U] = 0x2f746573U;
    __Vtemp1[4U] = 0x5f637075U;
    __Vtemp1[5U] = 0x732f6d79U;
    __Vtemp1[6U] = 0x6a616d65U;
    __Vtemp1[7U] = 0x6f6d652fU;
    __Vtemp1[8U] = 0x2f68U;
    VL_READMEM_N(true, 32, 4096, 0, VL_CVT_PACK_STR_NW(9, __Vtemp1)
                 , vlTOPp->PIPELINE__DOT__InstMemory__DOT__imem
                 , 0, ~0ULL);
}

void VPIPELINE::_settle__TOP__3(VPIPELINE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPIPELINE::_settle__TOP__3\n"); );
    VPIPELINE* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4 
        = ((0U == (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_AluOp_out_REG))
            ? (((IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_func7_out_REG) 
                << 3U) | (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_func3_out_REG))
            : ((1U == (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_AluOp_out_REG))
                ? (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_func3_out_REG)
                : ((2U == (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_AluOp_out_REG))
                    ? (0x10U | (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_func3_out_REG))
                    : ((3U == (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_AluOp_out_REG))
                        ? 0x1fU : 0U))));
    vlTOPp->PIPELINE__DOT___GEN_45 = ((IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_memToReg_out_REG)
                                       ? vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_dataMem_out_REG
                                       : 0U);
    vlTOPp->PIPELINE__DOT__DataMemory_io_dataOut = 
        ((IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_memRd_out_REG)
          ? vlTOPp->PIPELINE__DOT__DataMemory__DOT__Dmemory
         [(0x3ffU & vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG)]
          : 0U);
    vlTOPp->PIPELINE__DOT__Forwarding__DOT___T_11 = 
        (((IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_reg_w_out_REG) 
          & (0U != (IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG))) 
         & ((IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
            == (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs2_out_REG)));
    vlTOPp->PIPELINE__DOT__Forwarding__DOT___T_4 = 
        (((IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_reg_w_out_REG) 
          & (0U != (IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG))) 
         & ((IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
            == (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs1_out_REG)));
    vlTOPp->PIPELINE__DOT__control_module__DOT___GEN_5 
        = ((0x37U == (0x7fU & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
           | (0x17U == (0x7fU & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)));
    vlTOPp->PIPELINE__DOT__control_module__DOT___GEN_51 
        = ((0x13U != (0x7fU & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
           & ((0x23U != (0x7fU & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
              & (3U == (0x7fU & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))));
    vlTOPp->PIPELINE__DOT__HazardDetect_io_ctrl_forward 
        = ((IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_MemRd_out_REG) 
           & (((IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG) 
               == (0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                            >> 0xfU))) | ((IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG) 
                                          == (0x1fU 
                                              & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                 >> 0x14U)))));
    vlTOPp->PIPELINE__DOT__Structural_io_fwd_rs1 = 
        ((IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_reg_w_out_REG) 
         & ((IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
            == (0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                         >> 0xfU))));
    vlTOPp->PIPELINE__DOT__Structural_io_fwd_rs2 = 
        ((IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_reg_w_out_REG) 
         & ((IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
            == (0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                         >> 0x14U))));
    vlTOPp->PIPELINE__DOT__HazardDetect_io_inst_forward 
        = ((IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_MemRd_out_REG) 
           & (((IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG) 
               == (0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                            >> 0xfU))) | ((IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG) 
                                          == (0x1fU 
                                              & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                 >> 0x14U)))));
    vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel 
        = ((0x33U == (0x7fU & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
            ? 0U : ((0x13U == (0x7fU & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                     ? 0U : ((0x23U == (0x7fU & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                              ? 0U : ((3U == (0x7fU 
                                              & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                       ? 0U : ((0x63U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                ? 1U
                                                : (
                                                   (0x6fU 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                    ? 2U
                                                    : 
                                                   ((0x67U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                     ? 3U
                                                     : 0U)))))));
    vlTOPp->PIPELINE__DOT__HazardDetect_io_pc_forward 
        = ((IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_MemRd_out_REG) 
           & (((IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG) 
               == (0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                            >> 0xfU))) | ((IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG) 
                                          == (0x1fU 
                                              & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                 >> 0x14U)))));
    vlTOPp->PIPELINE__DOT__control_module_io_extend 
        = ((0x33U == (0x7fU & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
            ? 0U : ((0x13U == (0x7fU & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                     ? 0U : ((0x23U == (0x7fU & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                              ? 1U : ((3U == (0x7fU 
                                              & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                       ? 0U : ((0x63U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                ? 0U
                                                : (
                                                   (0x6fU 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                    ? 0U
                                                    : 
                                                   ((0x67U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                     ? 0U
                                                     : 
                                                    ((0x37U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                      ? 2U
                                                      : 
                                                     ((0x17U 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                       ? 2U
                                                       : 0U)))))))));
    vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_37 
        = ((IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
           == (0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                        >> 0xfU)));
    vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_5 
        = (((0U != (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG)) 
            & (~ (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_MemRd_out_REG))) 
           & ((((IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG) 
                == (0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                             >> 0xfU))) & ((IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG) 
                                           == (0x1fU 
                                               & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                  >> 0x14U)))) 
              | ((IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG) 
                 == (0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                              >> 0xfU)))));
    vlTOPp->PIPELINE__DOT__control_module_io_branch 
        = ((0x33U != (0x7fU & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
           & ((0x13U != (0x7fU & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
              & ((0x23U != (0x7fU & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                 & ((3U != (0x7fU & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                    & (0x63U == (0x7fU & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))))));
    vlTOPp->PIPELINE__DOT__RegFile_io_rs2 = ((((0x33U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                               | (0x23U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))) 
                                              | (0x63U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)))
                                              ? (0x1fU 
                                                 & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                    >> 0x14U))
                                              : 0U);
    vlTOPp->PIPELINE__DOT__RegFile_io_rs1 = (((((((0x33U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                                  | (0x13U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))) 
                                                 | (0x23U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))) 
                                                | (3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))) 
                                               | (0x63U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))) 
                                              | (0x67U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)))
                                              ? (0x1fU 
                                                 & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                    >> 0xfU))
                                              : 0U);
    vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_13 
        = ((IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
           == (0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                        >> 0x14U)));
    vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_12 
        = ((IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
           == (0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                        >> 0xfU)));
    vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_5 
        = ((IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG) 
           == (0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                        >> 0x14U)));
    vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_4 
        = ((IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG) 
           == (0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                        >> 0xfU)));
    if (vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_memToReg_out_REG) {
        vlTOPp->PIPELINE__DOT__d = vlTOPp->PIPELINE__DOT___GEN_45;
        vlTOPp->PIPELINE__DOT__RegFile_io_w_data = vlTOPp->PIPELINE__DOT___GEN_45;
    } else {
        vlTOPp->PIPELINE__DOT__d = vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_alu_out_REG;
        vlTOPp->PIPELINE__DOT__RegFile_io_w_data = vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_alu_out_REG;
    }
    vlTOPp->PIPELINE__DOT__Forwarding__DOT___T_44 = 
        ((((IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
           & (0U != (IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) 
          & ((IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
             == (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs2_out_REG))) 
         & (~ (IData)(vlTOPp->PIPELINE__DOT__Forwarding__DOT___T_11)));
    vlTOPp->PIPELINE__DOT__Forwarding__DOT___GEN_3 
        = (((IData)(vlTOPp->PIPELINE__DOT__Forwarding__DOT___T_4) 
            & ((IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
               == (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs2_out_REG)))
            ? 2U : ((IData)(vlTOPp->PIPELINE__DOT__Forwarding__DOT___T_11)
                     ? 0U : ((IData)(vlTOPp->PIPELINE__DOT__Forwarding__DOT___T_4)
                              ? 2U : 0U)));
    vlTOPp->PIPELINE__DOT__Forwarding__DOT___T_32 = 
        (((((IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
            & (0U != (IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) 
           & ((IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
              == (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs1_out_REG))) 
          & ((IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
             == (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs2_out_REG))) 
         & (~ ((IData)(vlTOPp->PIPELINE__DOT__Forwarding__DOT___T_4) 
               & ((IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
                  == (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs2_out_REG)))));
    if (vlTOPp->PIPELINE__DOT__HazardDetect_io_inst_forward) {
        vlTOPp->PIPELINE__DOT__PC_for = vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_pc;
        vlTOPp->PIPELINE__DOT__Instruction_F = vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr;
    } else {
        vlTOPp->PIPELINE__DOT__PC_for = vlTOPp->PIPELINE__DOT__PC__DOT__PC;
        vlTOPp->PIPELINE__DOT__Instruction_F = vlTOPp->PIPELINE__DOT__InstMemory__DOT__imem
            [(0xfffU & (vlTOPp->PIPELINE__DOT__PC__DOT__PC 
                        >> 2U))];
    }
    vlTOPp->PIPELINE__DOT___ImmValue_T_3 = ((1U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_extend))
                                             ? ((((0x80000000U 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                                   ? 0xfffffU
                                                   : 0U) 
                                                 << 0xcU) 
                                                | ((0xfe0U 
                                                    & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                         >> 7U))))
                                             : ((0U 
                                                 == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_extend))
                                                 ? 
                                                ((((0x80000000U 
                                                    & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                                    ? 0xfffffU
                                                    : 0U) 
                                                  << 0xcU) 
                                                 | (0xfffU 
                                                    & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                       >> 0x14U)))
                                                 : 0U));
    vlTOPp->PIPELINE__DOT__RegFile__DOT___GEN_53 = 
        ((0x15U == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
          ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_21
          : ((0x14U == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
              ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_20
              : ((0x13U == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                  ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_19
                  : ((0x12U == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                      ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_18
                      : ((0x11U == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                          ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_17
                          : ((0x10U == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                              ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_16
                              : ((0xfU == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                  ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_15
                                  : ((0xeU == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                      ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_14
                                      : ((0xdU == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                          ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_13
                                          : ((0xcU 
                                              == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                              ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_12
                                              : ((0xbU 
                                                  == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                  ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_11
                                                  : 
                                                 ((0xaU 
                                                   == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                   ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_10
                                                   : 
                                                  ((9U 
                                                    == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                    ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_9
                                                    : 
                                                   ((8U 
                                                     == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                     ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_8
                                                     : 
                                                    ((7U 
                                                      == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                      ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_7
                                                      : 
                                                     ((6U 
                                                       == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                       ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_6
                                                       : 
                                                      ((5U 
                                                        == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                        ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_5
                                                        : 
                                                       ((4U 
                                                         == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                         ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_4
                                                         : 
                                                        ((3U 
                                                          == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                          ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_3
                                                          : 
                                                         ((2U 
                                                           == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                           ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_2
                                                           : 
                                                          ((1U 
                                                            == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                            ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_1
                                                            : vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_0)))))))))))))))))))));
    vlTOPp->PIPELINE__DOT__RegFile__DOT___GEN_21 = 
        ((0x15U == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
          ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_21
          : ((0x14U == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
              ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_20
              : ((0x13U == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                  ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_19
                  : ((0x12U == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                      ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_18
                      : ((0x11U == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                          ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_17
                          : ((0x10U == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                              ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_16
                              : ((0xfU == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                  ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_15
                                  : ((0xeU == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                      ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_14
                                      : ((0xdU == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                          ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_13
                                          : ((0xcU 
                                              == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                              ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_12
                                              : ((0xbU 
                                                  == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                  ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_11
                                                  : 
                                                 ((0xaU 
                                                   == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                   ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_10
                                                   : 
                                                  ((9U 
                                                    == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                    ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_9
                                                    : 
                                                   ((8U 
                                                     == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                     ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_8
                                                     : 
                                                    ((7U 
                                                      == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                      ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_7
                                                      : 
                                                     ((6U 
                                                       == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                       ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_6
                                                       : 
                                                      ((5U 
                                                        == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                        ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_5
                                                        : 
                                                       ((4U 
                                                         == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                         ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_4
                                                         : 
                                                        ((3U 
                                                          == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                          ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_3
                                                          : 
                                                         ((2U 
                                                           == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                           ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_2
                                                           : 
                                                          ((1U 
                                                            == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                            ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_1
                                                            : vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_0)))))))))))))))))))));
    vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_49 
        = ((0U != (IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG)) 
           & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_12));
    vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_6 
        = (((0U != (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG)) 
            & (~ (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_MemRd_out_REG))) 
           & ((((IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG) 
                == (0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                             >> 0xfU))) & ((IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG) 
                                           == (0x1fU 
                                               & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                  >> 0x14U)))) 
              | ((~ (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_4)) 
                 & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_5))));
    vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_20 
        = (1U & (~ (((0U != (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG)) 
                     & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_4)) 
                    & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_5))));
    vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_17 
        = ((0U != (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG)) 
           & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_4));
    if (vlTOPp->PIPELINE__DOT__Forwarding__DOT___T_32) {
        vlTOPp->PIPELINE__DOT__Forwarding_io_forward_a = 1U;
        vlTOPp->PIPELINE__DOT__Forwarding_io_forward_b = 1U;
    } else {
        vlTOPp->PIPELINE__DOT__Forwarding_io_forward_a 
            = ((IData)(vlTOPp->PIPELINE__DOT__Forwarding__DOT___T_44)
                ? (IData)(vlTOPp->PIPELINE__DOT__Forwarding__DOT___GEN_3)
                : (((((IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG) 
                      & (0U != (IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG))) 
                     & ((IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
                        == (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs1_out_REG))) 
                    & (~ (IData)(vlTOPp->PIPELINE__DOT__Forwarding__DOT___T_4)))
                    ? 1U : (IData)(vlTOPp->PIPELINE__DOT__Forwarding__DOT___GEN_3)));
        vlTOPp->PIPELINE__DOT__Forwarding_io_forward_b 
            = ((IData)(vlTOPp->PIPELINE__DOT__Forwarding__DOT___T_44)
                ? 1U : (((IData)(vlTOPp->PIPELINE__DOT__Forwarding__DOT___T_4) 
                         & ((IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
                            == (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs2_out_REG)))
                         ? 2U : ((IData)(vlTOPp->PIPELINE__DOT__Forwarding__DOT___T_11)
                                  ? 2U : 0U)));
    }
    vlTOPp->PIPELINE__DOT__RegFile_io_rdata2 = ((0U 
                                                 == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                 ? 0U
                                                 : 
                                                ((0x1fU 
                                                  == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                  ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_31
                                                  : 
                                                 ((0x1eU 
                                                   == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                   ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_30
                                                   : 
                                                  ((0x1dU 
                                                    == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                    ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_29
                                                    : 
                                                   ((0x1cU 
                                                     == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                     ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_28
                                                     : 
                                                    ((0x1bU 
                                                      == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                      ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_27
                                                      : 
                                                     ((0x1aU 
                                                       == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                       ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_26
                                                       : 
                                                      ((0x19U 
                                                        == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                        ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_25
                                                        : 
                                                       ((0x18U 
                                                         == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                         ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_24
                                                         : 
                                                        ((0x17U 
                                                          == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                          ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_23
                                                          : 
                                                         ((0x16U 
                                                           == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs2))
                                                           ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_22
                                                           : vlTOPp->PIPELINE__DOT__RegFile__DOT___GEN_53)))))))))));
    vlTOPp->PIPELINE__DOT__RegFile_io_rdata1 = ((0U 
                                                 == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                 ? 0U
                                                 : 
                                                ((0x1fU 
                                                  == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                  ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_31
                                                  : 
                                                 ((0x1eU 
                                                   == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                   ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_30
                                                   : 
                                                  ((0x1dU 
                                                    == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                    ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_29
                                                    : 
                                                   ((0x1cU 
                                                     == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                     ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_28
                                                     : 
                                                    ((0x1bU 
                                                      == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                      ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_27
                                                      : 
                                                     ((0x1aU 
                                                       == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                       ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_26
                                                       : 
                                                      ((0x19U 
                                                        == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                        ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_25
                                                        : 
                                                       ((0x18U 
                                                         == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                         ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_24
                                                         : 
                                                        ((0x17U 
                                                          == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                          ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_23
                                                          : 
                                                         ((0x16U 
                                                           == (IData)(vlTOPp->PIPELINE__DOT__RegFile_io_rs1))
                                                           ? vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_22
                                                           : vlTOPp->PIPELINE__DOT__RegFile__DOT___GEN_21)))))))))));
    if (((0U != (IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG)) 
         & (~ (IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_memRd_out_REG)))) {
        vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_13 
            = (((((IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
                  == (0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                               >> 0xfU))) & ((IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
                                             == (0x1fU 
                                                 & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                    >> 0x14U)))) 
                & (~ (((0U != (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG)) 
                       & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_4)) 
                      & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_5))))
                ? 2U : (((IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_12) 
                         & (~ (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_17)))
                         ? (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_6)
                         : (((IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_13) 
                             & (~ ((0U != (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG)) 
                                   & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_5))))
                             ? 2U : (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_6))));
        vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_12 
            = (((((IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
                  == (0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                               >> 0xfU))) & ((IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG) 
                                             == (0x1fU 
                                                 & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                    >> 0x14U)))) 
                & (~ (((0U != (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG)) 
                       & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_4)) 
                      & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_5))))
                ? 2U : (((IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_12) 
                         & (~ (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_17)))
                         ? 2U : (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_5)));
    } else {
        vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_13 
            = vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_6;
        vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_12 
            = vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_5;
    }
    vlTOPp->PIPELINE__DOT__ALU_io_in_A = ((1U == (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_OpA_out_REG))
                                           ? vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_IFID_pc4_out_REG
                                           : ((0U == (IData)(vlTOPp->PIPELINE__DOT__Forwarding_io_forward_a))
                                               ? vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs1_data_out_REG
                                               : ((1U 
                                                   == (IData)(vlTOPp->PIPELINE__DOT__Forwarding_io_forward_a))
                                                   ? vlTOPp->PIPELINE__DOT__d
                                                   : 
                                                  ((2U 
                                                    == (IData)(vlTOPp->PIPELINE__DOT__Forwarding_io_forward_a))
                                                    ? vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG
                                                    : vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs1_data_out_REG))));
    vlTOPp->PIPELINE__DOT___GEN_42 = ((1U == (IData)(vlTOPp->PIPELINE__DOT__Forwarding_io_forward_b))
                                       ? vlTOPp->PIPELINE__DOT__d
                                       : ((2U == (IData)(vlTOPp->PIPELINE__DOT__Forwarding_io_forward_b))
                                           ? vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG
                                           : 0U));
    if (vlTOPp->PIPELINE__DOT__control_module_io_branch) {
        vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_28 
            = (((0U != (IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)) 
                & (~ (IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_memRd_out_REG)))
                ? ((((((IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
                       == (0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                    >> 0xfU))) & ((IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
                                                  == 
                                                  (0x1fU 
                                                   & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                      >> 0x14U)))) 
                     & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_20)) 
                    & (~ (((0U != (IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG)) 
                           & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_12)) 
                          & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_13))))
                    ? 3U : ((((IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_37) 
                              & (~ (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_17))) 
                             & (~ (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_49)))
                             ? (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_13)
                             : (((((IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
                                   == (0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                >> 0x14U))) 
                                  & (~ ((0U != (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG)) 
                                        & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_5)))) 
                                 & (~ ((0U != (IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG)) 
                                       & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_13))))
                                 ? 3U : (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_13))))
                : (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_13));
        vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1 
            = (((0U != (IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)) 
                & (~ (IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_memRd_out_REG)))
                ? ((((((IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
                       == (0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                    >> 0xfU))) & ((IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG) 
                                                  == 
                                                  (0x1fU 
                                                   & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                      >> 0x14U)))) 
                     & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_20)) 
                    & (~ (((0U != (IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG)) 
                           & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_12)) 
                          & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_13))))
                    ? 3U : ((((IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_37) 
                              & (~ (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_17))) 
                             & (~ (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_49)))
                             ? 3U : (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_12)))
                : (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_12));
    } else {
        vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_28 = 0U;
        vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1 
            = ((IData)(vlTOPp->PIPELINE__DOT__control_module_io_branch)
                ? 0U : ((((0U != (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG)) 
                          & (~ (IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_MemRd_out_REG))) 
                         & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_4))
                         ? 6U : (((((0U != (IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG)) 
                                    & (~ (IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_memRd_out_REG))) 
                                   & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_12)) 
                                  & (~ (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_17)))
                                  ? 7U : (((((0U != (IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG)) 
                                             & (IData)(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_memRd_out_REG)) 
                                            & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_12)) 
                                           & (~ (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_17)))
                                           ? 9U : (
                                                   (((((0U 
                                                        != (IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)) 
                                                       & (~ (IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_memRd_out_REG))) 
                                                      & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_37)) 
                                                     & (~ (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_17))) 
                                                    & (~ (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_49)))
                                                    ? 8U
                                                    : 
                                                   ((((((0U 
                                                         != (IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG)) 
                                                        & (IData)(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_memRd_out_REG)) 
                                                       & (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_37)) 
                                                      & (~ (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_17))) 
                                                     & (~ (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___T_49)))
                                                     ? 0xaU
                                                     : 0U))))));
    }
    vlTOPp->PIPELINE__DOT__ALU_io_in_B = ((IData)(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_OpB_out_REG)
                                           ? vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_imm_out_REG
                                           : ((0U == (IData)(vlTOPp->PIPELINE__DOT__Forwarding_io_forward_b))
                                               ? vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs2_data_out_REG
                                               : vlTOPp->PIPELINE__DOT___GEN_42));
    vlTOPp->PIPELINE__DOT__ALU__DOT___result_T_2 = 
        (vlTOPp->PIPELINE__DOT__ALU_io_in_A + vlTOPp->PIPELINE__DOT__ALU_io_in_B);
    vlTOPp->PIPELINE__DOT__ALU__DOT___result_T_8 = 
        (VL_LTS_III(1,32,32, vlTOPp->PIPELINE__DOT__ALU_io_in_A, vlTOPp->PIPELINE__DOT__ALU_io_in_B)
          ? 1U : 0U);
    vlTOPp->PIPELINE__DOT__ALU__DOT___result_T_12 = 
        ((vlTOPp->PIPELINE__DOT__ALU_io_in_A < vlTOPp->PIPELINE__DOT__ALU_io_in_B)
          ? 1U : 0U);
    vlTOPp->PIPELINE__DOT__ALU__DOT___GEN_6 = (((4U 
                                                 == 
                                                 (0x1fU 
                                                  & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))) 
                                                | (4U 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))))
                                                ? (vlTOPp->PIPELINE__DOT__ALU_io_in_A 
                                                   ^ vlTOPp->PIPELINE__DOT__ALU_io_in_B)
                                                : (
                                                   ((5U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))) 
                                                    | (5U 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))))
                                                    ? 
                                                   (vlTOPp->PIPELINE__DOT__ALU_io_in_A 
                                                    >> 
                                                    (0x1fU 
                                                     & vlTOPp->PIPELINE__DOT__ALU_io_in_B))
                                                    : 
                                                   (((6U 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))) 
                                                     | (6U 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))))
                                                     ? 
                                                    (vlTOPp->PIPELINE__DOT__ALU_io_in_A 
                                                     | vlTOPp->PIPELINE__DOT__ALU_io_in_B)
                                                     : 
                                                    (((7U 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))) 
                                                      | (7U 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))))
                                                      ? 
                                                     (vlTOPp->PIPELINE__DOT__ALU_io_in_A 
                                                      & vlTOPp->PIPELINE__DOT__ALU_io_in_B)
                                                      : 
                                                     ((8U 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4)))
                                                       ? 
                                                      (vlTOPp->PIPELINE__DOT__ALU_io_in_A 
                                                       - vlTOPp->PIPELINE__DOT__ALU_io_in_B)
                                                       : 
                                                      (((0xdU 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))) 
                                                        | (0xdU 
                                                           == 
                                                           (0x1fU 
                                                            & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))))
                                                        ? 
                                                       VL_SHIFTRS_III(32,32,5, vlTOPp->PIPELINE__DOT__ALU_io_in_A, 
                                                                      (0x1fU 
                                                                       & vlTOPp->PIPELINE__DOT__ALU_io_in_B))
                                                        : 
                                                       (((0x1fU 
                                                          == 
                                                          (0x1fU 
                                                           & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))) 
                                                         | (0x1fU 
                                                            == 
                                                            (0x1fU 
                                                             & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))))
                                                         ? vlTOPp->PIPELINE__DOT__ALU_io_in_A
                                                         : 0U)))))));
    vlTOPp->PIPELINE__DOT__ALU__DOT___GEN_8 = (((2U 
                                                 == 
                                                 (0x1fU 
                                                  & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))) 
                                                | (2U 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))))
                                                ? (
                                                   (0xfffffffcU 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & ((IData)(vlTOPp->PIPELINE__DOT__ALU__DOT___result_T_8) 
                                                                      >> 1U)))) 
                                                       << 2U)) 
                                                   | (IData)(vlTOPp->PIPELINE__DOT__ALU__DOT___result_T_8))
                                                : (
                                                   ((3U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))) 
                                                    | (3U 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))))
                                                    ? 
                                                   ((0xfffffffcU 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & ((IData)(vlTOPp->PIPELINE__DOT__ALU__DOT___result_T_12) 
                                                                       >> 1U)))) 
                                                        << 2U)) 
                                                    | (IData)(vlTOPp->PIPELINE__DOT__ALU__DOT___result_T_12))
                                                    : vlTOPp->PIPELINE__DOT__ALU__DOT___GEN_6));
    vlTOPp->PIPELINE__DOT__ALU__DOT___GEN_10 = (0x7fffffffffffffffULL 
                                                & (((((((0U 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))) 
                                                        | (0U 
                                                           == 
                                                           (0x1fU 
                                                            & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4)))) 
                                                       | (0U 
                                                          == 
                                                          (0x1fU 
                                                           & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4)))) 
                                                      | (0U 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4)))) 
                                                     | (0U 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4)))) 
                                                    | (0U 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))))
                                                    ? 
                                                   (((QData)((IData)(
                                                                     (0x7fffffffU 
                                                                      & (- (IData)(
                                                                                (1U 
                                                                                & (vlTOPp->PIPELINE__DOT__ALU__DOT___result_T_2 
                                                                                >> 0x1fU))))))) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(vlTOPp->PIPELINE__DOT__ALU__DOT___result_T_2)))
                                                    : 
                                                   (((1U 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))) 
                                                     | (1U 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))))
                                                     ? 
                                                    ((QData)((IData)(vlTOPp->PIPELINE__DOT__ALU_io_in_A)) 
                                                     << 
                                                     (0x1fU 
                                                      & vlTOPp->PIPELINE__DOT__ALU_io_in_B))
                                                     : 
                                                    (((QData)((IData)(
                                                                      (0x7fffffffU 
                                                                       & (- (IData)(
                                                                                (1U 
                                                                                & (vlTOPp->PIPELINE__DOT__ALU__DOT___GEN_8 
                                                                                >> 0x1fU))))))) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(vlTOPp->PIPELINE__DOT__ALU__DOT___GEN_8))))));
    vlTOPp->PIPELINE__DOT___Branch_M_io_arg_y_T_7 = 
        ((3U == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_28))
          ? vlTOPp->PIPELINE__DOT__RegFile_io_w_data
          : ((2U == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_28))
              ? vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG
              : ((1U == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_28))
                  ? (IData)(vlTOPp->PIPELINE__DOT__ALU__DOT___GEN_10)
                  : ((0U == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_28))
                      ? vlTOPp->PIPELINE__DOT__RegFile_io_rdata2
                      : 0U))));
    vlTOPp->PIPELINE__DOT__Branch_M_io_arg_x = ((0xaU 
                                                 == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                 ? vlTOPp->PIPELINE__DOT__RegFile_io_rdata1
                                                 : 
                                                ((9U 
                                                  == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                  ? vlTOPp->PIPELINE__DOT__RegFile_io_rdata1
                                                  : 
                                                 ((8U 
                                                   == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                   ? vlTOPp->PIPELINE__DOT__RegFile_io_rdata1
                                                   : 
                                                  ((7U 
                                                    == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                    ? vlTOPp->PIPELINE__DOT__RegFile_io_rdata1
                                                    : 
                                                   ((6U 
                                                     == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                     ? vlTOPp->PIPELINE__DOT__RegFile_io_rdata1
                                                     : 
                                                    ((5U 
                                                      == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                      ? vlTOPp->PIPELINE__DOT__RegFile_io_w_data
                                                      : 
                                                     ((4U 
                                                       == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                       ? vlTOPp->PIPELINE__DOT__DataMemory_io_dataOut
                                                       : 
                                                      ((3U 
                                                        == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                        ? vlTOPp->PIPELINE__DOT__RegFile_io_w_data
                                                        : 
                                                       ((2U 
                                                         == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                         ? vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG
                                                         : 
                                                        ((1U 
                                                          == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                          ? (IData)(vlTOPp->PIPELINE__DOT__ALU__DOT___GEN_10)
                                                          : 
                                                         ((0U 
                                                           == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                           ? vlTOPp->PIPELINE__DOT__RegFile_io_rdata1
                                                           : 0U)))))))))));
    vlTOPp->PIPELINE__DOT__Branch_M_io_br_taken = ((IData)(vlTOPp->PIPELINE__DOT__control_module_io_branch) 
                                                   & ((0U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                           >> 0xcU)))
                                                       ? 
                                                      (vlTOPp->PIPELINE__DOT__Branch_M_io_arg_x 
                                                       == vlTOPp->PIPELINE__DOT___Branch_M_io_arg_y_T_7)
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                            >> 0xcU)))
                                                        ? 
                                                       (vlTOPp->PIPELINE__DOT__Branch_M_io_arg_x 
                                                        != vlTOPp->PIPELINE__DOT___Branch_M_io_arg_y_T_7)
                                                        : 
                                                       ((4U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                             >> 0xcU)))
                                                         ? 
                                                        VL_LTS_III(1,32,32, vlTOPp->PIPELINE__DOT__Branch_M_io_arg_x, vlTOPp->PIPELINE__DOT___Branch_M_io_arg_y_T_7)
                                                         : 
                                                        ((5U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                              >> 0xcU)))
                                                          ? 
                                                         VL_GTES_III(1,32,32, vlTOPp->PIPELINE__DOT__Branch_M_io_arg_x, vlTOPp->PIPELINE__DOT___Branch_M_io_arg_y_T_7)
                                                          : 
                                                         ((6U 
                                                           == 
                                                           (7U 
                                                            & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                               >> 0xcU)))
                                                           ? 
                                                          (vlTOPp->PIPELINE__DOT__Branch_M_io_arg_x 
                                                           < vlTOPp->PIPELINE__DOT___Branch_M_io_arg_y_T_7)
                                                           : 
                                                          ((7U 
                                                            == 
                                                            (7U 
                                                             & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                                >> 0xcU))) 
                                                           & (vlTOPp->PIPELINE__DOT__Branch_M_io_arg_x 
                                                              >= vlTOPp->PIPELINE__DOT___Branch_M_io_arg_y_T_7))))))));
    vlTOPp->PIPELINE__DOT__PC_io_in = ((IData)(vlTOPp->PIPELINE__DOT__HazardDetect_io_pc_forward)
                                        ? vlTOPp->PIPELINE__DOT__IF_ID___DOT__Pc4_In
                                        : ((1U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                            ? (((IData)(vlTOPp->PIPELINE__DOT__Branch_M_io_br_taken) 
                                                & (IData)(vlTOPp->PIPELINE__DOT__control_module_io_branch))
                                                ? (
                                                   ((((0x80000000U 
                                                       & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                                       ? 0x7ffffU
                                                       : 0U) 
                                                     << 0xdU) 
                                                    | ((0x1000U 
                                                        & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                           >> 0x13U)) 
                                                       | ((0x800U 
                                                           & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                              << 4U)) 
                                                          | ((0x7e0U 
                                                              & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                                 >> 0x14U)) 
                                                             | (0x1eU 
                                                                & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                                   >> 7U)))))) 
                                                   + vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_pc)
                                                : ((IData)(4U) 
                                                   + vlTOPp->PIPELINE__DOT__PC__DOT__PC))
                                            : ((2U 
                                                == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                                ? (
                                                   ((((0x80000000U 
                                                       & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                                       ? 0x7ffU
                                                       : 0U) 
                                                     << 0x15U) 
                                                    | ((0x100000U 
                                                        & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                           >> 0xbU)) 
                                                       | ((0xff000U 
                                                           & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr) 
                                                          | ((0x800U 
                                                              & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                                 >> 9U)) 
                                                             | (0x7feU 
                                                                & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                                   >> 0x14U)))))) 
                                                   + vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_pc)
                                                : (
                                                   (3U 
                                                    == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                                    ? 
                                                   (0xfffffffeU 
                                                    & (((2U 
                                                         == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_extend))
                                                         ? 
                                                        (0xfffff000U 
                                                         & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                                         : vlTOPp->PIPELINE__DOT___ImmValue_T_3) 
                                                       + 
                                                       ((0xaU 
                                                         == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                         ? vlTOPp->PIPELINE__DOT__RegFile_io_w_data
                                                         : 
                                                        ((9U 
                                                          == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                          ? vlTOPp->PIPELINE__DOT__DataMemory_io_dataOut
                                                          : 
                                                         ((8U 
                                                           == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                           ? vlTOPp->PIPELINE__DOT__RegFile_io_w_data
                                                           : 
                                                          ((7U 
                                                            == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                            ? vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG
                                                            : 
                                                           ((6U 
                                                             == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                             ? (IData)(vlTOPp->PIPELINE__DOT__ALU__DOT___GEN_10)
                                                             : 
                                                            ((5U 
                                                              == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                              ? vlTOPp->PIPELINE__DOT__RegFile_io_rdata1
                                                              : 
                                                             ((4U 
                                                               == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                               ? vlTOPp->PIPELINE__DOT__RegFile_io_rdata1
                                                               : 
                                                              ((3U 
                                                                == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                                ? vlTOPp->PIPELINE__DOT__RegFile_io_rdata1
                                                                : 
                                                               ((2U 
                                                                 == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                                 ? vlTOPp->PIPELINE__DOT__RegFile_io_rdata1
                                                                 : 
                                                                ((1U 
                                                                  == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                                  ? vlTOPp->PIPELINE__DOT__RegFile_io_rdata1
                                                                  : 
                                                                 ((0U 
                                                                   == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                                   ? vlTOPp->PIPELINE__DOT__RegFile_io_rdata1
                                                                   : 0U)))))))))))))
                                                    : 
                                                   ((IData)(4U) 
                                                    + vlTOPp->PIPELINE__DOT__PC__DOT__PC)))));
}

void VPIPELINE::_eval_initial(VPIPELINE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPIPELINE::_eval_initial\n"); );
    VPIPELINE* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VPIPELINE::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPIPELINE::final\n"); );
    // Variables
    VPIPELINE__Syms* __restrict vlSymsp = this->__VlSymsp;
    VPIPELINE* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VPIPELINE::_eval_settle(VPIPELINE__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPIPELINE::_eval_settle\n"); );
    VPIPELINE* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void VPIPELINE::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPIPELINE::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_out = VL_RAND_RESET_I(4);
    PIPELINE__DOT__PC_io_in = VL_RAND_RESET_I(32);
    PIPELINE__DOT__DataMemory_io_dataOut = VL_RAND_RESET_I(32);
    PIPELINE__DOT__control_module_io_branch = VL_RAND_RESET_I(1);
    PIPELINE__DOT__control_module_io_extend = VL_RAND_RESET_I(2);
    PIPELINE__DOT__control_module_io_next_pc_sel = VL_RAND_RESET_I(2);
    PIPELINE__DOT__RegFile_io_rs1 = VL_RAND_RESET_I(5);
    PIPELINE__DOT__RegFile_io_rs2 = VL_RAND_RESET_I(5);
    PIPELINE__DOT__RegFile_io_w_data = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile_io_rdata1 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile_io_rdata2 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__ALU_io_in_A = VL_RAND_RESET_I(32);
    PIPELINE__DOT__ALU_io_in_B = VL_RAND_RESET_I(32);
    PIPELINE__DOT__Branch_M_io_arg_x = VL_RAND_RESET_I(32);
    PIPELINE__DOT__Branch_M_io_br_taken = VL_RAND_RESET_I(1);
    PIPELINE__DOT__Forwarding_io_forward_a = VL_RAND_RESET_I(2);
    PIPELINE__DOT__Forwarding_io_forward_b = VL_RAND_RESET_I(2);
    PIPELINE__DOT__HazardDetect_io_inst_forward = VL_RAND_RESET_I(1);
    PIPELINE__DOT__HazardDetect_io_pc_forward = VL_RAND_RESET_I(1);
    PIPELINE__DOT__HazardDetect_io_ctrl_forward = VL_RAND_RESET_I(1);
    PIPELINE__DOT__Branch_Forward_io_forward_rs1 = VL_RAND_RESET_I(4);
    PIPELINE__DOT__Structural_io_fwd_rs1 = VL_RAND_RESET_I(1);
    PIPELINE__DOT__Structural_io_fwd_rs2 = VL_RAND_RESET_I(1);
    PIPELINE__DOT__PC_for = VL_RAND_RESET_I(32);
    PIPELINE__DOT__Instruction_F = VL_RAND_RESET_I(32);
    PIPELINE__DOT___ImmValue_T_3 = VL_RAND_RESET_I(32);
    PIPELINE__DOT___Branch_M_io_arg_y_T_7 = VL_RAND_RESET_I(32);
    PIPELINE__DOT___GEN_45 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__d = VL_RAND_RESET_I(32);
    PIPELINE__DOT___GEN_42 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__IF_ID___DOT__Pc4_In = VL_RAND_RESET_I(32);
    PIPELINE__DOT__IF_ID___DOT__S_pc = VL_RAND_RESET_I(32);
    PIPELINE__DOT__IF_ID___DOT__S_instr = VL_RAND_RESET_I(32);
    PIPELINE__DOT__ID_EX___DOT__io_rs1_out_REG = VL_RAND_RESET_I(5);
    PIPELINE__DOT__ID_EX___DOT__io_rs2_out_REG = VL_RAND_RESET_I(5);
    PIPELINE__DOT__ID_EX___DOT__io_rs1_data_out_REG = VL_RAND_RESET_I(32);
    PIPELINE__DOT__ID_EX___DOT__io_rs2_data_out_REG = VL_RAND_RESET_I(32);
    PIPELINE__DOT__ID_EX___DOT__io_imm_out_REG = VL_RAND_RESET_I(32);
    PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG = VL_RAND_RESET_I(5);
    PIPELINE__DOT__ID_EX___DOT__io_func3_out_REG = VL_RAND_RESET_I(3);
    PIPELINE__DOT__ID_EX___DOT__io_func7_out_REG = VL_RAND_RESET_I(1);
    PIPELINE__DOT__ID_EX___DOT__io_ctrl_MemWr_out_REG = VL_RAND_RESET_I(1);
    PIPELINE__DOT__ID_EX___DOT__io_ctrl_MemRd_out_REG = VL_RAND_RESET_I(1);
    PIPELINE__DOT__ID_EX___DOT__io_ctrl_Reg_W_out_REG = VL_RAND_RESET_I(1);
    PIPELINE__DOT__ID_EX___DOT__io_ctrl_MemToReg_out_REG = VL_RAND_RESET_I(1);
    PIPELINE__DOT__ID_EX___DOT__io_ctrl_AluOp_out_REG = VL_RAND_RESET_I(3);
    PIPELINE__DOT__ID_EX___DOT__io_ctrl_OpA_out_REG = VL_RAND_RESET_I(2);
    PIPELINE__DOT__ID_EX___DOT__io_ctrl_OpB_out_REG = VL_RAND_RESET_I(1);
    PIPELINE__DOT__ID_EX___DOT__io_IFID_pc4_out_REG = VL_RAND_RESET_I(32);
    PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_memRd_out_REG = VL_RAND_RESET_I(1);
    PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_memWr_out_REG = VL_RAND_RESET_I(1);
    PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_memToReg_out_REG = VL_RAND_RESET_I(1);
    PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_reg_w_out_REG = VL_RAND_RESET_I(1);
    PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rs2_out_REG = VL_RAND_RESET_I(32);
    PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG = VL_RAND_RESET_I(5);
    PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG = VL_RAND_RESET_I(32);
    PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_memToReg_out_REG = VL_RAND_RESET_I(1);
    PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG = VL_RAND_RESET_I(1);
    PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_memRd_out_REG = VL_RAND_RESET_I(1);
    PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG = VL_RAND_RESET_I(5);
    PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_dataMem_out_REG = VL_RAND_RESET_I(32);
    PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_alu_out_REG = VL_RAND_RESET_I(32);
    PIPELINE__DOT__PC__DOT__PC = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<4096; ++__Vi0) {
            PIPELINE__DOT__InstMemory__DOT__imem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            PIPELINE__DOT__DataMemory__DOT__Dmemory[__Vi0] = VL_RAND_RESET_I(32);
    }}
    PIPELINE__DOT__control_module__DOT___GEN_5 = VL_RAND_RESET_I(1);
    PIPELINE__DOT__control_module__DOT___GEN_51 = VL_RAND_RESET_I(1);
    PIPELINE__DOT__RegFile__DOT__regfile_0 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_1 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_2 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_3 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_4 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_5 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_6 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_7 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_8 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_9 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_10 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_11 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_12 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_13 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_14 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_15 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_16 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_17 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_18 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_19 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_20 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_21 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_22 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_23 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_24 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_25 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_26 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_27 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_28 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_29 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_30 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT__regfile_31 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT___GEN_21 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__RegFile__DOT___GEN_53 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__ALU_Control__DOT___GEN_4 = VL_RAND_RESET_I(6);
    PIPELINE__DOT__ALU__DOT___result_T_2 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__ALU__DOT___result_T_8 = VL_RAND_RESET_I(2);
    PIPELINE__DOT__ALU__DOT___result_T_12 = VL_RAND_RESET_I(2);
    PIPELINE__DOT__ALU__DOT___GEN_6 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__ALU__DOT___GEN_8 = VL_RAND_RESET_I(32);
    PIPELINE__DOT__ALU__DOT___GEN_10 = VL_RAND_RESET_Q(63);
    PIPELINE__DOT__Forwarding__DOT___T_4 = VL_RAND_RESET_I(1);
    PIPELINE__DOT__Forwarding__DOT___T_11 = VL_RAND_RESET_I(1);
    PIPELINE__DOT__Forwarding__DOT___GEN_3 = VL_RAND_RESET_I(2);
    PIPELINE__DOT__Forwarding__DOT___T_32 = VL_RAND_RESET_I(1);
    PIPELINE__DOT__Forwarding__DOT___T_44 = VL_RAND_RESET_I(1);
    PIPELINE__DOT__Branch_Forward__DOT___T_4 = VL_RAND_RESET_I(1);
    PIPELINE__DOT__Branch_Forward__DOT___T_5 = VL_RAND_RESET_I(1);
    PIPELINE__DOT__Branch_Forward__DOT___GEN_5 = VL_RAND_RESET_I(1);
    PIPELINE__DOT__Branch_Forward__DOT___GEN_6 = VL_RAND_RESET_I(1);
    PIPELINE__DOT__Branch_Forward__DOT___T_12 = VL_RAND_RESET_I(1);
    PIPELINE__DOT__Branch_Forward__DOT___T_13 = VL_RAND_RESET_I(1);
    PIPELINE__DOT__Branch_Forward__DOT___T_17 = VL_RAND_RESET_I(1);
    PIPELINE__DOT__Branch_Forward__DOT___T_20 = VL_RAND_RESET_I(1);
    PIPELINE__DOT__Branch_Forward__DOT___GEN_12 = VL_RAND_RESET_I(2);
    PIPELINE__DOT__Branch_Forward__DOT___GEN_13 = VL_RAND_RESET_I(2);
    PIPELINE__DOT__Branch_Forward__DOT___T_37 = VL_RAND_RESET_I(1);
    PIPELINE__DOT__Branch_Forward__DOT___T_49 = VL_RAND_RESET_I(1);
    PIPELINE__DOT__Branch_Forward__DOT___GEN_28 = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
