// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VPIPELINE__Syms.h"


void VPIPELINE::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VPIPELINE__Syms* __restrict vlSymsp = static_cast<VPIPELINE__Syms*>(userp);
    VPIPELINE* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VPIPELINE::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VPIPELINE__Syms* __restrict vlSymsp = static_cast<VPIPELINE__Syms*>(userp);
    VPIPELINE* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+0,(((IData)(vlTOPp->PIPELINE__DOT__HazardDetect_io_pc_forward)
                                       ? ((IData)(4U) 
                                          + vlTOPp->PIPELINE__DOT__PC__DOT__PC)
                                       : ((1U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                           ? (((IData)(vlTOPp->PIPELINE__DOT__Branch_M_io_br_taken) 
                                               & (IData)(vlTOPp->PIPELINE__DOT__control_module_io_branch))
                                               ? 0U
                                               : ((IData)(4U) 
                                                  + vlTOPp->PIPELINE__DOT__PC__DOT__PC))
                                           : ((2U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                               ? 0U
                                               : ((3U 
                                                   == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                                   ? 0U
                                                   : 
                                                  ((IData)(4U) 
                                                   + vlTOPp->PIPELINE__DOT__PC__DOT__PC)))))),32);
            tracep->chgIData(oldp+1,(((IData)(vlTOPp->PIPELINE__DOT__HazardDetect_io_pc_forward)
                                       ? vlTOPp->PIPELINE__DOT__PC_for
                                       : ((1U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                           ? (((IData)(vlTOPp->PIPELINE__DOT__Branch_M_io_br_taken) 
                                               & (IData)(vlTOPp->PIPELINE__DOT__control_module_io_branch))
                                               ? 0U
                                               : vlTOPp->PIPELINE__DOT__PC_for)
                                           : ((2U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                               ? 0U
                                               : ((3U 
                                                   == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                                   ? 0U
                                                   : vlTOPp->PIPELINE__DOT__PC_for))))),32);
            tracep->chgIData(oldp+2,(((IData)(vlTOPp->PIPELINE__DOT__HazardDetect_io_pc_forward)
                                       ? vlTOPp->PIPELINE__DOT__Instruction_F
                                       : ((1U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                           ? (((IData)(vlTOPp->PIPELINE__DOT__Branch_M_io_br_taken) 
                                               & (IData)(vlTOPp->PIPELINE__DOT__control_module_io_branch))
                                               ? 0U
                                               : vlTOPp->PIPELINE__DOT__Instruction_F)
                                           : ((2U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                               ? 0U
                                               : ((3U 
                                                   == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                                   ? 0U
                                                   : vlTOPp->PIPELINE__DOT__Instruction_F))))),32);
            tracep->chgIData(oldp+3,(vlTOPp->PIPELINE__DOT__IF_ID___DOT__Pc4_In),32);
            tracep->chgIData(oldp+4,(vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_pc),32);
            tracep->chgIData(oldp+5,(vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr),32);
            tracep->chgCData(oldp+6,(vlTOPp->PIPELINE__DOT__RegFile_io_rs1),5);
            tracep->chgCData(oldp+7,(vlTOPp->PIPELINE__DOT__RegFile_io_rs2),5);
            tracep->chgIData(oldp+8,(((IData)(vlTOPp->PIPELINE__DOT__Structural_io_fwd_rs1)
                                       ? ((IData)(vlTOPp->PIPELINE__DOT__Structural_io_fwd_rs1)
                                           ? vlTOPp->PIPELINE__DOT__RegFile_io_w_data
                                           : 0U) : vlTOPp->PIPELINE__DOT__RegFile_io_rdata1)),32);
            tracep->chgIData(oldp+9,(((IData)(vlTOPp->PIPELINE__DOT__Structural_io_fwd_rs2)
                                       ? ((IData)(vlTOPp->PIPELINE__DOT__Structural_io_fwd_rs2)
                                           ? vlTOPp->PIPELINE__DOT__RegFile_io_w_data
                                           : 0U) : vlTOPp->PIPELINE__DOT__RegFile_io_rdata2)),32);
            tracep->chgIData(oldp+10,(((2U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_extend))
                                        ? (0xfffff000U 
                                           & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                        : vlTOPp->PIPELINE__DOT___ImmValue_T_3)),32);
            tracep->chgCData(oldp+11,((0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                >> 7U))),5);
            tracep->chgCData(oldp+12,((7U & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                             >> 0xcU))),3);
            tracep->chgBit(oldp+13,((1U & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                           >> 0x1eU))));
            tracep->chgBit(oldp+14,(((~ (IData)(vlTOPp->PIPELINE__DOT__HazardDetect_io_ctrl_forward)) 
                                     & ((0x33U != (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                        & ((0x13U != 
                                            (0x7fU 
                                             & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                           & (0x23U 
                                              == (0x7fU 
                                                  & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)))))));
            tracep->chgBit(oldp+15,(((~ (IData)(vlTOPp->PIPELINE__DOT__HazardDetect_io_ctrl_forward)) 
                                     & ((0x33U != (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                        & (IData)(vlTOPp->PIPELINE__DOT__control_module__DOT___GEN_51)))));
            tracep->chgBit(oldp+16,(((~ (IData)(vlTOPp->PIPELINE__DOT__HazardDetect_io_ctrl_forward)) 
                                     & ((0x33U == (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                        | ((0x13U == 
                                            (0x7fU 
                                             & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                           | ((0x23U 
                                               != (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                              & ((3U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                                 | ((0x63U 
                                                     != 
                                                     (0x7fU 
                                                      & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                                    & ((0x6fU 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                                       | ((0x67U 
                                                           == 
                                                           (0x7fU 
                                                            & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                                          | (IData)(vlTOPp->PIPELINE__DOT__control_module__DOT___GEN_5)))))))))));
            tracep->chgCData(oldp+17,(((IData)(vlTOPp->PIPELINE__DOT__HazardDetect_io_ctrl_forward)
                                        ? 0U : ((0x33U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                 ? 0U
                                                 : 
                                                ((0x13U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                  ? 1U
                                                  : 
                                                 ((0x23U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                   ? 5U
                                                   : 
                                                  ((3U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                    ? 4U
                                                    : 
                                                   ((0x63U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                     ? 2U
                                                     : 
                                                    ((0x6fU 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                      ? 3U
                                                      : 
                                                     ((0x67U 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                       ? 3U
                                                       : 
                                                      ((0x37U 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                        ? 6U
                                                        : 
                                                       ((0x17U 
                                                         == 
                                                         (0x7fU 
                                                          & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                         ? 7U
                                                         : 0U))))))))))),3);
            tracep->chgCData(oldp+18,(((0x33U == (0x7fU 
                                                  & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                        ? 0U : ((0x13U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                 ? 0U
                                                 : 
                                                ((0x23U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                  ? 0U
                                                  : 
                                                 ((3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                   ? 0U
                                                   : 
                                                  ((0x63U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                    ? 0U
                                                    : 
                                                   ((0x6fU 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                     ? 1U
                                                     : 
                                                    ((0x67U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                      ? 1U
                                                      : 
                                                     ((0x37U 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                       ? 3U
                                                       : 
                                                      ((0x17U 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                        ? 2U
                                                        : 0U)))))))))),2);
            tracep->chgBit(oldp+19,(((~ (IData)(vlTOPp->PIPELINE__DOT__HazardDetect_io_ctrl_forward)) 
                                     & ((0x33U != (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                        & ((0x13U == 
                                            (0x7fU 
                                             & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                           | ((0x23U 
                                               == (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                              | ((3U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                                 | ((0x63U 
                                                     != 
                                                     (0x7fU 
                                                      & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                                    & ((0x6fU 
                                                        != 
                                                        (0x7fU 
                                                         & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                                       & ((0x67U 
                                                           != 
                                                           (0x7fU 
                                                            & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                                          & (IData)(vlTOPp->PIPELINE__DOT__control_module__DOT___GEN_5)))))))))));
            tracep->chgCData(oldp+20,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs1_out_REG),5);
            tracep->chgCData(oldp+21,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs2_out_REG),5);
            tracep->chgIData(oldp+22,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs1_data_out_REG),32);
            tracep->chgIData(oldp+23,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs2_data_out_REG),32);
            tracep->chgCData(oldp+24,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG),5);
            tracep->chgIData(oldp+25,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_imm_out_REG),32);
            tracep->chgCData(oldp+26,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_func3_out_REG),3);
            tracep->chgBit(oldp+27,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_func7_out_REG));
            tracep->chgBit(oldp+28,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_MemWr_out_REG));
            tracep->chgBit(oldp+29,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_MemRd_out_REG));
            tracep->chgBit(oldp+30,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_Reg_W_out_REG));
            tracep->chgBit(oldp+31,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_MemToReg_out_REG));
            tracep->chgCData(oldp+32,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_AluOp_out_REG),3);
            tracep->chgCData(oldp+33,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_OpA_out_REG),2);
            tracep->chgBit(oldp+34,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_OpB_out_REG));
            tracep->chgIData(oldp+35,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_IFID_pc4_out_REG),32);
            tracep->chgIData(oldp+36,(((0U == (IData)(vlTOPp->PIPELINE__DOT__Forwarding_io_forward_b))
                                        ? vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs2_data_out_REG
                                        : vlTOPp->PIPELINE__DOT___GEN_42)),32);
            tracep->chgIData(oldp+37,((IData)(vlTOPp->PIPELINE__DOT__ALU__DOT___GEN_10)),32);
            tracep->chgBit(oldp+38,(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_memRd_out_REG));
            tracep->chgBit(oldp+39,(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_memWr_out_REG));
            tracep->chgBit(oldp+40,(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_memToReg_out_REG));
            tracep->chgBit(oldp+41,(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_reg_w_out_REG));
            tracep->chgIData(oldp+42,(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rs2_out_REG),32);
            tracep->chgCData(oldp+43,(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG),5);
            tracep->chgIData(oldp+44,(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG),32);
            tracep->chgIData(oldp+45,(vlTOPp->PIPELINE__DOT__DataMemory_io_dataOut),32);
            tracep->chgBit(oldp+46,(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_memToReg_out_REG));
            tracep->chgBit(oldp+47,(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG));
            tracep->chgBit(oldp+48,(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_memRd_out_REG));
            tracep->chgCData(oldp+49,(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG),5);
            tracep->chgIData(oldp+50,(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_dataMem_out_REG),32);
            tracep->chgIData(oldp+51,(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_alu_out_REG),32);
            tracep->chgIData(oldp+52,(((IData)(vlTOPp->PIPELINE__DOT__HazardDetect_io_pc_forward)
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
                                                    + vlTOPp->PIPELINE__DOT__PC__DOT__PC)))))),32);
            tracep->chgIData(oldp+53,(vlTOPp->PIPELINE__DOT__PC__DOT__PC),32);
            tracep->chgIData(oldp+54,(((IData)(4U) 
                                       + vlTOPp->PIPELINE__DOT__PC__DOT__PC)),32);
            tracep->chgIData(oldp+55,(vlTOPp->PIPELINE__DOT__InstMemory__DOT__imem
                                      [(0xfffU & (vlTOPp->PIPELINE__DOT__PC__DOT__PC 
                                                  >> 2U))]),32);
            tracep->chgCData(oldp+56,((0x7fU & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)),7);
            tracep->chgBit(oldp+57,(((0x33U != (0x7fU 
                                                & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                     & ((0x13U != (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                        & (0x23U == 
                                           (0x7fU & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))))));
            tracep->chgBit(oldp+58,(vlTOPp->PIPELINE__DOT__control_module_io_branch));
            tracep->chgBit(oldp+59,(((0x33U != (0x7fU 
                                                & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                     & (IData)(vlTOPp->PIPELINE__DOT__control_module__DOT___GEN_51))));
            tracep->chgBit(oldp+60,(((0x33U == (0x7fU 
                                                & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                     | ((0x13U == (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                        | ((0x23U != 
                                            (0x7fU 
                                             & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                           & ((3U == 
                                               (0x7fU 
                                                & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                              | ((0x63U 
                                                  != 
                                                  (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                                 & ((0x6fU 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                                    | ((0x67U 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                                       | (IData)(vlTOPp->PIPELINE__DOT__control_module__DOT___GEN_5))))))))));
            tracep->chgCData(oldp+61,(((0x33U == (0x7fU 
                                                  & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                        ? 0U : ((0x13U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                 ? 1U
                                                 : 
                                                ((0x23U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                  ? 5U
                                                  : 
                                                 ((3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                   ? 4U
                                                   : 
                                                  ((0x63U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                    ? 2U
                                                    : 
                                                   ((0x6fU 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                     ? 3U
                                                     : 
                                                    ((0x67U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                      ? 3U
                                                      : 
                                                     ((0x37U 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                       ? 6U
                                                       : 
                                                      ((0x17U 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                                        ? 7U
                                                        : 0U)))))))))),3);
            tracep->chgBit(oldp+62,(((0x33U != (0x7fU 
                                                & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                     & ((0x13U == (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                        | ((0x23U == 
                                            (0x7fU 
                                             & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                           | ((3U == 
                                               (0x7fU 
                                                & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                              | ((0x63U 
                                                  != 
                                                  (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                                 & ((0x6fU 
                                                     != 
                                                     (0x7fU 
                                                      & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                                    & ((0x67U 
                                                        != 
                                                        (0x7fU 
                                                         & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                                       & (IData)(vlTOPp->PIPELINE__DOT__control_module__DOT___GEN_5))))))))));
            tracep->chgCData(oldp+63,(vlTOPp->PIPELINE__DOT__control_module_io_extend),2);
            tracep->chgCData(oldp+64,(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel),2);
            tracep->chgIData(oldp+65,(((((0x80000000U 
                                          & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                          ? 0xfffffU
                                          : 0U) << 0xcU) 
                                       | (0xfffU & 
                                          (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                           >> 0x14U)))),32);
            tracep->chgIData(oldp+66,(((((0x80000000U 
                                          & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                          ? 0xfffffU
                                          : 0U) << 0xcU) 
                                       | ((0xfe0U & 
                                           (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                            >> 0x14U)) 
                                          | (0x1fU 
                                             & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                >> 7U))))),32);
            tracep->chgIData(oldp+67,((((((0x80000000U 
                                           & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                           ? 0x7ffffU
                                           : 0U) << 0xdU) 
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
                                       + vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_pc)),32);
            tracep->chgIData(oldp+68,((0xfffff000U 
                                       & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)),32);
            tracep->chgIData(oldp+69,((((((0x80000000U 
                                           & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                           ? 0x7ffU
                                           : 0U) << 0x15U) 
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
                                       + vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_pc)),32);
            tracep->chgIData(oldp+70,(vlTOPp->PIPELINE__DOT__RegFile_io_w_data),32);
            tracep->chgIData(oldp+71,(vlTOPp->PIPELINE__DOT__RegFile_io_rdata1),32);
            tracep->chgIData(oldp+72,(vlTOPp->PIPELINE__DOT__RegFile_io_rdata2),32);
            tracep->chgCData(oldp+73,((0x1fU & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))),5);
            tracep->chgIData(oldp+74,(vlTOPp->PIPELINE__DOT__ALU_io_in_A),32);
            tracep->chgIData(oldp+75,(vlTOPp->PIPELINE__DOT__ALU_io_in_B),32);
            tracep->chgIData(oldp+76,(vlTOPp->PIPELINE__DOT__Branch_M_io_arg_x),32);
            tracep->chgIData(oldp+77,(vlTOPp->PIPELINE__DOT___Branch_M_io_arg_y_T_7),32);
            tracep->chgBit(oldp+78,(vlTOPp->PIPELINE__DOT__Branch_M_io_br_taken));
            tracep->chgIData(oldp+79,(((0xaU == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                        ? vlTOPp->PIPELINE__DOT__RegFile_io_w_data
                                        : ((9U == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                            ? vlTOPp->PIPELINE__DOT__DataMemory_io_dataOut
                                            : ((8U 
                                                == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                ? vlTOPp->PIPELINE__DOT__RegFile_io_w_data
                                                : (
                                                   (7U 
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
                                                           : 0U)))))))))))),32);
            tracep->chgIData(oldp+80,((0xfffffffeU 
                                       & (((2U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_extend))
                                            ? (0xfffff000U 
                                               & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                            : vlTOPp->PIPELINE__DOT___ImmValue_T_3) 
                                          + ((0xaU 
                                              == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                              ? vlTOPp->PIPELINE__DOT__RegFile_io_w_data
                                              : ((9U 
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
                                                           : 0U)))))))))))))),32);
            tracep->chgCData(oldp+81,(vlTOPp->PIPELINE__DOT__Forwarding_io_forward_a),2);
            tracep->chgCData(oldp+82,(vlTOPp->PIPELINE__DOT__Forwarding_io_forward_b),2);
            tracep->chgBit(oldp+83,(vlTOPp->PIPELINE__DOT__HazardDetect_io_inst_forward));
            tracep->chgBit(oldp+84,(vlTOPp->PIPELINE__DOT__HazardDetect_io_pc_forward));
            tracep->chgBit(oldp+85,(vlTOPp->PIPELINE__DOT__HazardDetect_io_ctrl_forward));
            tracep->chgCData(oldp+86,((0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                >> 0xfU))),5);
            tracep->chgCData(oldp+87,((0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                >> 0x14U))),5);
            tracep->chgCData(oldp+88,(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1),4);
            tracep->chgCData(oldp+89,(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_28),4);
            tracep->chgBit(oldp+90,(vlTOPp->PIPELINE__DOT__Structural_io_fwd_rs1));
            tracep->chgBit(oldp+91,(vlTOPp->PIPELINE__DOT__Structural_io_fwd_rs2));
            tracep->chgIData(oldp+92,(vlTOPp->PIPELINE__DOT__PC_for),32);
            tracep->chgIData(oldp+93,(vlTOPp->PIPELINE__DOT__Instruction_F),32);
            tracep->chgIData(oldp+94,(vlTOPp->PIPELINE__DOT__d),32);
            tracep->chgSData(oldp+95,((0xfffU & (vlTOPp->PIPELINE__DOT__PC__DOT__PC 
                                                 >> 2U))),12);
            tracep->chgIData(oldp+96,(vlTOPp->PIPELINE__DOT__DataMemory__DOT__Dmemory
                                      [(0x3ffU & vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG)]),32);
            tracep->chgSData(oldp+97,((0x3ffU & vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG)),10);
            tracep->chgIData(oldp+98,(((0x80000000U 
                                        & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                        ? 0xfffffU : 0U)),20);
            tracep->chgSData(oldp+99,((0xfffU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                 >> 0x14U))),12);
            tracep->chgCData(oldp+100,((0x7fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                 >> 0x19U))),7);
            tracep->chgIData(oldp+101,(((0x80000000U 
                                         & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                         ? 0x7ffffU
                                         : 0U)),19);
            tracep->chgBit(oldp+102,((1U & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                            >> 7U))));
            tracep->chgCData(oldp+103,((0x3fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                 >> 0x19U))),6);
            tracep->chgCData(oldp+104,((0xfU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                >> 8U))),4);
            tracep->chgIData(oldp+105,(((((0x80000000U 
                                           & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                           ? 0x7ffffU
                                           : 0U) << 0xdU) 
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
                                                       >> 7U))))))),32);
            tracep->chgIData(oldp+106,((0xfffffU & 
                                        (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                         >> 0xcU))),20);
            tracep->chgSData(oldp+107,(((0x80000000U 
                                         & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                         ? 0x7ffU : 0U)),11);
            tracep->chgCData(oldp+108,((0xffU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                 >> 0xcU))),8);
            tracep->chgBit(oldp+109,((1U & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                            >> 0x14U))));
            tracep->chgSData(oldp+110,((0x3ffU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                  >> 0x15U))),10);
            tracep->chgIData(oldp+111,(((((0x80000000U 
                                           & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                           ? 0x7ffU
                                           : 0U) << 0x15U) 
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
                                                       >> 0x14U))))))),32);
            tracep->chgIData(oldp+112,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_0),32);
            tracep->chgIData(oldp+113,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_1),32);
            tracep->chgIData(oldp+114,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_2),32);
            tracep->chgIData(oldp+115,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_3),32);
            tracep->chgIData(oldp+116,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_4),32);
            tracep->chgIData(oldp+117,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_5),32);
            tracep->chgIData(oldp+118,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_6),32);
            tracep->chgIData(oldp+119,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_7),32);
            tracep->chgIData(oldp+120,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_8),32);
            tracep->chgIData(oldp+121,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_9),32);
            tracep->chgIData(oldp+122,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_10),32);
            tracep->chgIData(oldp+123,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_11),32);
            tracep->chgIData(oldp+124,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_12),32);
            tracep->chgIData(oldp+125,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_13),32);
            tracep->chgIData(oldp+126,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_14),32);
            tracep->chgIData(oldp+127,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_15),32);
            tracep->chgIData(oldp+128,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_16),32);
            tracep->chgIData(oldp+129,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_17),32);
            tracep->chgIData(oldp+130,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_18),32);
            tracep->chgIData(oldp+131,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_19),32);
            tracep->chgIData(oldp+132,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_20),32);
            tracep->chgIData(oldp+133,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_21),32);
            tracep->chgIData(oldp+134,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_22),32);
            tracep->chgIData(oldp+135,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_23),32);
            tracep->chgIData(oldp+136,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_24),32);
            tracep->chgIData(oldp+137,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_25),32);
            tracep->chgIData(oldp+138,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_26),32);
            tracep->chgIData(oldp+139,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_27),32);
            tracep->chgIData(oldp+140,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_28),32);
            tracep->chgIData(oldp+141,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_29),32);
            tracep->chgIData(oldp+142,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_30),32);
            tracep->chgIData(oldp+143,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_31),32);
            tracep->chgIData(oldp+144,((((2U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_extend))
                                          ? (0xfffff000U 
                                             & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                          : vlTOPp->PIPELINE__DOT___ImmValue_T_3) 
                                        + ((0xaU == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                            ? vlTOPp->PIPELINE__DOT__RegFile_io_w_data
                                            : ((9U 
                                                == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                                ? vlTOPp->PIPELINE__DOT__DataMemory_io_dataOut
                                                : (
                                                   (8U 
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
                                                            : 0U))))))))))))),32);
        }
        tracep->chgBit(oldp+145,(vlTOPp->clock));
        tracep->chgBit(oldp+146,(vlTOPp->reset));
        tracep->chgCData(oldp+147,(vlTOPp->io_out),4);
    }
}

void VPIPELINE::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VPIPELINE__Syms* __restrict vlSymsp = static_cast<VPIPELINE__Syms*>(userp);
    VPIPELINE* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
