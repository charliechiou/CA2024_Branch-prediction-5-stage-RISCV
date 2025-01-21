// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VCPU__Syms.h"


void VCPU::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VCPU__Syms* __restrict vlSymsp = static_cast<VCPU__Syms*>(userp);
    VCPU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VCPU::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VCPU__Syms* __restrict vlSymsp = static_cast<VCPU__Syms*>(userp);
    VCPU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+0,(((IData)(vlTOPp->CPU__DOT__HazardDetect_io_pc_forward)
                                       ? ((IData)(4U) 
                                          + vlTOPp->CPU__DOT__PC__DOT__PC)
                                       : ((1U == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                           ? (((IData)(vlTOPp->CPU__DOT__Branch_M_io_flush) 
                                               & (IData)(vlTOPp->CPU__DOT__control_module_io_branch))
                                               ? 0U
                                               : ((IData)(4U) 
                                                  + vlTOPp->CPU__DOT__PC__DOT__PC))
                                           : ((2U == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                               ? 0U
                                               : ((3U 
                                                   == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                                   ? 0U
                                                   : 
                                                  ((IData)(4U) 
                                                   + vlTOPp->CPU__DOT__PC__DOT__PC)))))),32);
            tracep->chgIData(oldp+1,(((IData)(vlTOPp->CPU__DOT__HazardDetect_io_pc_forward)
                                       ? vlTOPp->CPU__DOT__btb_io_target
                                       : ((1U == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                           ? (((IData)(vlTOPp->CPU__DOT__Branch_M_io_flush) 
                                               & (IData)(vlTOPp->CPU__DOT__control_module_io_branch))
                                               ? 0U
                                               : vlTOPp->CPU__DOT__btb_io_target)
                                           : ((2U == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                               ? 0U
                                               : ((3U 
                                                   == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                                   ? 0U
                                                   : vlTOPp->CPU__DOT__btb_io_target))))),32);
            tracep->chgIData(oldp+2,(((IData)(vlTOPp->CPU__DOT__HazardDetect_io_pc_forward)
                                       ? vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data
                                       : ((1U == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                           ? (((IData)(vlTOPp->CPU__DOT__Branch_M_io_flush) 
                                               & (IData)(vlTOPp->CPU__DOT__control_module_io_branch))
                                               ? 0U
                                               : vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data)
                                           : ((2U == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                               ? 0U
                                               : ((3U 
                                                   == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                                   ? 0U
                                                   : vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data))))),32);
            tracep->chgBit(oldp+3,(vlTOPp->CPU__DOT__predictor_io_prediction));
            tracep->chgIData(oldp+4,(vlTOPp->CPU__DOT__IF_ID___DOT__Pc4_In),32);
            tracep->chgIData(oldp+5,(vlTOPp->CPU__DOT__IF_ID___DOT__S_pc),32);
            tracep->chgIData(oldp+6,(vlTOPp->CPU__DOT__IF_ID___DOT__S_instr),32);
            tracep->chgBit(oldp+7,(vlTOPp->CPU__DOT__IF_ID___DOT__io_pred_out_REG));
            tracep->chgCData(oldp+8,(vlTOPp->CPU__DOT__RegFile_io_rs1),5);
            tracep->chgCData(oldp+9,(vlTOPp->CPU__DOT__RegFile_io_rs2),5);
            tracep->chgIData(oldp+10,(((IData)(vlTOPp->CPU__DOT__Structural_io_fwd_rs1)
                                        ? ((IData)(vlTOPp->CPU__DOT__Structural_io_fwd_rs1)
                                            ? vlTOPp->CPU__DOT__RegFile_io_w_data
                                            : 0U) : vlTOPp->CPU__DOT__RegFile_io_rdata1)),32);
            tracep->chgIData(oldp+11,(((IData)(vlTOPp->CPU__DOT__Structural_io_fwd_rs2)
                                        ? ((IData)(vlTOPp->CPU__DOT__Structural_io_fwd_rs2)
                                            ? vlTOPp->CPU__DOT__RegFile_io_w_data
                                            : 0U) : vlTOPp->CPU__DOT__RegFile_io_rdata2)),32);
            tracep->chgIData(oldp+12,(((2U == (IData)(vlTOPp->CPU__DOT__control_module_io_extend))
                                        ? (0xfffff000U 
                                           & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                        : vlTOPp->CPU__DOT___ImmValue_T_3)),32);
            tracep->chgCData(oldp+13,((0x1fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                >> 7U))),5);
            tracep->chgCData(oldp+14,((7U & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                             >> 0xcU))),3);
            tracep->chgBit(oldp+15,((1U & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                           >> 0x1eU))));
            tracep->chgBit(oldp+16,(((~ (IData)(vlTOPp->CPU__DOT__HazardDetect_io_ctrl_forward)) 
                                     & ((0x33U != (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                        & ((0x13U != 
                                            (0x7fU 
                                             & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                           & (0x23U 
                                              == (0x7fU 
                                                  & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)))))));
            tracep->chgBit(oldp+17,(((~ (IData)(vlTOPp->CPU__DOT__HazardDetect_io_ctrl_forward)) 
                                     & ((0x33U != (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                        & (IData)(vlTOPp->CPU__DOT__control_module__DOT___GEN_51)))));
            tracep->chgBit(oldp+18,(((~ (IData)(vlTOPp->CPU__DOT__HazardDetect_io_ctrl_forward)) 
                                     & ((0x33U == (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                        | ((0x13U == 
                                            (0x7fU 
                                             & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                           | ((0x23U 
                                               != (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                              & ((3U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                                 | ((0x63U 
                                                     != 
                                                     (0x7fU 
                                                      & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                                    & ((0x6fU 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                                       | ((0x67U 
                                                           == 
                                                           (0x7fU 
                                                            & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                                          | (IData)(vlTOPp->CPU__DOT__control_module__DOT___GEN_5)))))))))));
            tracep->chgCData(oldp+19,(((IData)(vlTOPp->CPU__DOT__HazardDetect_io_ctrl_forward)
                                        ? 0U : ((0x33U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                 ? 0U
                                                 : 
                                                ((0x13U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                  ? 1U
                                                  : 
                                                 ((0x23U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                   ? 5U
                                                   : 
                                                  ((3U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                    ? 4U
                                                    : 
                                                   ((0x63U 
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
                                                         : 0U))))))))))),3);
            tracep->chgCData(oldp+20,(((0x33U == (0x7fU 
                                                  & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                        ? 0U : ((0x13U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                 ? 0U
                                                 : 
                                                ((0x23U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                  ? 0U
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
                                                        : 0U)))))))))),2);
            tracep->chgBit(oldp+21,(((~ (IData)(vlTOPp->CPU__DOT__HazardDetect_io_ctrl_forward)) 
                                     & ((0x33U != (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                        & ((0x13U == 
                                            (0x7fU 
                                             & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                           | ((0x23U 
                                               == (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                              | ((3U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                                 | ((0x63U 
                                                     != 
                                                     (0x7fU 
                                                      & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                                    & ((0x6fU 
                                                        != 
                                                        (0x7fU 
                                                         & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                                       & ((0x67U 
                                                           != 
                                                           (0x7fU 
                                                            & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                                          & (IData)(vlTOPp->CPU__DOT__control_module__DOT___GEN_5)))))))))));
            tracep->chgCData(oldp+22,(vlTOPp->CPU__DOT__ID_EX___DOT__io_rs1_out_REG),5);
            tracep->chgCData(oldp+23,(vlTOPp->CPU__DOT__ID_EX___DOT__io_rs2_out_REG),5);
            tracep->chgIData(oldp+24,(vlTOPp->CPU__DOT__ID_EX___DOT__io_rs1_data_out_REG),32);
            tracep->chgIData(oldp+25,(vlTOPp->CPU__DOT__ID_EX___DOT__io_rs2_data_out_REG),32);
            tracep->chgCData(oldp+26,(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG),5);
            tracep->chgIData(oldp+27,(vlTOPp->CPU__DOT__ID_EX___DOT__io_imm_out_REG),32);
            tracep->chgCData(oldp+28,(vlTOPp->CPU__DOT__ID_EX___DOT__io_func3_out_REG),3);
            tracep->chgBit(oldp+29,(vlTOPp->CPU__DOT__ID_EX___DOT__io_func7_out_REG));
            tracep->chgBit(oldp+30,(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_MemWr_out_REG));
            tracep->chgBit(oldp+31,(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_MemRd_out_REG));
            tracep->chgBit(oldp+32,(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_Reg_W_out_REG));
            tracep->chgBit(oldp+33,(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_MemToReg_out_REG));
            tracep->chgCData(oldp+34,(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_AluOp_out_REG),3);
            tracep->chgCData(oldp+35,(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_OpA_out_REG),2);
            tracep->chgBit(oldp+36,(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_OpB_out_REG));
            tracep->chgIData(oldp+37,(vlTOPp->CPU__DOT__ID_EX___DOT__io_IFID_pc4_out_REG),32);
            tracep->chgIData(oldp+38,(((0U == (IData)(vlTOPp->CPU__DOT__Forwarding_io_forward_b))
                                        ? vlTOPp->CPU__DOT__ID_EX___DOT__io_rs2_data_out_REG
                                        : vlTOPp->CPU__DOT___GEN_42)),32);
            tracep->chgIData(oldp+39,((IData)(vlTOPp->CPU__DOT__ALU__DOT___GEN_10)),32);
            tracep->chgBit(oldp+40,(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_memRd_out_REG));
            tracep->chgBit(oldp+41,(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_memWr_out_REG));
            tracep->chgBit(oldp+42,(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_memToReg_out_REG));
            tracep->chgBit(oldp+43,(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_reg_w_out_REG));
            tracep->chgIData(oldp+44,(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rs2_out_REG),32);
            tracep->chgCData(oldp+45,(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG),5);
            tracep->chgIData(oldp+46,(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG),32);
            tracep->chgIData(oldp+47,(vlTOPp->CPU__DOT__DataMemory_io_dataOut),32);
            tracep->chgBit(oldp+48,(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_memToReg_out_REG));
            tracep->chgBit(oldp+49,(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG));
            tracep->chgBit(oldp+50,(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_memRd_out_REG));
            tracep->chgCData(oldp+51,(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG),5);
            tracep->chgIData(oldp+52,(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_dataMem_out_REG),32);
            tracep->chgIData(oldp+53,(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_alu_out_REG),32);
            tracep->chgIData(oldp+54,(((IData)(vlTOPp->CPU__DOT__HazardDetect_io_pc_forward)
                                        ? vlTOPp->CPU__DOT__IF_ID___DOT__Pc4_In
                                        : ((1U == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                            ? (((IData)(vlTOPp->CPU__DOT__Branch_M_io_flush) 
                                                & (IData)(vlTOPp->CPU__DOT__control_module_io_branch))
                                                ? ((IData)(vlTOPp->CPU__DOT__Branch_M_io_actual)
                                                    ? vlTOPp->CPU__DOT__IF_ID___DOT__S_pc
                                                    : vlTOPp->CPU__DOT__IF_ID___DOT__Pc4_In)
                                                : vlTOPp->CPU__DOT___PC_io_in_T_5)
                                            : ((2U 
                                                == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                                ? (
                                                   ((((0x80000000U 
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
                                                : (
                                                   (3U 
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
                                                    : vlTOPp->CPU__DOT___PC_io_in_T_5))))),32);
            tracep->chgIData(oldp+55,(vlTOPp->CPU__DOT__PC__DOT__PC),32);
            tracep->chgIData(oldp+56,(((IData)(4U) 
                                       + vlTOPp->CPU__DOT__PC__DOT__PC)),32);
            tracep->chgBit(oldp+57,(vlTOPp->CPU__DOT__Branch_M_io_actual));
            tracep->chgBit(oldp+58,(vlTOPp->CPU__DOT__control_module_io_branch));
            tracep->chgIData(oldp+59,(vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data),32);
            tracep->chgBit(oldp+60,((0x63U == (0x7fU 
                                               & vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data))));
            tracep->chgIData(oldp+61,(vlTOPp->CPU__DOT__btb_io_target),32);
            tracep->chgCData(oldp+62,((0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)),7);
            tracep->chgBit(oldp+63,(((0x33U != (0x7fU 
                                                & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                     & ((0x13U != (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                        & (0x23U == 
                                           (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))))));
            tracep->chgBit(oldp+64,(((0x33U != (0x7fU 
                                                & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                     & (IData)(vlTOPp->CPU__DOT__control_module__DOT___GEN_51))));
            tracep->chgBit(oldp+65,(((0x33U == (0x7fU 
                                                & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                     | ((0x13U == (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                        | ((0x23U != 
                                            (0x7fU 
                                             & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                           & ((3U == 
                                               (0x7fU 
                                                & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                              | ((0x63U 
                                                  != 
                                                  (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                                 & ((0x6fU 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                                    | ((0x67U 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                                       | (IData)(vlTOPp->CPU__DOT__control_module__DOT___GEN_5))))))))));
            tracep->chgCData(oldp+66,(((0x33U == (0x7fU 
                                                  & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                        ? 0U : ((0x13U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                 ? 1U
                                                 : 
                                                ((0x23U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                  ? 5U
                                                  : 
                                                 ((3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                                   ? 4U
                                                   : 
                                                  ((0x63U 
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
                                                        : 0U)))))))))),3);
            tracep->chgBit(oldp+67,(((0x33U != (0x7fU 
                                                & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                     & ((0x13U == (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                        | ((0x23U == 
                                            (0x7fU 
                                             & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                           | ((3U == 
                                               (0x7fU 
                                                & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                              | ((0x63U 
                                                  != 
                                                  (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                                 & ((0x6fU 
                                                     != 
                                                     (0x7fU 
                                                      & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                                    & ((0x67U 
                                                        != 
                                                        (0x7fU 
                                                         & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                                       & (IData)(vlTOPp->CPU__DOT__control_module__DOT___GEN_5))))))))));
            tracep->chgCData(oldp+68,(vlTOPp->CPU__DOT__control_module_io_extend),2);
            tracep->chgCData(oldp+69,(vlTOPp->CPU__DOT__control_module_io_next_pc_sel),2);
            tracep->chgIData(oldp+70,(((((0x80000000U 
                                          & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                          ? 0xfffffU
                                          : 0U) << 0xcU) 
                                       | (0xfffU & 
                                          (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                           >> 0x14U)))),32);
            tracep->chgIData(oldp+71,(((((0x80000000U 
                                          & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                          ? 0xfffffU
                                          : 0U) << 0xcU) 
                                       | ((0xfe0U & 
                                           (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                            >> 0x14U)) 
                                          | (0x1fU 
                                             & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                >> 7U))))),32);
            tracep->chgIData(oldp+72,((0xfffff000U 
                                       & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)),32);
            tracep->chgIData(oldp+73,((((((0x80000000U 
                                           & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                           ? 0x7ffU
                                           : 0U) << 0x15U) 
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
                                       + vlTOPp->CPU__DOT__IF_ID___DOT__S_pc)),32);
            tracep->chgIData(oldp+74,(vlTOPp->CPU__DOT__RegFile_io_w_data),32);
            tracep->chgIData(oldp+75,(vlTOPp->CPU__DOT__RegFile_io_rdata1),32);
            tracep->chgIData(oldp+76,(vlTOPp->CPU__DOT__RegFile_io_rdata2),32);
            tracep->chgCData(oldp+77,((0x1fU & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))),5);
            tracep->chgIData(oldp+78,(vlTOPp->CPU__DOT__ALU_io_in_A),32);
            tracep->chgIData(oldp+79,(vlTOPp->CPU__DOT__ALU_io_in_B),32);
            tracep->chgIData(oldp+80,(vlTOPp->CPU__DOT__Branch_M_io_arg_x),32);
            tracep->chgIData(oldp+81,(vlTOPp->CPU__DOT___Branch_M_io_arg_y_T_7),32);
            tracep->chgBit(oldp+82,(vlTOPp->CPU__DOT__Branch_M_io_flush));
            tracep->chgIData(oldp+83,(((0xaU == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                        ? vlTOPp->CPU__DOT__RegFile_io_w_data
                                        : ((9U == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                            ? vlTOPp->CPU__DOT__DataMemory_io_dataOut
                                            : ((8U 
                                                == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                ? vlTOPp->CPU__DOT__RegFile_io_w_data
                                                : (
                                                   (7U 
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
                                                           : 0U)))))))))))),32);
            tracep->chgIData(oldp+84,((0xfffffffeU 
                                       & (((2U == (IData)(vlTOPp->CPU__DOT__control_module_io_extend))
                                            ? (0xfffff000U 
                                               & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                            : vlTOPp->CPU__DOT___ImmValue_T_3) 
                                          + ((0xaU 
                                              == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                              ? vlTOPp->CPU__DOT__RegFile_io_w_data
                                              : ((9U 
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
                                                           : 0U)))))))))))))),32);
            tracep->chgCData(oldp+85,(vlTOPp->CPU__DOT__Forwarding_io_forward_a),2);
            tracep->chgCData(oldp+86,(vlTOPp->CPU__DOT__Forwarding_io_forward_b),2);
            tracep->chgBit(oldp+87,(vlTOPp->CPU__DOT__HazardDetect_io_pc_forward));
            tracep->chgBit(oldp+88,(vlTOPp->CPU__DOT__HazardDetect_io_ctrl_forward));
            tracep->chgCData(oldp+89,((0x1fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                >> 0xfU))),5);
            tracep->chgCData(oldp+90,((0x1fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                >> 0x14U))),5);
            tracep->chgCData(oldp+91,(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1),4);
            tracep->chgCData(oldp+92,(vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_28),4);
            tracep->chgBit(oldp+93,(vlTOPp->CPU__DOT__Structural_io_fwd_rs1));
            tracep->chgBit(oldp+94,(vlTOPp->CPU__DOT__Structural_io_fwd_rs2));
            tracep->chgIData(oldp+95,(vlTOPp->CPU__DOT__d),32);
            tracep->chgCData(oldp+96,(vlTOPp->CPU__DOT__predictor__DOT__currentState),2);
            tracep->chgIData(oldp+97,(((0x80000000U 
                                        & vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data)
                                        ? 0x7ffffU : 0U)),19);
            tracep->chgBit(oldp+98,((1U & (vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data 
                                           >> 7U))));
            tracep->chgCData(oldp+99,((0x3fU & (vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data 
                                                >> 0x19U))),6);
            tracep->chgCData(oldp+100,((0xfU & (vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data 
                                                >> 8U))),4);
            tracep->chgSData(oldp+101,((0xfffU & (vlTOPp->CPU__DOT__PC__DOT__PC 
                                                  >> 2U))),12);
            tracep->chgIData(oldp+102,(((0x800U >= 
                                         (0xfffU & vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG))
                                         ? vlTOPp->CPU__DOT__DataMemory__DOT__Dmemory
                                        [(0xfffU & vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG)]
                                         : 0U)),32);
            tracep->chgSData(oldp+103,((0xfffU & vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG)),12);
            tracep->chgIData(oldp+104,(((0x80000000U 
                                         & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                         ? 0xfffffU
                                         : 0U)),20);
            tracep->chgSData(oldp+105,((0xfffU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                  >> 0x14U))),12);
            tracep->chgCData(oldp+106,((0x7fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                 >> 0x19U))),7);
            tracep->chgIData(oldp+107,((0xfffffU & 
                                        (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                         >> 0xcU))),20);
            tracep->chgSData(oldp+108,(((0x80000000U 
                                         & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                         ? 0x7ffU : 0U)),11);
            tracep->chgCData(oldp+109,((0xffU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                 >> 0xcU))),8);
            tracep->chgBit(oldp+110,((1U & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                            >> 0x14U))));
            tracep->chgSData(oldp+111,((0x3ffU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                  >> 0x15U))),10);
            tracep->chgIData(oldp+112,(((((0x80000000U 
                                           & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                           ? 0x7ffU
                                           : 0U) << 0x15U) 
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
                                                       >> 0x14U))))))),32);
            tracep->chgIData(oldp+113,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_0),32);
            tracep->chgIData(oldp+114,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_1),32);
            tracep->chgIData(oldp+115,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_2),32);
            tracep->chgIData(oldp+116,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_3),32);
            tracep->chgIData(oldp+117,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_4),32);
            tracep->chgIData(oldp+118,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_5),32);
            tracep->chgIData(oldp+119,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_6),32);
            tracep->chgIData(oldp+120,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_7),32);
            tracep->chgIData(oldp+121,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_8),32);
            tracep->chgIData(oldp+122,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_9),32);
            tracep->chgIData(oldp+123,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_10),32);
            tracep->chgIData(oldp+124,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_11),32);
            tracep->chgIData(oldp+125,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_12),32);
            tracep->chgIData(oldp+126,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_13),32);
            tracep->chgIData(oldp+127,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_14),32);
            tracep->chgIData(oldp+128,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_15),32);
            tracep->chgIData(oldp+129,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_16),32);
            tracep->chgIData(oldp+130,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_17),32);
            tracep->chgIData(oldp+131,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_18),32);
            tracep->chgIData(oldp+132,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_19),32);
            tracep->chgIData(oldp+133,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_20),32);
            tracep->chgIData(oldp+134,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_21),32);
            tracep->chgIData(oldp+135,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_22),32);
            tracep->chgIData(oldp+136,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_23),32);
            tracep->chgIData(oldp+137,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_24),32);
            tracep->chgIData(oldp+138,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_25),32);
            tracep->chgIData(oldp+139,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_26),32);
            tracep->chgIData(oldp+140,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_27),32);
            tracep->chgIData(oldp+141,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_28),32);
            tracep->chgIData(oldp+142,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_29),32);
            tracep->chgIData(oldp+143,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_30),32);
            tracep->chgIData(oldp+144,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_31),32);
            tracep->chgIData(oldp+145,((((2U == (IData)(vlTOPp->CPU__DOT__control_module_io_extend))
                                          ? (0xfffff000U 
                                             & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                          : vlTOPp->CPU__DOT___ImmValue_T_3) 
                                        + ((0xaU == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                            ? vlTOPp->CPU__DOT__RegFile_io_w_data
                                            : ((9U 
                                                == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                                ? vlTOPp->CPU__DOT__DataMemory_io_dataOut
                                                : (
                                                   (8U 
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
                                                            : 0U))))))))))))),32);
        }
        tracep->chgBit(oldp+146,(vlTOPp->clock));
        tracep->chgBit(oldp+147,(vlTOPp->reset));
        tracep->chgCData(oldp+148,(vlTOPp->io_out),4);
    }
}

void VCPU::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VCPU__Syms* __restrict vlSymsp = static_cast<VCPU__Syms*>(userp);
    VCPU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
