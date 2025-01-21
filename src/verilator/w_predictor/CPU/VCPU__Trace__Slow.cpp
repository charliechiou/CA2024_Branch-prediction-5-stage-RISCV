// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VCPU__Syms.h"


//======================

void VCPU::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VCPU::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VCPU__Syms* __restrict vlSymsp = static_cast<VCPU__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VCPU::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VCPU::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VCPU__Syms* __restrict vlSymsp = static_cast<VCPU__Syms*>(userp);
    VCPU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VCPU::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VCPU__Syms* __restrict vlSymsp = static_cast<VCPU__Syms*>(userp);
    VCPU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+147,"clock", false,-1);
        tracep->declBit(c+148,"reset", false,-1);
        tracep->declBus(c+149,"io_out", false,-1, 3,0);
        tracep->declBit(c+147,"CPU clock", false,-1);
        tracep->declBit(c+148,"CPU reset", false,-1);
        tracep->declBus(c+149,"CPU io_out", false,-1, 3,0);
        tracep->declBit(c+147,"CPU IF_ID__clock", false,-1);
        tracep->declBit(c+148,"CPU IF_ID__reset", false,-1);
        tracep->declBus(c+1,"CPU IF_ID__io_pc4_in", false,-1, 31,0);
        tracep->declBus(c+2,"CPU IF_ID__io_target", false,-1, 31,0);
        tracep->declBus(c+3,"CPU IF_ID__io_SelectedInstr", false,-1, 31,0);
        tracep->declBit(c+4,"CPU IF_ID__io_pred_in", false,-1);
        tracep->declBus(c+5,"CPU IF_ID__io_pc4_out", false,-1, 31,0);
        tracep->declBus(c+6,"CPU IF_ID__io_target_old", false,-1, 31,0);
        tracep->declBus(c+7,"CPU IF_ID__io_SelectedInstr_out", false,-1, 31,0);
        tracep->declBit(c+8,"CPU IF_ID__io_pred_out", false,-1);
        tracep->declBit(c+147,"CPU ID_EX__clock", false,-1);
        tracep->declBus(c+9,"CPU ID_EX__io_rs1_in", false,-1, 4,0);
        tracep->declBus(c+10,"CPU ID_EX__io_rs2_in", false,-1, 4,0);
        tracep->declBus(c+11,"CPU ID_EX__io_rs1_data_in", false,-1, 31,0);
        tracep->declBus(c+12,"CPU ID_EX__io_rs2_data_in", false,-1, 31,0);
        tracep->declBus(c+13,"CPU ID_EX__io_imm", false,-1, 31,0);
        tracep->declBus(c+14,"CPU ID_EX__io_rd_in", false,-1, 4,0);
        tracep->declBus(c+15,"CPU ID_EX__io_func3_in", false,-1, 2,0);
        tracep->declBit(c+16,"CPU ID_EX__io_func7_in", false,-1);
        tracep->declBit(c+17,"CPU ID_EX__io_ctrl_MemWr_in", false,-1);
        tracep->declBit(c+18,"CPU ID_EX__io_ctrl_MemRd_in", false,-1);
        tracep->declBit(c+19,"CPU ID_EX__io_ctrl_Reg_W_in", false,-1);
        tracep->declBit(c+18,"CPU ID_EX__io_ctrl_MemToReg_in", false,-1);
        tracep->declBus(c+20,"CPU ID_EX__io_ctrl_AluOp_in", false,-1, 2,0);
        tracep->declBus(c+21,"CPU ID_EX__io_ctrl_OpA_in", false,-1, 1,0);
        tracep->declBit(c+22,"CPU ID_EX__io_ctrl_OpB_in", false,-1);
        tracep->declBus(c+5,"CPU ID_EX__io_IFID_pc4_in", false,-1, 31,0);
        tracep->declBus(c+23,"CPU ID_EX__io_rs1_out", false,-1, 4,0);
        tracep->declBus(c+24,"CPU ID_EX__io_rs2_out", false,-1, 4,0);
        tracep->declBus(c+25,"CPU ID_EX__io_rs1_data_out", false,-1, 31,0);
        tracep->declBus(c+26,"CPU ID_EX__io_rs2_data_out", false,-1, 31,0);
        tracep->declBus(c+27,"CPU ID_EX__io_rd_out", false,-1, 4,0);
        tracep->declBus(c+28,"CPU ID_EX__io_imm_out", false,-1, 31,0);
        tracep->declBus(c+29,"CPU ID_EX__io_func3_out", false,-1, 2,0);
        tracep->declBit(c+30,"CPU ID_EX__io_func7_out", false,-1);
        tracep->declBit(c+31,"CPU ID_EX__io_ctrl_MemWr_out", false,-1);
        tracep->declBit(c+32,"CPU ID_EX__io_ctrl_MemRd_out", false,-1);
        tracep->declBit(c+33,"CPU ID_EX__io_ctrl_Reg_W_out", false,-1);
        tracep->declBit(c+34,"CPU ID_EX__io_ctrl_MemToReg_out", false,-1);
        tracep->declBus(c+35,"CPU ID_EX__io_ctrl_AluOp_out", false,-1, 2,0);
        tracep->declBus(c+36,"CPU ID_EX__io_ctrl_OpA_out", false,-1, 1,0);
        tracep->declBit(c+37,"CPU ID_EX__io_ctrl_OpB_out", false,-1);
        tracep->declBus(c+38,"CPU ID_EX__io_IFID_pc4_out", false,-1, 31,0);
        tracep->declBit(c+147,"CPU EX_MEM_M_clock", false,-1);
        tracep->declBit(c+32,"CPU EX_MEM_M_io_IDEX_MEMRD", false,-1);
        tracep->declBit(c+31,"CPU EX_MEM_M_io_IDEX_MEMWR", false,-1);
        tracep->declBit(c+34,"CPU EX_MEM_M_io_IDEX_MEMTOREG", false,-1);
        tracep->declBit(c+33,"CPU EX_MEM_M_io_IDEX_REG_W", false,-1);
        tracep->declBus(c+39,"CPU EX_MEM_M_io_IDEX_rs2", false,-1, 31,0);
        tracep->declBus(c+27,"CPU EX_MEM_M_io_IDEX_rd", false,-1, 4,0);
        tracep->declBus(c+40,"CPU EX_MEM_M_io_alu_out", false,-1, 31,0);
        tracep->declBit(c+41,"CPU EX_MEM_M_io_EXMEM_memRd_out", false,-1);
        tracep->declBit(c+42,"CPU EX_MEM_M_io_EXMEM_memWr_out", false,-1);
        tracep->declBit(c+43,"CPU EX_MEM_M_io_EXMEM_memToReg_out", false,-1);
        tracep->declBit(c+44,"CPU EX_MEM_M_io_EXMEM_reg_w_out", false,-1);
        tracep->declBus(c+45,"CPU EX_MEM_M_io_EXMEM_rs2_out", false,-1, 31,0);
        tracep->declBus(c+46,"CPU EX_MEM_M_io_EXMEM_rd_out", false,-1, 4,0);
        tracep->declBus(c+47,"CPU EX_MEM_M_io_EXMEM_alu_out", false,-1, 31,0);
        tracep->declBit(c+147,"CPU MEM_WB_M_clock", false,-1);
        tracep->declBit(c+43,"CPU MEM_WB_M_io_EXMEM_MEMTOREG", false,-1);
        tracep->declBit(c+44,"CPU MEM_WB_M_io_EXMEM_REG_W", false,-1);
        tracep->declBit(c+41,"CPU MEM_WB_M_io_EXMEM_MEMRD", false,-1);
        tracep->declBus(c+46,"CPU MEM_WB_M_io_EXMEM_rd", false,-1, 4,0);
        tracep->declBus(c+48,"CPU MEM_WB_M_io_in_dataMem_out", false,-1, 31,0);
        tracep->declBus(c+47,"CPU MEM_WB_M_io_in_alu_out", false,-1, 31,0);
        tracep->declBit(c+49,"CPU MEM_WB_M_io_MEMWB_memToReg_out", false,-1);
        tracep->declBit(c+50,"CPU MEM_WB_M_io_MEMWB_reg_w_out", false,-1);
        tracep->declBit(c+51,"CPU MEM_WB_M_io_MEMWB_memRd_out", false,-1);
        tracep->declBus(c+52,"CPU MEM_WB_M_io_MEMWB_rd_out", false,-1, 4,0);
        tracep->declBus(c+53,"CPU MEM_WB_M_io_MEMWB_dataMem_out", false,-1, 31,0);
        tracep->declBus(c+54,"CPU MEM_WB_M_io_MEMWB_alu_out", false,-1, 31,0);
        tracep->declBit(c+147,"CPU PC_clock", false,-1);
        tracep->declBit(c+148,"CPU PC_reset", false,-1);
        tracep->declBus(c+55,"CPU PC_io_in", false,-1, 31,0);
        tracep->declBus(c+56,"CPU PC_io_out", false,-1, 31,0);
        tracep->declBus(c+56,"CPU PC4_io_pc", false,-1, 31,0);
        tracep->declBus(c+57,"CPU PC4_io_out", false,-1, 31,0);
        tracep->declBit(c+147,"CPU predictor_clock", false,-1);
        tracep->declBit(c+148,"CPU predictor_reset", false,-1);
        tracep->declBit(c+58,"CPU predictor_io_taken", false,-1);
        tracep->declBit(c+59,"CPU predictor_io_isBtype", false,-1);
        tracep->declBit(c+4,"CPU predictor_io_prediction", false,-1);
        tracep->declBus(c+60,"CPU btb_io_inst", false,-1, 31,0);
        tracep->declBus(c+56,"CPU btb_io_PC", false,-1, 31,0);
        tracep->declBit(c+61,"CPU btb_io_isBtype", false,-1);
        tracep->declBus(c+62,"CPU btb_io_target", false,-1, 31,0);
        tracep->declBit(c+147,"CPU InstMemory_clock", false,-1);
        tracep->declBus(c+56,"CPU InstMemory_io_addr", false,-1, 31,0);
        tracep->declBus(c+60,"CPU InstMemory_io_data", false,-1, 31,0);
        tracep->declBit(c+147,"CPU DataMemory_clock", false,-1);
        tracep->declBus(c+47,"CPU DataMemory_io_addr", false,-1, 31,0);
        tracep->declBus(c+45,"CPU DataMemory_io_dataIn", false,-1, 31,0);
        tracep->declBit(c+41,"CPU DataMemory_io_mem_read", false,-1);
        tracep->declBit(c+42,"CPU DataMemory_io_mem_write", false,-1);
        tracep->declBus(c+48,"CPU DataMemory_io_dataOut", false,-1, 31,0);
        tracep->declBus(c+63,"CPU control_module_io_opcode", false,-1, 6,0);
        tracep->declBit(c+64,"CPU control_module_io_mem_write", false,-1);
        tracep->declBit(c+59,"CPU control_module_io_branch", false,-1);
        tracep->declBit(c+65,"CPU control_module_io_mem_read", false,-1);
        tracep->declBit(c+66,"CPU control_module_io_reg_write", false,-1);
        tracep->declBit(c+65,"CPU control_module_io_men_to_reg", false,-1);
        tracep->declBus(c+67,"CPU control_module_io_alu_operation", false,-1, 2,0);
        tracep->declBus(c+21,"CPU control_module_io_operand_A", false,-1, 1,0);
        tracep->declBit(c+68,"CPU control_module_io_operand_B", false,-1);
        tracep->declBus(c+69,"CPU control_module_io_extend", false,-1, 1,0);
        tracep->declBus(c+70,"CPU control_module_io_next_pc_sel", false,-1, 1,0);
        tracep->declBus(c+7,"CPU ImmGen_io_instr", false,-1, 31,0);
        tracep->declBus(c+6,"CPU ImmGen_io_pc", false,-1, 31,0);
        tracep->declBus(c+71,"CPU ImmGen_io_I_type", false,-1, 31,0);
        tracep->declBus(c+72,"CPU ImmGen_io_S_type", false,-1, 31,0);
        tracep->declBus(c+73,"CPU ImmGen_io_U_type", false,-1, 31,0);
        tracep->declBus(c+74,"CPU ImmGen_io_UJ_type", false,-1, 31,0);
        tracep->declBit(c+147,"CPU RegFile_clock", false,-1);
        tracep->declBit(c+148,"CPU RegFile_reset", false,-1);
        tracep->declBus(c+9,"CPU RegFile_io_rs1", false,-1, 4,0);
        tracep->declBus(c+10,"CPU RegFile_io_rs2", false,-1, 4,0);
        tracep->declBit(c+50,"CPU RegFile_io_reg_write", false,-1);
        tracep->declBus(c+52,"CPU RegFile_io_w_reg", false,-1, 4,0);
        tracep->declBus(c+75,"CPU RegFile_io_w_data", false,-1, 31,0);
        tracep->declBus(c+76,"CPU RegFile_io_rdata1", false,-1, 31,0);
        tracep->declBus(c+77,"CPU RegFile_io_rdata2", false,-1, 31,0);
        tracep->declBus(c+29,"CPU ALU_Control_io_func3", false,-1, 2,0);
        tracep->declBit(c+30,"CPU ALU_Control_io_func7", false,-1);
        tracep->declBus(c+35,"CPU ALU_Control_io_aluOp", false,-1, 2,0);
        tracep->declBus(c+78,"CPU ALU_Control_io_out", false,-1, 4,0);
        tracep->declBus(c+79,"CPU ALU_io_in_A", false,-1, 31,0);
        tracep->declBus(c+80,"CPU ALU_io_in_B", false,-1, 31,0);
        tracep->declBus(c+78,"CPU ALU_io_alu_Op", false,-1, 4,0);
        tracep->declBus(c+40,"CPU ALU_io_out", false,-1, 31,0);
        tracep->declBus(c+15,"CPU Branch_M_io_fnct3", false,-1, 2,0);
        tracep->declBit(c+59,"CPU Branch_M_io_branch", false,-1);
        tracep->declBus(c+81,"CPU Branch_M_io_arg_x", false,-1, 31,0);
        tracep->declBus(c+82,"CPU Branch_M_io_arg_y", false,-1, 31,0);
        tracep->declBit(c+8,"CPU Branch_M_io_pred", false,-1);
        tracep->declBit(c+58,"CPU Branch_M_io_actual", false,-1);
        tracep->declBit(c+83,"CPU Branch_M_io_flush", false,-1);
        tracep->declBus(c+13,"CPU JALR_io_imme", false,-1, 31,0);
        tracep->declBus(c+84,"CPU JALR_io_rdata1", false,-1, 31,0);
        tracep->declBus(c+85,"CPU JALR_io_out", false,-1, 31,0);
        tracep->declBus(c+23,"CPU Forwarding_io_IDEX_rs1", false,-1, 4,0);
        tracep->declBus(c+24,"CPU Forwarding_io_IDEX_rs2", false,-1, 4,0);
        tracep->declBus(c+46,"CPU Forwarding_io_EXMEM_rd", false,-1, 4,0);
        tracep->declBit(c+44,"CPU Forwarding_io_EXMEM_regWr", false,-1);
        tracep->declBus(c+52,"CPU Forwarding_io_MEMWB_rd", false,-1, 4,0);
        tracep->declBit(c+50,"CPU Forwarding_io_MEMWB_regWr", false,-1);
        tracep->declBus(c+86,"CPU Forwarding_io_forward_a", false,-1, 1,0);
        tracep->declBus(c+87,"CPU Forwarding_io_forward_b", false,-1, 1,0);
        tracep->declBus(c+7,"CPU HazardDetect_io_IF_ID_inst", false,-1, 31,0);
        tracep->declBit(c+32,"CPU HazardDetect_io_ID_EX_memRead", false,-1);
        tracep->declBus(c+27,"CPU HazardDetect_io_ID_EX_rd", false,-1, 4,0);
        tracep->declBus(c+5,"CPU HazardDetect_io_pc_in", false,-1, 31,0);
        tracep->declBit(c+88,"CPU HazardDetect_io_pc_forward", false,-1);
        tracep->declBit(c+89,"CPU HazardDetect_io_ctrl_forward", false,-1);
        tracep->declBus(c+5,"CPU HazardDetect_io_pc_out", false,-1, 31,0);
        tracep->declBus(c+27,"CPU Branch_Forward_io_ID_EX_RD", false,-1, 4,0);
        tracep->declBus(c+46,"CPU Branch_Forward_io_EX_MEM_RD", false,-1, 4,0);
        tracep->declBus(c+52,"CPU Branch_Forward_io_MEM_WB_RD", false,-1, 4,0);
        tracep->declBit(c+32,"CPU Branch_Forward_io_ID_EX_memRd", false,-1);
        tracep->declBit(c+41,"CPU Branch_Forward_io_EX_MEM_memRd", false,-1);
        tracep->declBit(c+51,"CPU Branch_Forward_io_MEM_WB_memRd", false,-1);
        tracep->declBus(c+90,"CPU Branch_Forward_io_rs1", false,-1, 4,0);
        tracep->declBus(c+91,"CPU Branch_Forward_io_rs2", false,-1, 4,0);
        tracep->declBit(c+59,"CPU Branch_Forward_io_ctrl_branch", false,-1);
        tracep->declBus(c+92,"CPU Branch_Forward_io_forward_rs1", false,-1, 3,0);
        tracep->declBus(c+93,"CPU Branch_Forward_io_forward_rs2", false,-1, 3,0);
        tracep->declBus(c+90,"CPU Structural_io_rs1", false,-1, 4,0);
        tracep->declBus(c+91,"CPU Structural_io_rs2", false,-1, 4,0);
        tracep->declBit(c+44,"CPU Structural_io_MEM_WB_regWr", false,-1);
        tracep->declBus(c+52,"CPU Structural_io_MEM_WB_Rd", false,-1, 4,0);
        tracep->declBit(c+94,"CPU Structural_io_fwd_rs1", false,-1);
        tracep->declBit(c+95,"CPU Structural_io_fwd_rs2", false,-1);
        tracep->declBus(c+96,"CPU d", false,-1, 31,0);
        tracep->declBus(c+39,"CPU RS2_value", false,-1, 31,0);
        tracep->declBit(c+147,"CPU IF_ID_ clock", false,-1);
        tracep->declBit(c+148,"CPU IF_ID_ reset", false,-1);
        tracep->declBus(c+1,"CPU IF_ID_ io_pc4_in", false,-1, 31,0);
        tracep->declBus(c+2,"CPU IF_ID_ io_target", false,-1, 31,0);
        tracep->declBus(c+3,"CPU IF_ID_ io_SelectedInstr", false,-1, 31,0);
        tracep->declBit(c+4,"CPU IF_ID_ io_pred_in", false,-1);
        tracep->declBus(c+5,"CPU IF_ID_ io_pc4_out", false,-1, 31,0);
        tracep->declBus(c+6,"CPU IF_ID_ io_target_old", false,-1, 31,0);
        tracep->declBus(c+7,"CPU IF_ID_ io_SelectedInstr_out", false,-1, 31,0);
        tracep->declBit(c+8,"CPU IF_ID_ io_pred_out", false,-1);
        tracep->declBus(c+5,"CPU IF_ID_ Pc4_In", false,-1, 31,0);
        tracep->declBus(c+6,"CPU IF_ID_ S_pc", false,-1, 31,0);
        tracep->declBus(c+7,"CPU IF_ID_ S_instr", false,-1, 31,0);
        tracep->declBit(c+8,"CPU IF_ID_ io_pred_out_REG", false,-1);
        tracep->declBit(c+147,"CPU ID_EX_ clock", false,-1);
        tracep->declBus(c+9,"CPU ID_EX_ io_rs1_in", false,-1, 4,0);
        tracep->declBus(c+10,"CPU ID_EX_ io_rs2_in", false,-1, 4,0);
        tracep->declBus(c+11,"CPU ID_EX_ io_rs1_data_in", false,-1, 31,0);
        tracep->declBus(c+12,"CPU ID_EX_ io_rs2_data_in", false,-1, 31,0);
        tracep->declBus(c+13,"CPU ID_EX_ io_imm", false,-1, 31,0);
        tracep->declBus(c+14,"CPU ID_EX_ io_rd_in", false,-1, 4,0);
        tracep->declBus(c+15,"CPU ID_EX_ io_func3_in", false,-1, 2,0);
        tracep->declBit(c+16,"CPU ID_EX_ io_func7_in", false,-1);
        tracep->declBit(c+17,"CPU ID_EX_ io_ctrl_MemWr_in", false,-1);
        tracep->declBit(c+18,"CPU ID_EX_ io_ctrl_MemRd_in", false,-1);
        tracep->declBit(c+19,"CPU ID_EX_ io_ctrl_Reg_W_in", false,-1);
        tracep->declBit(c+18,"CPU ID_EX_ io_ctrl_MemToReg_in", false,-1);
        tracep->declBus(c+20,"CPU ID_EX_ io_ctrl_AluOp_in", false,-1, 2,0);
        tracep->declBus(c+21,"CPU ID_EX_ io_ctrl_OpA_in", false,-1, 1,0);
        tracep->declBit(c+22,"CPU ID_EX_ io_ctrl_OpB_in", false,-1);
        tracep->declBus(c+5,"CPU ID_EX_ io_IFID_pc4_in", false,-1, 31,0);
        tracep->declBus(c+23,"CPU ID_EX_ io_rs1_out", false,-1, 4,0);
        tracep->declBus(c+24,"CPU ID_EX_ io_rs2_out", false,-1, 4,0);
        tracep->declBus(c+25,"CPU ID_EX_ io_rs1_data_out", false,-1, 31,0);
        tracep->declBus(c+26,"CPU ID_EX_ io_rs2_data_out", false,-1, 31,0);
        tracep->declBus(c+27,"CPU ID_EX_ io_rd_out", false,-1, 4,0);
        tracep->declBus(c+28,"CPU ID_EX_ io_imm_out", false,-1, 31,0);
        tracep->declBus(c+29,"CPU ID_EX_ io_func3_out", false,-1, 2,0);
        tracep->declBit(c+30,"CPU ID_EX_ io_func7_out", false,-1);
        tracep->declBit(c+31,"CPU ID_EX_ io_ctrl_MemWr_out", false,-1);
        tracep->declBit(c+32,"CPU ID_EX_ io_ctrl_MemRd_out", false,-1);
        tracep->declBit(c+33,"CPU ID_EX_ io_ctrl_Reg_W_out", false,-1);
        tracep->declBit(c+34,"CPU ID_EX_ io_ctrl_MemToReg_out", false,-1);
        tracep->declBus(c+35,"CPU ID_EX_ io_ctrl_AluOp_out", false,-1, 2,0);
        tracep->declBus(c+36,"CPU ID_EX_ io_ctrl_OpA_out", false,-1, 1,0);
        tracep->declBit(c+37,"CPU ID_EX_ io_ctrl_OpB_out", false,-1);
        tracep->declBus(c+38,"CPU ID_EX_ io_IFID_pc4_out", false,-1, 31,0);
        tracep->declBus(c+23,"CPU ID_EX_ io_rs1_out_REG", false,-1, 4,0);
        tracep->declBus(c+24,"CPU ID_EX_ io_rs2_out_REG", false,-1, 4,0);
        tracep->declBus(c+25,"CPU ID_EX_ io_rs1_data_out_REG", false,-1, 31,0);
        tracep->declBus(c+26,"CPU ID_EX_ io_rs2_data_out_REG", false,-1, 31,0);
        tracep->declBus(c+28,"CPU ID_EX_ io_imm_out_REG", false,-1, 31,0);
        tracep->declBus(c+27,"CPU ID_EX_ io_rd_out_REG", false,-1, 4,0);
        tracep->declBus(c+29,"CPU ID_EX_ io_func3_out_REG", false,-1, 2,0);
        tracep->declBit(c+30,"CPU ID_EX_ io_func7_out_REG", false,-1);
        tracep->declBit(c+31,"CPU ID_EX_ io_ctrl_MemWr_out_REG", false,-1);
        tracep->declBit(c+32,"CPU ID_EX_ io_ctrl_MemRd_out_REG", false,-1);
        tracep->declBit(c+33,"CPU ID_EX_ io_ctrl_Reg_W_out_REG", false,-1);
        tracep->declBit(c+34,"CPU ID_EX_ io_ctrl_MemToReg_out_REG", false,-1);
        tracep->declBus(c+35,"CPU ID_EX_ io_ctrl_AluOp_out_REG", false,-1, 2,0);
        tracep->declBus(c+36,"CPU ID_EX_ io_ctrl_OpA_out_REG", false,-1, 1,0);
        tracep->declBit(c+37,"CPU ID_EX_ io_ctrl_OpB_out_REG", false,-1);
        tracep->declBus(c+38,"CPU ID_EX_ io_IFID_pc4_out_REG", false,-1, 31,0);
        tracep->declBit(c+147,"CPU EX_MEM_M clock", false,-1);
        tracep->declBit(c+32,"CPU EX_MEM_M io_IDEX_MEMRD", false,-1);
        tracep->declBit(c+31,"CPU EX_MEM_M io_IDEX_MEMWR", false,-1);
        tracep->declBit(c+34,"CPU EX_MEM_M io_IDEX_MEMTOREG", false,-1);
        tracep->declBit(c+33,"CPU EX_MEM_M io_IDEX_REG_W", false,-1);
        tracep->declBus(c+39,"CPU EX_MEM_M io_IDEX_rs2", false,-1, 31,0);
        tracep->declBus(c+27,"CPU EX_MEM_M io_IDEX_rd", false,-1, 4,0);
        tracep->declBus(c+40,"CPU EX_MEM_M io_alu_out", false,-1, 31,0);
        tracep->declBit(c+41,"CPU EX_MEM_M io_EXMEM_memRd_out", false,-1);
        tracep->declBit(c+42,"CPU EX_MEM_M io_EXMEM_memWr_out", false,-1);
        tracep->declBit(c+43,"CPU EX_MEM_M io_EXMEM_memToReg_out", false,-1);
        tracep->declBit(c+44,"CPU EX_MEM_M io_EXMEM_reg_w_out", false,-1);
        tracep->declBus(c+45,"CPU EX_MEM_M io_EXMEM_rs2_out", false,-1, 31,0);
        tracep->declBus(c+46,"CPU EX_MEM_M io_EXMEM_rd_out", false,-1, 4,0);
        tracep->declBus(c+47,"CPU EX_MEM_M io_EXMEM_alu_out", false,-1, 31,0);
        tracep->declBit(c+41,"CPU EX_MEM_M io_EXMEM_memRd_out_REG", false,-1);
        tracep->declBit(c+42,"CPU EX_MEM_M io_EXMEM_memWr_out_REG", false,-1);
        tracep->declBit(c+43,"CPU EX_MEM_M io_EXMEM_memToReg_out_REG", false,-1);
        tracep->declBit(c+44,"CPU EX_MEM_M io_EXMEM_reg_w_out_REG", false,-1);
        tracep->declBus(c+45,"CPU EX_MEM_M io_EXMEM_rs2_out_REG", false,-1, 31,0);
        tracep->declBus(c+46,"CPU EX_MEM_M io_EXMEM_rd_out_REG", false,-1, 4,0);
        tracep->declBus(c+47,"CPU EX_MEM_M io_EXMEM_alu_out_REG", false,-1, 31,0);
        tracep->declBit(c+147,"CPU MEM_WB_M clock", false,-1);
        tracep->declBit(c+43,"CPU MEM_WB_M io_EXMEM_MEMTOREG", false,-1);
        tracep->declBit(c+44,"CPU MEM_WB_M io_EXMEM_REG_W", false,-1);
        tracep->declBit(c+41,"CPU MEM_WB_M io_EXMEM_MEMRD", false,-1);
        tracep->declBus(c+46,"CPU MEM_WB_M io_EXMEM_rd", false,-1, 4,0);
        tracep->declBus(c+48,"CPU MEM_WB_M io_in_dataMem_out", false,-1, 31,0);
        tracep->declBus(c+47,"CPU MEM_WB_M io_in_alu_out", false,-1, 31,0);
        tracep->declBit(c+49,"CPU MEM_WB_M io_MEMWB_memToReg_out", false,-1);
        tracep->declBit(c+50,"CPU MEM_WB_M io_MEMWB_reg_w_out", false,-1);
        tracep->declBit(c+51,"CPU MEM_WB_M io_MEMWB_memRd_out", false,-1);
        tracep->declBus(c+52,"CPU MEM_WB_M io_MEMWB_rd_out", false,-1, 4,0);
        tracep->declBus(c+53,"CPU MEM_WB_M io_MEMWB_dataMem_out", false,-1, 31,0);
        tracep->declBus(c+54,"CPU MEM_WB_M io_MEMWB_alu_out", false,-1, 31,0);
        tracep->declBit(c+49,"CPU MEM_WB_M io_MEMWB_memToReg_out_REG", false,-1);
        tracep->declBit(c+50,"CPU MEM_WB_M io_MEMWB_reg_w_out_REG", false,-1);
        tracep->declBit(c+51,"CPU MEM_WB_M io_MEMWB_memRd_out_REG", false,-1);
        tracep->declBus(c+52,"CPU MEM_WB_M io_MEMWB_rd_out_REG", false,-1, 4,0);
        tracep->declBus(c+53,"CPU MEM_WB_M io_MEMWB_dataMem_out_REG", false,-1, 31,0);
        tracep->declBus(c+54,"CPU MEM_WB_M io_MEMWB_alu_out_REG", false,-1, 31,0);
        tracep->declBit(c+147,"CPU PC clock", false,-1);
        tracep->declBit(c+148,"CPU PC reset", false,-1);
        tracep->declBus(c+55,"CPU PC io_in", false,-1, 31,0);
        tracep->declBus(c+56,"CPU PC io_out", false,-1, 31,0);
        tracep->declBus(c+56,"CPU PC PC", false,-1, 31,0);
        tracep->declBus(c+56,"CPU PC4 io_pc", false,-1, 31,0);
        tracep->declBus(c+57,"CPU PC4 io_out", false,-1, 31,0);
        tracep->declBit(c+147,"CPU predictor clock", false,-1);
        tracep->declBit(c+148,"CPU predictor reset", false,-1);
        tracep->declBit(c+58,"CPU predictor io_taken", false,-1);
        tracep->declBit(c+59,"CPU predictor io_isBtype", false,-1);
        tracep->declBit(c+4,"CPU predictor io_prediction", false,-1);
        tracep->declBus(c+97,"CPU predictor currentState", false,-1, 1,0);
        tracep->declBus(c+60,"CPU btb io_inst", false,-1, 31,0);
        tracep->declBus(c+56,"CPU btb io_PC", false,-1, 31,0);
        tracep->declBit(c+61,"CPU btb io_isBtype", false,-1);
        tracep->declBus(c+62,"CPU btb io_target", false,-1, 31,0);
        tracep->declBus(c+98,"CPU btb bImm_hi_hi_hi", false,-1, 18,0);
        tracep->declBit(c+99,"CPU btb bImm_hi_lo", false,-1);
        tracep->declBus(c+100,"CPU btb bImm_lo_hi_hi", false,-1, 5,0);
        tracep->declBus(c+101,"CPU btb bImm_lo_hi_lo", false,-1, 3,0);
        tracep->declBit(c+147,"CPU InstMemory clock", false,-1);
        tracep->declBus(c+56,"CPU InstMemory io_addr", false,-1, 31,0);
        tracep->declBus(c+60,"CPU InstMemory io_data", false,-1, 31,0);
        tracep->declBus(c+60,"CPU InstMemory imem_io_data_MPORT_data", false,-1, 31,0);
        tracep->declBus(c+102,"CPU InstMemory imem_io_data_MPORT_addr", false,-1, 11,0);
        tracep->declBit(c+147,"CPU DataMemory clock", false,-1);
        tracep->declBus(c+47,"CPU DataMemory io_addr", false,-1, 31,0);
        tracep->declBus(c+45,"CPU DataMemory io_dataIn", false,-1, 31,0);
        tracep->declBit(c+41,"CPU DataMemory io_mem_read", false,-1);
        tracep->declBit(c+42,"CPU DataMemory io_mem_write", false,-1);
        tracep->declBus(c+48,"CPU DataMemory io_dataOut", false,-1, 31,0);
        tracep->declBus(c+103,"CPU DataMemory Dmemory_io_dataOut_MPORT_data", false,-1, 31,0);
        tracep->declBus(c+104,"CPU DataMemory Dmemory_io_dataOut_MPORT_addr", false,-1, 11,0);
        tracep->declBus(c+45,"CPU DataMemory Dmemory_MPORT_data", false,-1, 31,0);
        tracep->declBus(c+104,"CPU DataMemory Dmemory_MPORT_addr", false,-1, 11,0);
        tracep->declBit(c+150,"CPU DataMemory Dmemory_MPORT_mask", false,-1);
        tracep->declBit(c+42,"CPU DataMemory Dmemory_MPORT_en", false,-1);
        tracep->declBus(c+63,"CPU control_module io_opcode", false,-1, 6,0);
        tracep->declBit(c+64,"CPU control_module io_mem_write", false,-1);
        tracep->declBit(c+59,"CPU control_module io_branch", false,-1);
        tracep->declBit(c+65,"CPU control_module io_mem_read", false,-1);
        tracep->declBit(c+66,"CPU control_module io_reg_write", false,-1);
        tracep->declBit(c+65,"CPU control_module io_men_to_reg", false,-1);
        tracep->declBus(c+67,"CPU control_module io_alu_operation", false,-1, 2,0);
        tracep->declBus(c+21,"CPU control_module io_operand_A", false,-1, 1,0);
        tracep->declBit(c+68,"CPU control_module io_operand_B", false,-1);
        tracep->declBus(c+69,"CPU control_module io_extend", false,-1, 1,0);
        tracep->declBus(c+70,"CPU control_module io_next_pc_sel", false,-1, 1,0);
        tracep->declBus(c+7,"CPU ImmGen io_instr", false,-1, 31,0);
        tracep->declBus(c+6,"CPU ImmGen io_pc", false,-1, 31,0);
        tracep->declBus(c+71,"CPU ImmGen io_I_type", false,-1, 31,0);
        tracep->declBus(c+72,"CPU ImmGen io_S_type", false,-1, 31,0);
        tracep->declBus(c+73,"CPU ImmGen io_U_type", false,-1, 31,0);
        tracep->declBus(c+74,"CPU ImmGen io_UJ_type", false,-1, 31,0);
        tracep->declBus(c+105,"CPU ImmGen io_I_type_hi", false,-1, 19,0);
        tracep->declBus(c+106,"CPU ImmGen io_I_type_lo", false,-1, 11,0);
        tracep->declBus(c+107,"CPU ImmGen io_S_type_hi_lo", false,-1, 6,0);
        tracep->declBus(c+14,"CPU ImmGen io_S_type_lo", false,-1, 4,0);
        tracep->declBus(c+108,"CPU ImmGen io_U_type_hi", false,-1, 19,0);
        tracep->declBus(c+109,"CPU ImmGen ujImm_hi_hi_hi", false,-1, 10,0);
        tracep->declBus(c+110,"CPU ImmGen ujImm_hi_lo", false,-1, 7,0);
        tracep->declBit(c+111,"CPU ImmGen ujImm_lo_hi_hi", false,-1);
        tracep->declBus(c+112,"CPU ImmGen ujImm_lo_hi_lo", false,-1, 9,0);
        tracep->declBus(c+113,"CPU ImmGen ujImm", false,-1, 31,0);
        tracep->declBit(c+147,"CPU RegFile clock", false,-1);
        tracep->declBit(c+148,"CPU RegFile reset", false,-1);
        tracep->declBus(c+9,"CPU RegFile io_rs1", false,-1, 4,0);
        tracep->declBus(c+10,"CPU RegFile io_rs2", false,-1, 4,0);
        tracep->declBit(c+50,"CPU RegFile io_reg_write", false,-1);
        tracep->declBus(c+52,"CPU RegFile io_w_reg", false,-1, 4,0);
        tracep->declBus(c+75,"CPU RegFile io_w_data", false,-1, 31,0);
        tracep->declBus(c+76,"CPU RegFile io_rdata1", false,-1, 31,0);
        tracep->declBus(c+77,"CPU RegFile io_rdata2", false,-1, 31,0);
        tracep->declBus(c+114,"CPU RegFile regfile_0", false,-1, 31,0);
        tracep->declBus(c+115,"CPU RegFile regfile_1", false,-1, 31,0);
        tracep->declBus(c+116,"CPU RegFile regfile_2", false,-1, 31,0);
        tracep->declBus(c+117,"CPU RegFile regfile_3", false,-1, 31,0);
        tracep->declBus(c+118,"CPU RegFile regfile_4", false,-1, 31,0);
        tracep->declBus(c+119,"CPU RegFile regfile_5", false,-1, 31,0);
        tracep->declBus(c+120,"CPU RegFile regfile_6", false,-1, 31,0);
        tracep->declBus(c+121,"CPU RegFile regfile_7", false,-1, 31,0);
        tracep->declBus(c+122,"CPU RegFile regfile_8", false,-1, 31,0);
        tracep->declBus(c+123,"CPU RegFile regfile_9", false,-1, 31,0);
        tracep->declBus(c+124,"CPU RegFile regfile_10", false,-1, 31,0);
        tracep->declBus(c+125,"CPU RegFile regfile_11", false,-1, 31,0);
        tracep->declBus(c+126,"CPU RegFile regfile_12", false,-1, 31,0);
        tracep->declBus(c+127,"CPU RegFile regfile_13", false,-1, 31,0);
        tracep->declBus(c+128,"CPU RegFile regfile_14", false,-1, 31,0);
        tracep->declBus(c+129,"CPU RegFile regfile_15", false,-1, 31,0);
        tracep->declBus(c+130,"CPU RegFile regfile_16", false,-1, 31,0);
        tracep->declBus(c+131,"CPU RegFile regfile_17", false,-1, 31,0);
        tracep->declBus(c+132,"CPU RegFile regfile_18", false,-1, 31,0);
        tracep->declBus(c+133,"CPU RegFile regfile_19", false,-1, 31,0);
        tracep->declBus(c+134,"CPU RegFile regfile_20", false,-1, 31,0);
        tracep->declBus(c+135,"CPU RegFile regfile_21", false,-1, 31,0);
        tracep->declBus(c+136,"CPU RegFile regfile_22", false,-1, 31,0);
        tracep->declBus(c+137,"CPU RegFile regfile_23", false,-1, 31,0);
        tracep->declBus(c+138,"CPU RegFile regfile_24", false,-1, 31,0);
        tracep->declBus(c+139,"CPU RegFile regfile_25", false,-1, 31,0);
        tracep->declBus(c+140,"CPU RegFile regfile_26", false,-1, 31,0);
        tracep->declBus(c+141,"CPU RegFile regfile_27", false,-1, 31,0);
        tracep->declBus(c+142,"CPU RegFile regfile_28", false,-1, 31,0);
        tracep->declBus(c+143,"CPU RegFile regfile_29", false,-1, 31,0);
        tracep->declBus(c+144,"CPU RegFile regfile_30", false,-1, 31,0);
        tracep->declBus(c+145,"CPU RegFile regfile_31", false,-1, 31,0);
        tracep->declBus(c+29,"CPU ALU_Control io_func3", false,-1, 2,0);
        tracep->declBit(c+30,"CPU ALU_Control io_func7", false,-1);
        tracep->declBus(c+35,"CPU ALU_Control io_aluOp", false,-1, 2,0);
        tracep->declBus(c+78,"CPU ALU_Control io_out", false,-1, 4,0);
        tracep->declBus(c+79,"CPU ALU io_in_A", false,-1, 31,0);
        tracep->declBus(c+80,"CPU ALU io_in_B", false,-1, 31,0);
        tracep->declBus(c+78,"CPU ALU io_alu_Op", false,-1, 4,0);
        tracep->declBus(c+40,"CPU ALU io_out", false,-1, 31,0);
        tracep->declBus(c+15,"CPU Branch_M io_fnct3", false,-1, 2,0);
        tracep->declBit(c+59,"CPU Branch_M io_branch", false,-1);
        tracep->declBus(c+81,"CPU Branch_M io_arg_x", false,-1, 31,0);
        tracep->declBus(c+82,"CPU Branch_M io_arg_y", false,-1, 31,0);
        tracep->declBit(c+8,"CPU Branch_M io_pred", false,-1);
        tracep->declBit(c+58,"CPU Branch_M io_actual", false,-1);
        tracep->declBit(c+83,"CPU Branch_M io_flush", false,-1);
        tracep->declBus(c+13,"CPU JALR io_imme", false,-1, 31,0);
        tracep->declBus(c+84,"CPU JALR io_rdata1", false,-1, 31,0);
        tracep->declBus(c+85,"CPU JALR io_out", false,-1, 31,0);
        tracep->declBus(c+146,"CPU JALR computedAddr", false,-1, 31,0);
        tracep->declBus(c+23,"CPU Forwarding io_IDEX_rs1", false,-1, 4,0);
        tracep->declBus(c+24,"CPU Forwarding io_IDEX_rs2", false,-1, 4,0);
        tracep->declBus(c+46,"CPU Forwarding io_EXMEM_rd", false,-1, 4,0);
        tracep->declBit(c+44,"CPU Forwarding io_EXMEM_regWr", false,-1);
        tracep->declBus(c+52,"CPU Forwarding io_MEMWB_rd", false,-1, 4,0);
        tracep->declBit(c+50,"CPU Forwarding io_MEMWB_regWr", false,-1);
        tracep->declBus(c+86,"CPU Forwarding io_forward_a", false,-1, 1,0);
        tracep->declBus(c+87,"CPU Forwarding io_forward_b", false,-1, 1,0);
        tracep->declBus(c+7,"CPU HazardDetect io_IF_ID_inst", false,-1, 31,0);
        tracep->declBit(c+32,"CPU HazardDetect io_ID_EX_memRead", false,-1);
        tracep->declBus(c+27,"CPU HazardDetect io_ID_EX_rd", false,-1, 4,0);
        tracep->declBus(c+5,"CPU HazardDetect io_pc_in", false,-1, 31,0);
        tracep->declBit(c+88,"CPU HazardDetect io_pc_forward", false,-1);
        tracep->declBit(c+89,"CPU HazardDetect io_ctrl_forward", false,-1);
        tracep->declBus(c+5,"CPU HazardDetect io_pc_out", false,-1, 31,0);
        tracep->declBus(c+90,"CPU HazardDetect Rs1", false,-1, 4,0);
        tracep->declBus(c+91,"CPU HazardDetect Rs2", false,-1, 4,0);
        tracep->declBus(c+27,"CPU Branch_Forward io_ID_EX_RD", false,-1, 4,0);
        tracep->declBus(c+46,"CPU Branch_Forward io_EX_MEM_RD", false,-1, 4,0);
        tracep->declBus(c+52,"CPU Branch_Forward io_MEM_WB_RD", false,-1, 4,0);
        tracep->declBit(c+32,"CPU Branch_Forward io_ID_EX_memRd", false,-1);
        tracep->declBit(c+41,"CPU Branch_Forward io_EX_MEM_memRd", false,-1);
        tracep->declBit(c+51,"CPU Branch_Forward io_MEM_WB_memRd", false,-1);
        tracep->declBus(c+90,"CPU Branch_Forward io_rs1", false,-1, 4,0);
        tracep->declBus(c+91,"CPU Branch_Forward io_rs2", false,-1, 4,0);
        tracep->declBit(c+59,"CPU Branch_Forward io_ctrl_branch", false,-1);
        tracep->declBus(c+92,"CPU Branch_Forward io_forward_rs1", false,-1, 3,0);
        tracep->declBus(c+93,"CPU Branch_Forward io_forward_rs2", false,-1, 3,0);
        tracep->declBus(c+90,"CPU Structural io_rs1", false,-1, 4,0);
        tracep->declBus(c+91,"CPU Structural io_rs2", false,-1, 4,0);
        tracep->declBit(c+44,"CPU Structural io_MEM_WB_regWr", false,-1);
        tracep->declBus(c+52,"CPU Structural io_MEM_WB_Rd", false,-1, 4,0);
        tracep->declBit(c+94,"CPU Structural io_fwd_rs1", false,-1);
        tracep->declBit(c+95,"CPU Structural io_fwd_rs2", false,-1);
    }
}

void VCPU::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VCPU::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VCPU__Syms* __restrict vlSymsp = static_cast<VCPU__Syms*>(userp);
    VCPU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VCPU::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VCPU__Syms* __restrict vlSymsp = static_cast<VCPU__Syms*>(userp);
    VCPU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(((IData)(vlTOPp->CPU__DOT__HazardDetect_io_pc_forward)
                                    ? ((IData)(4U) 
                                       + vlTOPp->CPU__DOT__PC__DOT__PC)
                                    : ((1U == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                        ? (((IData)(vlTOPp->CPU__DOT__Branch_M_io_flush) 
                                            & (IData)(vlTOPp->CPU__DOT__control_module_io_branch))
                                            ? 0U : 
                                           ((IData)(4U) 
                                            + vlTOPp->CPU__DOT__PC__DOT__PC))
                                        : ((2U == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                            ? 0U : 
                                           ((3U == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                             ? 0U : 
                                            ((IData)(4U) 
                                             + vlTOPp->CPU__DOT__PC__DOT__PC)))))),32);
        tracep->fullIData(oldp+2,(((IData)(vlTOPp->CPU__DOT__HazardDetect_io_pc_forward)
                                    ? vlTOPp->CPU__DOT__btb_io_target
                                    : ((1U == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                        ? (((IData)(vlTOPp->CPU__DOT__Branch_M_io_flush) 
                                            & (IData)(vlTOPp->CPU__DOT__control_module_io_branch))
                                            ? 0U : vlTOPp->CPU__DOT__btb_io_target)
                                        : ((2U == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                            ? 0U : 
                                           ((3U == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                             ? 0U : vlTOPp->CPU__DOT__btb_io_target))))),32);
        tracep->fullIData(oldp+3,(((IData)(vlTOPp->CPU__DOT__HazardDetect_io_pc_forward)
                                    ? vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data
                                    : ((1U == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                        ? (((IData)(vlTOPp->CPU__DOT__Branch_M_io_flush) 
                                            & (IData)(vlTOPp->CPU__DOT__control_module_io_branch))
                                            ? 0U : vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data)
                                        : ((2U == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                            ? 0U : 
                                           ((3U == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                             ? 0U : vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data))))),32);
        tracep->fullBit(oldp+4,(vlTOPp->CPU__DOT__predictor_io_prediction));
        tracep->fullIData(oldp+5,(vlTOPp->CPU__DOT__IF_ID___DOT__Pc4_In),32);
        tracep->fullIData(oldp+6,(vlTOPp->CPU__DOT__IF_ID___DOT__S_pc),32);
        tracep->fullIData(oldp+7,(vlTOPp->CPU__DOT__IF_ID___DOT__S_instr),32);
        tracep->fullBit(oldp+8,(vlTOPp->CPU__DOT__IF_ID___DOT__io_pred_out_REG));
        tracep->fullCData(oldp+9,(vlTOPp->CPU__DOT__RegFile_io_rs1),5);
        tracep->fullCData(oldp+10,(vlTOPp->CPU__DOT__RegFile_io_rs2),5);
        tracep->fullIData(oldp+11,(((IData)(vlTOPp->CPU__DOT__Structural_io_fwd_rs1)
                                     ? ((IData)(vlTOPp->CPU__DOT__Structural_io_fwd_rs1)
                                         ? vlTOPp->CPU__DOT__RegFile_io_w_data
                                         : 0U) : vlTOPp->CPU__DOT__RegFile_io_rdata1)),32);
        tracep->fullIData(oldp+12,(((IData)(vlTOPp->CPU__DOT__Structural_io_fwd_rs2)
                                     ? ((IData)(vlTOPp->CPU__DOT__Structural_io_fwd_rs2)
                                         ? vlTOPp->CPU__DOT__RegFile_io_w_data
                                         : 0U) : vlTOPp->CPU__DOT__RegFile_io_rdata2)),32);
        tracep->fullIData(oldp+13,(((2U == (IData)(vlTOPp->CPU__DOT__control_module_io_extend))
                                     ? (0xfffff000U 
                                        & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                     : vlTOPp->CPU__DOT___ImmValue_T_3)),32);
        tracep->fullCData(oldp+14,((0x1fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                             >> 7U))),5);
        tracep->fullCData(oldp+15,((7U & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                          >> 0xcU))),3);
        tracep->fullBit(oldp+16,((1U & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                        >> 0x1eU))));
        tracep->fullBit(oldp+17,(((~ (IData)(vlTOPp->CPU__DOT__HazardDetect_io_ctrl_forward)) 
                                  & ((0x33U != (0x7fU 
                                                & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                     & ((0x13U != (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                        & (0x23U == 
                                           (0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)))))));
        tracep->fullBit(oldp+18,(((~ (IData)(vlTOPp->CPU__DOT__HazardDetect_io_ctrl_forward)) 
                                  & ((0x33U != (0x7fU 
                                                & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                     & (IData)(vlTOPp->CPU__DOT__control_module__DOT___GEN_51)))));
        tracep->fullBit(oldp+19,(((~ (IData)(vlTOPp->CPU__DOT__HazardDetect_io_ctrl_forward)) 
                                  & ((0x33U == (0x7fU 
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
                                                       | (IData)(vlTOPp->CPU__DOT__control_module__DOT___GEN_5)))))))))));
        tracep->fullCData(oldp+20,(((IData)(vlTOPp->CPU__DOT__HazardDetect_io_ctrl_forward)
                                     ? 0U : ((0x33U 
                                              == (0x7fU 
                                                  & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                              ? 0U : 
                                             ((0x13U 
                                               == (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                               ? 1U
                                               : ((0x23U 
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
        tracep->fullCData(oldp+21,(((0x33U == (0x7fU 
                                               & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                     ? 0U : ((0x13U 
                                              == (0x7fU 
                                                  & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                              ? 0U : 
                                             ((0x23U 
                                               == (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                               ? 0U
                                               : ((3U 
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
        tracep->fullBit(oldp+22,(((~ (IData)(vlTOPp->CPU__DOT__HazardDetect_io_ctrl_forward)) 
                                  & ((0x33U != (0x7fU 
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
                                                       & (IData)(vlTOPp->CPU__DOT__control_module__DOT___GEN_5)))))))))));
        tracep->fullCData(oldp+23,(vlTOPp->CPU__DOT__ID_EX___DOT__io_rs1_out_REG),5);
        tracep->fullCData(oldp+24,(vlTOPp->CPU__DOT__ID_EX___DOT__io_rs2_out_REG),5);
        tracep->fullIData(oldp+25,(vlTOPp->CPU__DOT__ID_EX___DOT__io_rs1_data_out_REG),32);
        tracep->fullIData(oldp+26,(vlTOPp->CPU__DOT__ID_EX___DOT__io_rs2_data_out_REG),32);
        tracep->fullCData(oldp+27,(vlTOPp->CPU__DOT__ID_EX___DOT__io_rd_out_REG),5);
        tracep->fullIData(oldp+28,(vlTOPp->CPU__DOT__ID_EX___DOT__io_imm_out_REG),32);
        tracep->fullCData(oldp+29,(vlTOPp->CPU__DOT__ID_EX___DOT__io_func3_out_REG),3);
        tracep->fullBit(oldp+30,(vlTOPp->CPU__DOT__ID_EX___DOT__io_func7_out_REG));
        tracep->fullBit(oldp+31,(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_MemWr_out_REG));
        tracep->fullBit(oldp+32,(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_MemRd_out_REG));
        tracep->fullBit(oldp+33,(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_Reg_W_out_REG));
        tracep->fullBit(oldp+34,(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_MemToReg_out_REG));
        tracep->fullCData(oldp+35,(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_AluOp_out_REG),3);
        tracep->fullCData(oldp+36,(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_OpA_out_REG),2);
        tracep->fullBit(oldp+37,(vlTOPp->CPU__DOT__ID_EX___DOT__io_ctrl_OpB_out_REG));
        tracep->fullIData(oldp+38,(vlTOPp->CPU__DOT__ID_EX___DOT__io_IFID_pc4_out_REG),32);
        tracep->fullIData(oldp+39,(((0U == (IData)(vlTOPp->CPU__DOT__Forwarding_io_forward_b))
                                     ? vlTOPp->CPU__DOT__ID_EX___DOT__io_rs2_data_out_REG
                                     : vlTOPp->CPU__DOT___GEN_42)),32);
        tracep->fullIData(oldp+40,((IData)(vlTOPp->CPU__DOT__ALU__DOT___GEN_10)),32);
        tracep->fullBit(oldp+41,(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_memRd_out_REG));
        tracep->fullBit(oldp+42,(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_memWr_out_REG));
        tracep->fullBit(oldp+43,(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_memToReg_out_REG));
        tracep->fullBit(oldp+44,(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_reg_w_out_REG));
        tracep->fullIData(oldp+45,(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rs2_out_REG),32);
        tracep->fullCData(oldp+46,(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG),5);
        tracep->fullIData(oldp+47,(vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG),32);
        tracep->fullIData(oldp+48,(vlTOPp->CPU__DOT__DataMemory_io_dataOut),32);
        tracep->fullBit(oldp+49,(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_memToReg_out_REG));
        tracep->fullBit(oldp+50,(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG));
        tracep->fullBit(oldp+51,(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_memRd_out_REG));
        tracep->fullCData(oldp+52,(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG),5);
        tracep->fullIData(oldp+53,(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_dataMem_out_REG),32);
        tracep->fullIData(oldp+54,(vlTOPp->CPU__DOT__MEM_WB_M__DOT__io_MEMWB_alu_out_REG),32);
        tracep->fullIData(oldp+55,(((IData)(vlTOPp->CPU__DOT__HazardDetect_io_pc_forward)
                                     ? vlTOPp->CPU__DOT__IF_ID___DOT__Pc4_In
                                     : ((1U == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                         ? (((IData)(vlTOPp->CPU__DOT__Branch_M_io_flush) 
                                             & (IData)(vlTOPp->CPU__DOT__control_module_io_branch))
                                             ? ((IData)(vlTOPp->CPU__DOT__Branch_M_io_actual)
                                                 ? vlTOPp->CPU__DOT__IF_ID___DOT__S_pc
                                                 : vlTOPp->CPU__DOT__IF_ID___DOT__Pc4_In)
                                             : vlTOPp->CPU__DOT___PC_io_in_T_5)
                                         : ((2U == (IData)(vlTOPp->CPU__DOT__control_module_io_next_pc_sel))
                                             ? ((((
                                                   (0x80000000U 
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
                                             : ((3U 
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
        tracep->fullIData(oldp+56,(vlTOPp->CPU__DOT__PC__DOT__PC),32);
        tracep->fullIData(oldp+57,(((IData)(4U) + vlTOPp->CPU__DOT__PC__DOT__PC)),32);
        tracep->fullBit(oldp+58,(vlTOPp->CPU__DOT__Branch_M_io_actual));
        tracep->fullBit(oldp+59,(vlTOPp->CPU__DOT__control_module_io_branch));
        tracep->fullIData(oldp+60,(vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data),32);
        tracep->fullBit(oldp+61,((0x63U == (0x7fU & vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data))));
        tracep->fullIData(oldp+62,(vlTOPp->CPU__DOT__btb_io_target),32);
        tracep->fullCData(oldp+63,((0x7fU & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)),7);
        tracep->fullBit(oldp+64,(((0x33U != (0x7fU 
                                             & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                  & ((0x13U != (0x7fU 
                                                & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                     & (0x23U == (0x7fU 
                                                  & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))))));
        tracep->fullBit(oldp+65,(((0x33U != (0x7fU 
                                             & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                  & (IData)(vlTOPp->CPU__DOT__control_module__DOT___GEN_51))));
        tracep->fullBit(oldp+66,(((0x33U == (0x7fU 
                                             & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                  | ((0x13U == (0x7fU 
                                                & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                     | ((0x23U != (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                        & ((3U == (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                           | ((0x63U 
                                               != (0x7fU 
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
        tracep->fullCData(oldp+67,(((0x33U == (0x7fU 
                                               & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                     ? 0U : ((0x13U 
                                              == (0x7fU 
                                                  & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                              ? 1U : 
                                             ((0x23U 
                                               == (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr))
                                               ? 5U
                                               : ((3U 
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
        tracep->fullBit(oldp+68,(((0x33U != (0x7fU 
                                             & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                  & ((0x13U == (0x7fU 
                                                & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                     | ((0x23U == (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                        | ((3U == (0x7fU 
                                                   & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)) 
                                           | ((0x63U 
                                               != (0x7fU 
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
        tracep->fullCData(oldp+69,(vlTOPp->CPU__DOT__control_module_io_extend),2);
        tracep->fullCData(oldp+70,(vlTOPp->CPU__DOT__control_module_io_next_pc_sel),2);
        tracep->fullIData(oldp+71,(((((0x80000000U 
                                       & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                       ? 0xfffffU : 0U) 
                                     << 0xcU) | (0xfffU 
                                                 & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                    >> 0x14U)))),32);
        tracep->fullIData(oldp+72,(((((0x80000000U 
                                       & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                       ? 0xfffffU : 0U) 
                                     << 0xcU) | ((0xfe0U 
                                                  & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                     >> 0x14U)) 
                                                 | (0x1fU 
                                                    & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                       >> 7U))))),32);
        tracep->fullIData(oldp+73,((0xfffff000U & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)),32);
        tracep->fullIData(oldp+74,((((((0x80000000U 
                                        & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                        ? 0x7ffU : 0U) 
                                      << 0x15U) | (
                                                   (0x100000U 
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
        tracep->fullIData(oldp+75,(vlTOPp->CPU__DOT__RegFile_io_w_data),32);
        tracep->fullIData(oldp+76,(vlTOPp->CPU__DOT__RegFile_io_rdata1),32);
        tracep->fullIData(oldp+77,(vlTOPp->CPU__DOT__RegFile_io_rdata2),32);
        tracep->fullCData(oldp+78,((0x1fU & (IData)(vlTOPp->CPU__DOT__ALU_Control__DOT___GEN_4))),5);
        tracep->fullIData(oldp+79,(vlTOPp->CPU__DOT__ALU_io_in_A),32);
        tracep->fullIData(oldp+80,(vlTOPp->CPU__DOT__ALU_io_in_B),32);
        tracep->fullIData(oldp+81,(vlTOPp->CPU__DOT__Branch_M_io_arg_x),32);
        tracep->fullIData(oldp+82,(vlTOPp->CPU__DOT___Branch_M_io_arg_y_T_7),32);
        tracep->fullBit(oldp+83,(vlTOPp->CPU__DOT__Branch_M_io_flush));
        tracep->fullIData(oldp+84,(((0xaU == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                     ? vlTOPp->CPU__DOT__RegFile_io_w_data
                                     : ((9U == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                         ? vlTOPp->CPU__DOT__DataMemory_io_dataOut
                                         : ((8U == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                             ? vlTOPp->CPU__DOT__RegFile_io_w_data
                                             : ((7U 
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
        tracep->fullIData(oldp+85,((0xfffffffeU & (
                                                   ((2U 
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
                                                               : 0U)))))))))))))),32);
        tracep->fullCData(oldp+86,(vlTOPp->CPU__DOT__Forwarding_io_forward_a),2);
        tracep->fullCData(oldp+87,(vlTOPp->CPU__DOT__Forwarding_io_forward_b),2);
        tracep->fullBit(oldp+88,(vlTOPp->CPU__DOT__HazardDetect_io_pc_forward));
        tracep->fullBit(oldp+89,(vlTOPp->CPU__DOT__HazardDetect_io_ctrl_forward));
        tracep->fullCData(oldp+90,((0x1fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+91,((0x1fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                             >> 0x14U))),5);
        tracep->fullCData(oldp+92,(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1),4);
        tracep->fullCData(oldp+93,(vlTOPp->CPU__DOT__Branch_Forward__DOT___GEN_28),4);
        tracep->fullBit(oldp+94,(vlTOPp->CPU__DOT__Structural_io_fwd_rs1));
        tracep->fullBit(oldp+95,(vlTOPp->CPU__DOT__Structural_io_fwd_rs2));
        tracep->fullIData(oldp+96,(vlTOPp->CPU__DOT__d),32);
        tracep->fullCData(oldp+97,(vlTOPp->CPU__DOT__predictor__DOT__currentState),2);
        tracep->fullIData(oldp+98,(((0x80000000U & vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data)
                                     ? 0x7ffffU : 0U)),19);
        tracep->fullBit(oldp+99,((1U & (vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data 
                                        >> 7U))));
        tracep->fullCData(oldp+100,((0x3fU & (vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data 
                                              >> 0x19U))),6);
        tracep->fullCData(oldp+101,((0xfU & (vlTOPp->CPU__DOT__InstMemory__DOT__imem_io_data_MPORT_data 
                                             >> 8U))),4);
        tracep->fullSData(oldp+102,((0xfffU & (vlTOPp->CPU__DOT__PC__DOT__PC 
                                               >> 2U))),12);
        tracep->fullIData(oldp+103,(((0x800U >= (0xfffU 
                                                 & vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG))
                                      ? vlTOPp->CPU__DOT__DataMemory__DOT__Dmemory
                                     [(0xfffU & vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG)]
                                      : 0U)),32);
        tracep->fullSData(oldp+104,((0xfffU & vlTOPp->CPU__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG)),12);
        tracep->fullIData(oldp+105,(((0x80000000U & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                      ? 0xfffffU : 0U)),20);
        tracep->fullSData(oldp+106,((0xfffU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                               >> 0x14U))),12);
        tracep->fullCData(oldp+107,((0x7fU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                              >> 0x19U))),7);
        tracep->fullIData(oldp+108,((0xfffffU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                                 >> 0xcU))),20);
        tracep->fullSData(oldp+109,(((0x80000000U & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                      ? 0x7ffU : 0U)),11);
        tracep->fullCData(oldp+110,((0xffU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                              >> 0xcU))),8);
        tracep->fullBit(oldp+111,((1U & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                         >> 0x14U))));
        tracep->fullSData(oldp+112,((0x3ffU & (vlTOPp->CPU__DOT__IF_ID___DOT__S_instr 
                                               >> 0x15U))),10);
        tracep->fullIData(oldp+113,(((((0x80000000U 
                                        & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                        ? 0x7ffU : 0U) 
                                      << 0x15U) | (
                                                   (0x100000U 
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
        tracep->fullIData(oldp+114,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_0),32);
        tracep->fullIData(oldp+115,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_1),32);
        tracep->fullIData(oldp+116,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_2),32);
        tracep->fullIData(oldp+117,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_3),32);
        tracep->fullIData(oldp+118,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_4),32);
        tracep->fullIData(oldp+119,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_5),32);
        tracep->fullIData(oldp+120,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_6),32);
        tracep->fullIData(oldp+121,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_7),32);
        tracep->fullIData(oldp+122,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_8),32);
        tracep->fullIData(oldp+123,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_9),32);
        tracep->fullIData(oldp+124,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_10),32);
        tracep->fullIData(oldp+125,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_11),32);
        tracep->fullIData(oldp+126,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_12),32);
        tracep->fullIData(oldp+127,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_13),32);
        tracep->fullIData(oldp+128,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_14),32);
        tracep->fullIData(oldp+129,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_15),32);
        tracep->fullIData(oldp+130,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_16),32);
        tracep->fullIData(oldp+131,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_17),32);
        tracep->fullIData(oldp+132,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_18),32);
        tracep->fullIData(oldp+133,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_19),32);
        tracep->fullIData(oldp+134,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_20),32);
        tracep->fullIData(oldp+135,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_21),32);
        tracep->fullIData(oldp+136,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_22),32);
        tracep->fullIData(oldp+137,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_23),32);
        tracep->fullIData(oldp+138,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_24),32);
        tracep->fullIData(oldp+139,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_25),32);
        tracep->fullIData(oldp+140,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_26),32);
        tracep->fullIData(oldp+141,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_27),32);
        tracep->fullIData(oldp+142,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_28),32);
        tracep->fullIData(oldp+143,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_29),32);
        tracep->fullIData(oldp+144,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_30),32);
        tracep->fullIData(oldp+145,(vlTOPp->CPU__DOT__RegFile__DOT__regfile_31),32);
        tracep->fullIData(oldp+146,((((2U == (IData)(vlTOPp->CPU__DOT__control_module_io_extend))
                                       ? (0xfffff000U 
                                          & vlTOPp->CPU__DOT__IF_ID___DOT__S_instr)
                                       : vlTOPp->CPU__DOT___ImmValue_T_3) 
                                     + ((0xaU == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                         ? vlTOPp->CPU__DOT__RegFile_io_w_data
                                         : ((9U == (IData)(vlTOPp->CPU__DOT__Branch_Forward_io_forward_rs1))
                                             ? vlTOPp->CPU__DOT__DataMemory_io_dataOut
                                             : ((8U 
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
        tracep->fullBit(oldp+147,(vlTOPp->clock));
        tracep->fullBit(oldp+148,(vlTOPp->reset));
        tracep->fullCData(oldp+149,(vlTOPp->io_out),4);
        tracep->fullBit(oldp+150,(1U));
    }
}
