// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VPIPELINE__Syms.h"


//======================

void VPIPELINE::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VPIPELINE::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VPIPELINE__Syms* __restrict vlSymsp = static_cast<VPIPELINE__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VPIPELINE::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VPIPELINE::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VPIPELINE__Syms* __restrict vlSymsp = static_cast<VPIPELINE__Syms*>(userp);
    VPIPELINE* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VPIPELINE::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VPIPELINE__Syms* __restrict vlSymsp = static_cast<VPIPELINE__Syms*>(userp);
    VPIPELINE* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+146,"clock", false,-1);
        tracep->declBit(c+147,"reset", false,-1);
        tracep->declBus(c+148,"io_out", false,-1, 3,0);
        tracep->declBit(c+146,"PIPELINE clock", false,-1);
        tracep->declBit(c+147,"PIPELINE reset", false,-1);
        tracep->declBus(c+148,"PIPELINE io_out", false,-1, 3,0);
        tracep->declBit(c+146,"PIPELINE IF_ID__clock", false,-1);
        tracep->declBit(c+147,"PIPELINE IF_ID__reset", false,-1);
        tracep->declBus(c+1,"PIPELINE IF_ID__io_pc4_in", false,-1, 31,0);
        tracep->declBus(c+2,"PIPELINE IF_ID__io_SelectedPC", false,-1, 31,0);
        tracep->declBus(c+3,"PIPELINE IF_ID__io_SelectedInstr", false,-1, 31,0);
        tracep->declBus(c+4,"PIPELINE IF_ID__io_pc4_out", false,-1, 31,0);
        tracep->declBus(c+5,"PIPELINE IF_ID__io_SelectedPC_out", false,-1, 31,0);
        tracep->declBus(c+6,"PIPELINE IF_ID__io_SelectedInstr_out", false,-1, 31,0);
        tracep->declBit(c+146,"PIPELINE ID_EX__clock", false,-1);
        tracep->declBus(c+7,"PIPELINE ID_EX__io_rs1_in", false,-1, 4,0);
        tracep->declBus(c+8,"PIPELINE ID_EX__io_rs2_in", false,-1, 4,0);
        tracep->declBus(c+9,"PIPELINE ID_EX__io_rs1_data_in", false,-1, 31,0);
        tracep->declBus(c+10,"PIPELINE ID_EX__io_rs2_data_in", false,-1, 31,0);
        tracep->declBus(c+11,"PIPELINE ID_EX__io_imm", false,-1, 31,0);
        tracep->declBus(c+12,"PIPELINE ID_EX__io_rd_in", false,-1, 4,0);
        tracep->declBus(c+13,"PIPELINE ID_EX__io_func3_in", false,-1, 2,0);
        tracep->declBit(c+14,"PIPELINE ID_EX__io_func7_in", false,-1);
        tracep->declBit(c+15,"PIPELINE ID_EX__io_ctrl_MemWr_in", false,-1);
        tracep->declBit(c+16,"PIPELINE ID_EX__io_ctrl_MemRd_in", false,-1);
        tracep->declBit(c+17,"PIPELINE ID_EX__io_ctrl_Reg_W_in", false,-1);
        tracep->declBit(c+16,"PIPELINE ID_EX__io_ctrl_MemToReg_in", false,-1);
        tracep->declBus(c+18,"PIPELINE ID_EX__io_ctrl_AluOp_in", false,-1, 2,0);
        tracep->declBus(c+19,"PIPELINE ID_EX__io_ctrl_OpA_in", false,-1, 1,0);
        tracep->declBit(c+20,"PIPELINE ID_EX__io_ctrl_OpB_in", false,-1);
        tracep->declBus(c+4,"PIPELINE ID_EX__io_IFID_pc4_in", false,-1, 31,0);
        tracep->declBus(c+21,"PIPELINE ID_EX__io_rs1_out", false,-1, 4,0);
        tracep->declBus(c+22,"PIPELINE ID_EX__io_rs2_out", false,-1, 4,0);
        tracep->declBus(c+23,"PIPELINE ID_EX__io_rs1_data_out", false,-1, 31,0);
        tracep->declBus(c+24,"PIPELINE ID_EX__io_rs2_data_out", false,-1, 31,0);
        tracep->declBus(c+25,"PIPELINE ID_EX__io_rd_out", false,-1, 4,0);
        tracep->declBus(c+26,"PIPELINE ID_EX__io_imm_out", false,-1, 31,0);
        tracep->declBus(c+27,"PIPELINE ID_EX__io_func3_out", false,-1, 2,0);
        tracep->declBit(c+28,"PIPELINE ID_EX__io_func7_out", false,-1);
        tracep->declBit(c+29,"PIPELINE ID_EX__io_ctrl_MemWr_out", false,-1);
        tracep->declBit(c+30,"PIPELINE ID_EX__io_ctrl_MemRd_out", false,-1);
        tracep->declBit(c+31,"PIPELINE ID_EX__io_ctrl_Reg_W_out", false,-1);
        tracep->declBit(c+32,"PIPELINE ID_EX__io_ctrl_MemToReg_out", false,-1);
        tracep->declBus(c+33,"PIPELINE ID_EX__io_ctrl_AluOp_out", false,-1, 2,0);
        tracep->declBus(c+34,"PIPELINE ID_EX__io_ctrl_OpA_out", false,-1, 1,0);
        tracep->declBit(c+35,"PIPELINE ID_EX__io_ctrl_OpB_out", false,-1);
        tracep->declBus(c+36,"PIPELINE ID_EX__io_IFID_pc4_out", false,-1, 31,0);
        tracep->declBit(c+146,"PIPELINE EX_MEM_M_clock", false,-1);
        tracep->declBit(c+30,"PIPELINE EX_MEM_M_io_IDEX_MEMRD", false,-1);
        tracep->declBit(c+29,"PIPELINE EX_MEM_M_io_IDEX_MEMWR", false,-1);
        tracep->declBit(c+32,"PIPELINE EX_MEM_M_io_IDEX_MEMTOREG", false,-1);
        tracep->declBit(c+31,"PIPELINE EX_MEM_M_io_IDEX_REG_W", false,-1);
        tracep->declBus(c+37,"PIPELINE EX_MEM_M_io_IDEX_rs2", false,-1, 31,0);
        tracep->declBus(c+25,"PIPELINE EX_MEM_M_io_IDEX_rd", false,-1, 4,0);
        tracep->declBus(c+38,"PIPELINE EX_MEM_M_io_alu_out", false,-1, 31,0);
        tracep->declBit(c+39,"PIPELINE EX_MEM_M_io_EXMEM_memRd_out", false,-1);
        tracep->declBit(c+40,"PIPELINE EX_MEM_M_io_EXMEM_memWr_out", false,-1);
        tracep->declBit(c+41,"PIPELINE EX_MEM_M_io_EXMEM_memToReg_out", false,-1);
        tracep->declBit(c+42,"PIPELINE EX_MEM_M_io_EXMEM_reg_w_out", false,-1);
        tracep->declBus(c+43,"PIPELINE EX_MEM_M_io_EXMEM_rs2_out", false,-1, 31,0);
        tracep->declBus(c+44,"PIPELINE EX_MEM_M_io_EXMEM_rd_out", false,-1, 4,0);
        tracep->declBus(c+45,"PIPELINE EX_MEM_M_io_EXMEM_alu_out", false,-1, 31,0);
        tracep->declBit(c+146,"PIPELINE MEM_WB_M_clock", false,-1);
        tracep->declBit(c+41,"PIPELINE MEM_WB_M_io_EXMEM_MEMTOREG", false,-1);
        tracep->declBit(c+42,"PIPELINE MEM_WB_M_io_EXMEM_REG_W", false,-1);
        tracep->declBit(c+39,"PIPELINE MEM_WB_M_io_EXMEM_MEMRD", false,-1);
        tracep->declBus(c+44,"PIPELINE MEM_WB_M_io_EXMEM_rd", false,-1, 4,0);
        tracep->declBus(c+46,"PIPELINE MEM_WB_M_io_in_dataMem_out", false,-1, 31,0);
        tracep->declBus(c+45,"PIPELINE MEM_WB_M_io_in_alu_out", false,-1, 31,0);
        tracep->declBit(c+47,"PIPELINE MEM_WB_M_io_MEMWB_memToReg_out", false,-1);
        tracep->declBit(c+48,"PIPELINE MEM_WB_M_io_MEMWB_reg_w_out", false,-1);
        tracep->declBit(c+49,"PIPELINE MEM_WB_M_io_MEMWB_memRd_out", false,-1);
        tracep->declBus(c+50,"PIPELINE MEM_WB_M_io_MEMWB_rd_out", false,-1, 4,0);
        tracep->declBus(c+51,"PIPELINE MEM_WB_M_io_MEMWB_dataMem_out", false,-1, 31,0);
        tracep->declBus(c+52,"PIPELINE MEM_WB_M_io_MEMWB_alu_out", false,-1, 31,0);
        tracep->declBit(c+146,"PIPELINE PC_clock", false,-1);
        tracep->declBit(c+147,"PIPELINE PC_reset", false,-1);
        tracep->declBus(c+53,"PIPELINE PC_io_in", false,-1, 31,0);
        tracep->declBus(c+54,"PIPELINE PC_io_out", false,-1, 31,0);
        tracep->declBus(c+54,"PIPELINE PC4_io_pc", false,-1, 31,0);
        tracep->declBus(c+55,"PIPELINE PC4_io_out", false,-1, 31,0);
        tracep->declBit(c+146,"PIPELINE InstMemory_clock", false,-1);
        tracep->declBus(c+54,"PIPELINE InstMemory_io_addr", false,-1, 31,0);
        tracep->declBus(c+56,"PIPELINE InstMemory_io_data", false,-1, 31,0);
        tracep->declBit(c+146,"PIPELINE DataMemory_clock", false,-1);
        tracep->declBus(c+45,"PIPELINE DataMemory_io_addr", false,-1, 31,0);
        tracep->declBus(c+43,"PIPELINE DataMemory_io_dataIn", false,-1, 31,0);
        tracep->declBit(c+39,"PIPELINE DataMemory_io_mem_read", false,-1);
        tracep->declBit(c+40,"PIPELINE DataMemory_io_mem_write", false,-1);
        tracep->declBus(c+46,"PIPELINE DataMemory_io_dataOut", false,-1, 31,0);
        tracep->declBus(c+57,"PIPELINE control_module_io_opcode", false,-1, 6,0);
        tracep->declBit(c+58,"PIPELINE control_module_io_mem_write", false,-1);
        tracep->declBit(c+59,"PIPELINE control_module_io_branch", false,-1);
        tracep->declBit(c+60,"PIPELINE control_module_io_mem_read", false,-1);
        tracep->declBit(c+61,"PIPELINE control_module_io_reg_write", false,-1);
        tracep->declBit(c+60,"PIPELINE control_module_io_men_to_reg", false,-1);
        tracep->declBus(c+62,"PIPELINE control_module_io_alu_operation", false,-1, 2,0);
        tracep->declBus(c+19,"PIPELINE control_module_io_operand_A", false,-1, 1,0);
        tracep->declBit(c+63,"PIPELINE control_module_io_operand_B", false,-1);
        tracep->declBus(c+64,"PIPELINE control_module_io_extend", false,-1, 1,0);
        tracep->declBus(c+65,"PIPELINE control_module_io_next_pc_sel", false,-1, 1,0);
        tracep->declBus(c+6,"PIPELINE ImmGen_io_instr", false,-1, 31,0);
        tracep->declBus(c+5,"PIPELINE ImmGen_io_pc", false,-1, 31,0);
        tracep->declBus(c+66,"PIPELINE ImmGen_io_I_type", false,-1, 31,0);
        tracep->declBus(c+67,"PIPELINE ImmGen_io_S_type", false,-1, 31,0);
        tracep->declBus(c+68,"PIPELINE ImmGen_io_SB_type", false,-1, 31,0);
        tracep->declBus(c+69,"PIPELINE ImmGen_io_U_type", false,-1, 31,0);
        tracep->declBus(c+70,"PIPELINE ImmGen_io_UJ_type", false,-1, 31,0);
        tracep->declBit(c+146,"PIPELINE RegFile_clock", false,-1);
        tracep->declBit(c+147,"PIPELINE RegFile_reset", false,-1);
        tracep->declBus(c+7,"PIPELINE RegFile_io_rs1", false,-1, 4,0);
        tracep->declBus(c+8,"PIPELINE RegFile_io_rs2", false,-1, 4,0);
        tracep->declBit(c+48,"PIPELINE RegFile_io_reg_write", false,-1);
        tracep->declBus(c+50,"PIPELINE RegFile_io_w_reg", false,-1, 4,0);
        tracep->declBus(c+71,"PIPELINE RegFile_io_w_data", false,-1, 31,0);
        tracep->declBus(c+72,"PIPELINE RegFile_io_rdata1", false,-1, 31,0);
        tracep->declBus(c+73,"PIPELINE RegFile_io_rdata2", false,-1, 31,0);
        tracep->declBus(c+27,"PIPELINE ALU_Control_io_func3", false,-1, 2,0);
        tracep->declBit(c+28,"PIPELINE ALU_Control_io_func7", false,-1);
        tracep->declBus(c+33,"PIPELINE ALU_Control_io_aluOp", false,-1, 2,0);
        tracep->declBus(c+74,"PIPELINE ALU_Control_io_out", false,-1, 4,0);
        tracep->declBus(c+75,"PIPELINE ALU_io_in_A", false,-1, 31,0);
        tracep->declBus(c+76,"PIPELINE ALU_io_in_B", false,-1, 31,0);
        tracep->declBus(c+74,"PIPELINE ALU_io_alu_Op", false,-1, 4,0);
        tracep->declBus(c+38,"PIPELINE ALU_io_out", false,-1, 31,0);
        tracep->declBus(c+13,"PIPELINE Branch_M_io_fnct3", false,-1, 2,0);
        tracep->declBit(c+59,"PIPELINE Branch_M_io_branch", false,-1);
        tracep->declBus(c+77,"PIPELINE Branch_M_io_arg_x", false,-1, 31,0);
        tracep->declBus(c+78,"PIPELINE Branch_M_io_arg_y", false,-1, 31,0);
        tracep->declBit(c+79,"PIPELINE Branch_M_io_br_taken", false,-1);
        tracep->declBus(c+11,"PIPELINE JALR_io_imme", false,-1, 31,0);
        tracep->declBus(c+80,"PIPELINE JALR_io_rdata1", false,-1, 31,0);
        tracep->declBus(c+81,"PIPELINE JALR_io_out", false,-1, 31,0);
        tracep->declBus(c+21,"PIPELINE Forwarding_io_IDEX_rs1", false,-1, 4,0);
        tracep->declBus(c+22,"PIPELINE Forwarding_io_IDEX_rs2", false,-1, 4,0);
        tracep->declBus(c+44,"PIPELINE Forwarding_io_EXMEM_rd", false,-1, 4,0);
        tracep->declBit(c+42,"PIPELINE Forwarding_io_EXMEM_regWr", false,-1);
        tracep->declBus(c+50,"PIPELINE Forwarding_io_MEMWB_rd", false,-1, 4,0);
        tracep->declBit(c+48,"PIPELINE Forwarding_io_MEMWB_regWr", false,-1);
        tracep->declBus(c+82,"PIPELINE Forwarding_io_forward_a", false,-1, 1,0);
        tracep->declBus(c+83,"PIPELINE Forwarding_io_forward_b", false,-1, 1,0);
        tracep->declBus(c+6,"PIPELINE HazardDetect_io_IF_ID_inst", false,-1, 31,0);
        tracep->declBit(c+30,"PIPELINE HazardDetect_io_ID_EX_memRead", false,-1);
        tracep->declBus(c+25,"PIPELINE HazardDetect_io_ID_EX_rd", false,-1, 4,0);
        tracep->declBus(c+4,"PIPELINE HazardDetect_io_pc_in", false,-1, 31,0);
        tracep->declBus(c+5,"PIPELINE HazardDetect_io_current_pc", false,-1, 31,0);
        tracep->declBit(c+84,"PIPELINE HazardDetect_io_inst_forward", false,-1);
        tracep->declBit(c+85,"PIPELINE HazardDetect_io_pc_forward", false,-1);
        tracep->declBit(c+86,"PIPELINE HazardDetect_io_ctrl_forward", false,-1);
        tracep->declBus(c+6,"PIPELINE HazardDetect_io_inst_out", false,-1, 31,0);
        tracep->declBus(c+4,"PIPELINE HazardDetect_io_pc_out", false,-1, 31,0);
        tracep->declBus(c+5,"PIPELINE HazardDetect_io_current_pc_out", false,-1, 31,0);
        tracep->declBus(c+25,"PIPELINE Branch_Forward_io_ID_EX_RD", false,-1, 4,0);
        tracep->declBus(c+44,"PIPELINE Branch_Forward_io_EX_MEM_RD", false,-1, 4,0);
        tracep->declBus(c+50,"PIPELINE Branch_Forward_io_MEM_WB_RD", false,-1, 4,0);
        tracep->declBit(c+30,"PIPELINE Branch_Forward_io_ID_EX_memRd", false,-1);
        tracep->declBit(c+39,"PIPELINE Branch_Forward_io_EX_MEM_memRd", false,-1);
        tracep->declBit(c+49,"PIPELINE Branch_Forward_io_MEM_WB_memRd", false,-1);
        tracep->declBus(c+87,"PIPELINE Branch_Forward_io_rs1", false,-1, 4,0);
        tracep->declBus(c+88,"PIPELINE Branch_Forward_io_rs2", false,-1, 4,0);
        tracep->declBit(c+59,"PIPELINE Branch_Forward_io_ctrl_branch", false,-1);
        tracep->declBus(c+89,"PIPELINE Branch_Forward_io_forward_rs1", false,-1, 3,0);
        tracep->declBus(c+90,"PIPELINE Branch_Forward_io_forward_rs2", false,-1, 3,0);
        tracep->declBus(c+87,"PIPELINE Structural_io_rs1", false,-1, 4,0);
        tracep->declBus(c+88,"PIPELINE Structural_io_rs2", false,-1, 4,0);
        tracep->declBit(c+42,"PIPELINE Structural_io_MEM_WB_regWr", false,-1);
        tracep->declBus(c+50,"PIPELINE Structural_io_MEM_WB_Rd", false,-1, 4,0);
        tracep->declBit(c+91,"PIPELINE Structural_io_fwd_rs1", false,-1);
        tracep->declBit(c+92,"PIPELINE Structural_io_fwd_rs2", false,-1);
        tracep->declBus(c+93,"PIPELINE PC_for", false,-1, 31,0);
        tracep->declBus(c+94,"PIPELINE Instruction_F", false,-1, 31,0);
        tracep->declBus(c+95,"PIPELINE d", false,-1, 31,0);
        tracep->declBus(c+37,"PIPELINE RS2_value", false,-1, 31,0);
        tracep->declBit(c+146,"PIPELINE IF_ID_ clock", false,-1);
        tracep->declBit(c+147,"PIPELINE IF_ID_ reset", false,-1);
        tracep->declBus(c+1,"PIPELINE IF_ID_ io_pc4_in", false,-1, 31,0);
        tracep->declBus(c+2,"PIPELINE IF_ID_ io_SelectedPC", false,-1, 31,0);
        tracep->declBus(c+3,"PIPELINE IF_ID_ io_SelectedInstr", false,-1, 31,0);
        tracep->declBus(c+4,"PIPELINE IF_ID_ io_pc4_out", false,-1, 31,0);
        tracep->declBus(c+5,"PIPELINE IF_ID_ io_SelectedPC_out", false,-1, 31,0);
        tracep->declBus(c+6,"PIPELINE IF_ID_ io_SelectedInstr_out", false,-1, 31,0);
        tracep->declBus(c+4,"PIPELINE IF_ID_ Pc4_In", false,-1, 31,0);
        tracep->declBus(c+5,"PIPELINE IF_ID_ S_pc", false,-1, 31,0);
        tracep->declBus(c+6,"PIPELINE IF_ID_ S_instr", false,-1, 31,0);
        tracep->declBit(c+146,"PIPELINE ID_EX_ clock", false,-1);
        tracep->declBus(c+7,"PIPELINE ID_EX_ io_rs1_in", false,-1, 4,0);
        tracep->declBus(c+8,"PIPELINE ID_EX_ io_rs2_in", false,-1, 4,0);
        tracep->declBus(c+9,"PIPELINE ID_EX_ io_rs1_data_in", false,-1, 31,0);
        tracep->declBus(c+10,"PIPELINE ID_EX_ io_rs2_data_in", false,-1, 31,0);
        tracep->declBus(c+11,"PIPELINE ID_EX_ io_imm", false,-1, 31,0);
        tracep->declBus(c+12,"PIPELINE ID_EX_ io_rd_in", false,-1, 4,0);
        tracep->declBus(c+13,"PIPELINE ID_EX_ io_func3_in", false,-1, 2,0);
        tracep->declBit(c+14,"PIPELINE ID_EX_ io_func7_in", false,-1);
        tracep->declBit(c+15,"PIPELINE ID_EX_ io_ctrl_MemWr_in", false,-1);
        tracep->declBit(c+16,"PIPELINE ID_EX_ io_ctrl_MemRd_in", false,-1);
        tracep->declBit(c+17,"PIPELINE ID_EX_ io_ctrl_Reg_W_in", false,-1);
        tracep->declBit(c+16,"PIPELINE ID_EX_ io_ctrl_MemToReg_in", false,-1);
        tracep->declBus(c+18,"PIPELINE ID_EX_ io_ctrl_AluOp_in", false,-1, 2,0);
        tracep->declBus(c+19,"PIPELINE ID_EX_ io_ctrl_OpA_in", false,-1, 1,0);
        tracep->declBit(c+20,"PIPELINE ID_EX_ io_ctrl_OpB_in", false,-1);
        tracep->declBus(c+4,"PIPELINE ID_EX_ io_IFID_pc4_in", false,-1, 31,0);
        tracep->declBus(c+21,"PIPELINE ID_EX_ io_rs1_out", false,-1, 4,0);
        tracep->declBus(c+22,"PIPELINE ID_EX_ io_rs2_out", false,-1, 4,0);
        tracep->declBus(c+23,"PIPELINE ID_EX_ io_rs1_data_out", false,-1, 31,0);
        tracep->declBus(c+24,"PIPELINE ID_EX_ io_rs2_data_out", false,-1, 31,0);
        tracep->declBus(c+25,"PIPELINE ID_EX_ io_rd_out", false,-1, 4,0);
        tracep->declBus(c+26,"PIPELINE ID_EX_ io_imm_out", false,-1, 31,0);
        tracep->declBus(c+27,"PIPELINE ID_EX_ io_func3_out", false,-1, 2,0);
        tracep->declBit(c+28,"PIPELINE ID_EX_ io_func7_out", false,-1);
        tracep->declBit(c+29,"PIPELINE ID_EX_ io_ctrl_MemWr_out", false,-1);
        tracep->declBit(c+30,"PIPELINE ID_EX_ io_ctrl_MemRd_out", false,-1);
        tracep->declBit(c+31,"PIPELINE ID_EX_ io_ctrl_Reg_W_out", false,-1);
        tracep->declBit(c+32,"PIPELINE ID_EX_ io_ctrl_MemToReg_out", false,-1);
        tracep->declBus(c+33,"PIPELINE ID_EX_ io_ctrl_AluOp_out", false,-1, 2,0);
        tracep->declBus(c+34,"PIPELINE ID_EX_ io_ctrl_OpA_out", false,-1, 1,0);
        tracep->declBit(c+35,"PIPELINE ID_EX_ io_ctrl_OpB_out", false,-1);
        tracep->declBus(c+36,"PIPELINE ID_EX_ io_IFID_pc4_out", false,-1, 31,0);
        tracep->declBus(c+21,"PIPELINE ID_EX_ io_rs1_out_REG", false,-1, 4,0);
        tracep->declBus(c+22,"PIPELINE ID_EX_ io_rs2_out_REG", false,-1, 4,0);
        tracep->declBus(c+23,"PIPELINE ID_EX_ io_rs1_data_out_REG", false,-1, 31,0);
        tracep->declBus(c+24,"PIPELINE ID_EX_ io_rs2_data_out_REG", false,-1, 31,0);
        tracep->declBus(c+26,"PIPELINE ID_EX_ io_imm_out_REG", false,-1, 31,0);
        tracep->declBus(c+25,"PIPELINE ID_EX_ io_rd_out_REG", false,-1, 4,0);
        tracep->declBus(c+27,"PIPELINE ID_EX_ io_func3_out_REG", false,-1, 2,0);
        tracep->declBit(c+28,"PIPELINE ID_EX_ io_func7_out_REG", false,-1);
        tracep->declBit(c+29,"PIPELINE ID_EX_ io_ctrl_MemWr_out_REG", false,-1);
        tracep->declBit(c+30,"PIPELINE ID_EX_ io_ctrl_MemRd_out_REG", false,-1);
        tracep->declBit(c+31,"PIPELINE ID_EX_ io_ctrl_Reg_W_out_REG", false,-1);
        tracep->declBit(c+32,"PIPELINE ID_EX_ io_ctrl_MemToReg_out_REG", false,-1);
        tracep->declBus(c+33,"PIPELINE ID_EX_ io_ctrl_AluOp_out_REG", false,-1, 2,0);
        tracep->declBus(c+34,"PIPELINE ID_EX_ io_ctrl_OpA_out_REG", false,-1, 1,0);
        tracep->declBit(c+35,"PIPELINE ID_EX_ io_ctrl_OpB_out_REG", false,-1);
        tracep->declBus(c+36,"PIPELINE ID_EX_ io_IFID_pc4_out_REG", false,-1, 31,0);
        tracep->declBit(c+146,"PIPELINE EX_MEM_M clock", false,-1);
        tracep->declBit(c+30,"PIPELINE EX_MEM_M io_IDEX_MEMRD", false,-1);
        tracep->declBit(c+29,"PIPELINE EX_MEM_M io_IDEX_MEMWR", false,-1);
        tracep->declBit(c+32,"PIPELINE EX_MEM_M io_IDEX_MEMTOREG", false,-1);
        tracep->declBit(c+31,"PIPELINE EX_MEM_M io_IDEX_REG_W", false,-1);
        tracep->declBus(c+37,"PIPELINE EX_MEM_M io_IDEX_rs2", false,-1, 31,0);
        tracep->declBus(c+25,"PIPELINE EX_MEM_M io_IDEX_rd", false,-1, 4,0);
        tracep->declBus(c+38,"PIPELINE EX_MEM_M io_alu_out", false,-1, 31,0);
        tracep->declBit(c+39,"PIPELINE EX_MEM_M io_EXMEM_memRd_out", false,-1);
        tracep->declBit(c+40,"PIPELINE EX_MEM_M io_EXMEM_memWr_out", false,-1);
        tracep->declBit(c+41,"PIPELINE EX_MEM_M io_EXMEM_memToReg_out", false,-1);
        tracep->declBit(c+42,"PIPELINE EX_MEM_M io_EXMEM_reg_w_out", false,-1);
        tracep->declBus(c+43,"PIPELINE EX_MEM_M io_EXMEM_rs2_out", false,-1, 31,0);
        tracep->declBus(c+44,"PIPELINE EX_MEM_M io_EXMEM_rd_out", false,-1, 4,0);
        tracep->declBus(c+45,"PIPELINE EX_MEM_M io_EXMEM_alu_out", false,-1, 31,0);
        tracep->declBit(c+39,"PIPELINE EX_MEM_M io_EXMEM_memRd_out_REG", false,-1);
        tracep->declBit(c+40,"PIPELINE EX_MEM_M io_EXMEM_memWr_out_REG", false,-1);
        tracep->declBit(c+41,"PIPELINE EX_MEM_M io_EXMEM_memToReg_out_REG", false,-1);
        tracep->declBit(c+42,"PIPELINE EX_MEM_M io_EXMEM_reg_w_out_REG", false,-1);
        tracep->declBus(c+43,"PIPELINE EX_MEM_M io_EXMEM_rs2_out_REG", false,-1, 31,0);
        tracep->declBus(c+44,"PIPELINE EX_MEM_M io_EXMEM_rd_out_REG", false,-1, 4,0);
        tracep->declBus(c+45,"PIPELINE EX_MEM_M io_EXMEM_alu_out_REG", false,-1, 31,0);
        tracep->declBit(c+146,"PIPELINE MEM_WB_M clock", false,-1);
        tracep->declBit(c+41,"PIPELINE MEM_WB_M io_EXMEM_MEMTOREG", false,-1);
        tracep->declBit(c+42,"PIPELINE MEM_WB_M io_EXMEM_REG_W", false,-1);
        tracep->declBit(c+39,"PIPELINE MEM_WB_M io_EXMEM_MEMRD", false,-1);
        tracep->declBus(c+44,"PIPELINE MEM_WB_M io_EXMEM_rd", false,-1, 4,0);
        tracep->declBus(c+46,"PIPELINE MEM_WB_M io_in_dataMem_out", false,-1, 31,0);
        tracep->declBus(c+45,"PIPELINE MEM_WB_M io_in_alu_out", false,-1, 31,0);
        tracep->declBit(c+47,"PIPELINE MEM_WB_M io_MEMWB_memToReg_out", false,-1);
        tracep->declBit(c+48,"PIPELINE MEM_WB_M io_MEMWB_reg_w_out", false,-1);
        tracep->declBit(c+49,"PIPELINE MEM_WB_M io_MEMWB_memRd_out", false,-1);
        tracep->declBus(c+50,"PIPELINE MEM_WB_M io_MEMWB_rd_out", false,-1, 4,0);
        tracep->declBus(c+51,"PIPELINE MEM_WB_M io_MEMWB_dataMem_out", false,-1, 31,0);
        tracep->declBus(c+52,"PIPELINE MEM_WB_M io_MEMWB_alu_out", false,-1, 31,0);
        tracep->declBit(c+47,"PIPELINE MEM_WB_M io_MEMWB_memToReg_out_REG", false,-1);
        tracep->declBit(c+48,"PIPELINE MEM_WB_M io_MEMWB_reg_w_out_REG", false,-1);
        tracep->declBit(c+49,"PIPELINE MEM_WB_M io_MEMWB_memRd_out_REG", false,-1);
        tracep->declBus(c+50,"PIPELINE MEM_WB_M io_MEMWB_rd_out_REG", false,-1, 4,0);
        tracep->declBus(c+51,"PIPELINE MEM_WB_M io_MEMWB_dataMem_out_REG", false,-1, 31,0);
        tracep->declBus(c+52,"PIPELINE MEM_WB_M io_MEMWB_alu_out_REG", false,-1, 31,0);
        tracep->declBit(c+146,"PIPELINE PC clock", false,-1);
        tracep->declBit(c+147,"PIPELINE PC reset", false,-1);
        tracep->declBus(c+53,"PIPELINE PC io_in", false,-1, 31,0);
        tracep->declBus(c+54,"PIPELINE PC io_out", false,-1, 31,0);
        tracep->declBus(c+54,"PIPELINE PC PC", false,-1, 31,0);
        tracep->declBus(c+54,"PIPELINE PC4 io_pc", false,-1, 31,0);
        tracep->declBus(c+55,"PIPELINE PC4 io_out", false,-1, 31,0);
        tracep->declBit(c+146,"PIPELINE InstMemory clock", false,-1);
        tracep->declBus(c+54,"PIPELINE InstMemory io_addr", false,-1, 31,0);
        tracep->declBus(c+56,"PIPELINE InstMemory io_data", false,-1, 31,0);
        tracep->declBus(c+56,"PIPELINE InstMemory imem_io_data_MPORT_data", false,-1, 31,0);
        tracep->declBus(c+96,"PIPELINE InstMemory imem_io_data_MPORT_addr", false,-1, 11,0);
        tracep->declBit(c+146,"PIPELINE DataMemory clock", false,-1);
        tracep->declBus(c+45,"PIPELINE DataMemory io_addr", false,-1, 31,0);
        tracep->declBus(c+43,"PIPELINE DataMemory io_dataIn", false,-1, 31,0);
        tracep->declBit(c+39,"PIPELINE DataMemory io_mem_read", false,-1);
        tracep->declBit(c+40,"PIPELINE DataMemory io_mem_write", false,-1);
        tracep->declBus(c+46,"PIPELINE DataMemory io_dataOut", false,-1, 31,0);
        tracep->declBus(c+97,"PIPELINE DataMemory Dmemory_io_dataOut_MPORT_data", false,-1, 31,0);
        tracep->declBus(c+98,"PIPELINE DataMemory Dmemory_io_dataOut_MPORT_addr", false,-1, 9,0);
        tracep->declBus(c+43,"PIPELINE DataMemory Dmemory_MPORT_data", false,-1, 31,0);
        tracep->declBus(c+98,"PIPELINE DataMemory Dmemory_MPORT_addr", false,-1, 9,0);
        tracep->declBit(c+149,"PIPELINE DataMemory Dmemory_MPORT_mask", false,-1);
        tracep->declBit(c+40,"PIPELINE DataMemory Dmemory_MPORT_en", false,-1);
        tracep->declBus(c+57,"PIPELINE control_module io_opcode", false,-1, 6,0);
        tracep->declBit(c+58,"PIPELINE control_module io_mem_write", false,-1);
        tracep->declBit(c+59,"PIPELINE control_module io_branch", false,-1);
        tracep->declBit(c+60,"PIPELINE control_module io_mem_read", false,-1);
        tracep->declBit(c+61,"PIPELINE control_module io_reg_write", false,-1);
        tracep->declBit(c+60,"PIPELINE control_module io_men_to_reg", false,-1);
        tracep->declBus(c+62,"PIPELINE control_module io_alu_operation", false,-1, 2,0);
        tracep->declBus(c+19,"PIPELINE control_module io_operand_A", false,-1, 1,0);
        tracep->declBit(c+63,"PIPELINE control_module io_operand_B", false,-1);
        tracep->declBus(c+64,"PIPELINE control_module io_extend", false,-1, 1,0);
        tracep->declBus(c+65,"PIPELINE control_module io_next_pc_sel", false,-1, 1,0);
        tracep->declBus(c+6,"PIPELINE ImmGen io_instr", false,-1, 31,0);
        tracep->declBus(c+5,"PIPELINE ImmGen io_pc", false,-1, 31,0);
        tracep->declBus(c+66,"PIPELINE ImmGen io_I_type", false,-1, 31,0);
        tracep->declBus(c+67,"PIPELINE ImmGen io_S_type", false,-1, 31,0);
        tracep->declBus(c+68,"PIPELINE ImmGen io_SB_type", false,-1, 31,0);
        tracep->declBus(c+69,"PIPELINE ImmGen io_U_type", false,-1, 31,0);
        tracep->declBus(c+70,"PIPELINE ImmGen io_UJ_type", false,-1, 31,0);
        tracep->declBus(c+99,"PIPELINE ImmGen io_I_type_hi", false,-1, 19,0);
        tracep->declBus(c+100,"PIPELINE ImmGen io_I_type_lo", false,-1, 11,0);
        tracep->declBus(c+101,"PIPELINE ImmGen io_S_type_hi_lo", false,-1, 6,0);
        tracep->declBus(c+12,"PIPELINE ImmGen io_S_type_lo", false,-1, 4,0);
        tracep->declBus(c+102,"PIPELINE ImmGen sbImm_hi_hi_hi", false,-1, 18,0);
        tracep->declBit(c+103,"PIPELINE ImmGen sbImm_hi_lo", false,-1);
        tracep->declBus(c+104,"PIPELINE ImmGen sbImm_lo_hi_hi", false,-1, 5,0);
        tracep->declBus(c+105,"PIPELINE ImmGen sbImm_lo_hi_lo", false,-1, 3,0);
        tracep->declBus(c+106,"PIPELINE ImmGen sbImm", false,-1, 31,0);
        tracep->declBus(c+107,"PIPELINE ImmGen io_U_type_hi", false,-1, 19,0);
        tracep->declBus(c+108,"PIPELINE ImmGen ujImm_hi_hi_hi", false,-1, 10,0);
        tracep->declBus(c+109,"PIPELINE ImmGen ujImm_hi_lo", false,-1, 7,0);
        tracep->declBit(c+110,"PIPELINE ImmGen ujImm_lo_hi_hi", false,-1);
        tracep->declBus(c+111,"PIPELINE ImmGen ujImm_lo_hi_lo", false,-1, 9,0);
        tracep->declBus(c+112,"PIPELINE ImmGen ujImm", false,-1, 31,0);
        tracep->declBit(c+146,"PIPELINE RegFile clock", false,-1);
        tracep->declBit(c+147,"PIPELINE RegFile reset", false,-1);
        tracep->declBus(c+7,"PIPELINE RegFile io_rs1", false,-1, 4,0);
        tracep->declBus(c+8,"PIPELINE RegFile io_rs2", false,-1, 4,0);
        tracep->declBit(c+48,"PIPELINE RegFile io_reg_write", false,-1);
        tracep->declBus(c+50,"PIPELINE RegFile io_w_reg", false,-1, 4,0);
        tracep->declBus(c+71,"PIPELINE RegFile io_w_data", false,-1, 31,0);
        tracep->declBus(c+72,"PIPELINE RegFile io_rdata1", false,-1, 31,0);
        tracep->declBus(c+73,"PIPELINE RegFile io_rdata2", false,-1, 31,0);
        tracep->declBus(c+113,"PIPELINE RegFile regfile_0", false,-1, 31,0);
        tracep->declBus(c+114,"PIPELINE RegFile regfile_1", false,-1, 31,0);
        tracep->declBus(c+115,"PIPELINE RegFile regfile_2", false,-1, 31,0);
        tracep->declBus(c+116,"PIPELINE RegFile regfile_3", false,-1, 31,0);
        tracep->declBus(c+117,"PIPELINE RegFile regfile_4", false,-1, 31,0);
        tracep->declBus(c+118,"PIPELINE RegFile regfile_5", false,-1, 31,0);
        tracep->declBus(c+119,"PIPELINE RegFile regfile_6", false,-1, 31,0);
        tracep->declBus(c+120,"PIPELINE RegFile regfile_7", false,-1, 31,0);
        tracep->declBus(c+121,"PIPELINE RegFile regfile_8", false,-1, 31,0);
        tracep->declBus(c+122,"PIPELINE RegFile regfile_9", false,-1, 31,0);
        tracep->declBus(c+123,"PIPELINE RegFile regfile_10", false,-1, 31,0);
        tracep->declBus(c+124,"PIPELINE RegFile regfile_11", false,-1, 31,0);
        tracep->declBus(c+125,"PIPELINE RegFile regfile_12", false,-1, 31,0);
        tracep->declBus(c+126,"PIPELINE RegFile regfile_13", false,-1, 31,0);
        tracep->declBus(c+127,"PIPELINE RegFile regfile_14", false,-1, 31,0);
        tracep->declBus(c+128,"PIPELINE RegFile regfile_15", false,-1, 31,0);
        tracep->declBus(c+129,"PIPELINE RegFile regfile_16", false,-1, 31,0);
        tracep->declBus(c+130,"PIPELINE RegFile regfile_17", false,-1, 31,0);
        tracep->declBus(c+131,"PIPELINE RegFile regfile_18", false,-1, 31,0);
        tracep->declBus(c+132,"PIPELINE RegFile regfile_19", false,-1, 31,0);
        tracep->declBus(c+133,"PIPELINE RegFile regfile_20", false,-1, 31,0);
        tracep->declBus(c+134,"PIPELINE RegFile regfile_21", false,-1, 31,0);
        tracep->declBus(c+135,"PIPELINE RegFile regfile_22", false,-1, 31,0);
        tracep->declBus(c+136,"PIPELINE RegFile regfile_23", false,-1, 31,0);
        tracep->declBus(c+137,"PIPELINE RegFile regfile_24", false,-1, 31,0);
        tracep->declBus(c+138,"PIPELINE RegFile regfile_25", false,-1, 31,0);
        tracep->declBus(c+139,"PIPELINE RegFile regfile_26", false,-1, 31,0);
        tracep->declBus(c+140,"PIPELINE RegFile regfile_27", false,-1, 31,0);
        tracep->declBus(c+141,"PIPELINE RegFile regfile_28", false,-1, 31,0);
        tracep->declBus(c+142,"PIPELINE RegFile regfile_29", false,-1, 31,0);
        tracep->declBus(c+143,"PIPELINE RegFile regfile_30", false,-1, 31,0);
        tracep->declBus(c+144,"PIPELINE RegFile regfile_31", false,-1, 31,0);
        tracep->declBus(c+27,"PIPELINE ALU_Control io_func3", false,-1, 2,0);
        tracep->declBit(c+28,"PIPELINE ALU_Control io_func7", false,-1);
        tracep->declBus(c+33,"PIPELINE ALU_Control io_aluOp", false,-1, 2,0);
        tracep->declBus(c+74,"PIPELINE ALU_Control io_out", false,-1, 4,0);
        tracep->declBus(c+75,"PIPELINE ALU io_in_A", false,-1, 31,0);
        tracep->declBus(c+76,"PIPELINE ALU io_in_B", false,-1, 31,0);
        tracep->declBus(c+74,"PIPELINE ALU io_alu_Op", false,-1, 4,0);
        tracep->declBus(c+38,"PIPELINE ALU io_out", false,-1, 31,0);
        tracep->declBus(c+13,"PIPELINE Branch_M io_fnct3", false,-1, 2,0);
        tracep->declBit(c+59,"PIPELINE Branch_M io_branch", false,-1);
        tracep->declBus(c+77,"PIPELINE Branch_M io_arg_x", false,-1, 31,0);
        tracep->declBus(c+78,"PIPELINE Branch_M io_arg_y", false,-1, 31,0);
        tracep->declBit(c+79,"PIPELINE Branch_M io_br_taken", false,-1);
        tracep->declBus(c+11,"PIPELINE JALR io_imme", false,-1, 31,0);
        tracep->declBus(c+80,"PIPELINE JALR io_rdata1", false,-1, 31,0);
        tracep->declBus(c+81,"PIPELINE JALR io_out", false,-1, 31,0);
        tracep->declBus(c+145,"PIPELINE JALR computedAddr", false,-1, 31,0);
        tracep->declBus(c+21,"PIPELINE Forwarding io_IDEX_rs1", false,-1, 4,0);
        tracep->declBus(c+22,"PIPELINE Forwarding io_IDEX_rs2", false,-1, 4,0);
        tracep->declBus(c+44,"PIPELINE Forwarding io_EXMEM_rd", false,-1, 4,0);
        tracep->declBit(c+42,"PIPELINE Forwarding io_EXMEM_regWr", false,-1);
        tracep->declBus(c+50,"PIPELINE Forwarding io_MEMWB_rd", false,-1, 4,0);
        tracep->declBit(c+48,"PIPELINE Forwarding io_MEMWB_regWr", false,-1);
        tracep->declBus(c+82,"PIPELINE Forwarding io_forward_a", false,-1, 1,0);
        tracep->declBus(c+83,"PIPELINE Forwarding io_forward_b", false,-1, 1,0);
        tracep->declBus(c+6,"PIPELINE HazardDetect io_IF_ID_inst", false,-1, 31,0);
        tracep->declBit(c+30,"PIPELINE HazardDetect io_ID_EX_memRead", false,-1);
        tracep->declBus(c+25,"PIPELINE HazardDetect io_ID_EX_rd", false,-1, 4,0);
        tracep->declBus(c+4,"PIPELINE HazardDetect io_pc_in", false,-1, 31,0);
        tracep->declBus(c+5,"PIPELINE HazardDetect io_current_pc", false,-1, 31,0);
        tracep->declBit(c+84,"PIPELINE HazardDetect io_inst_forward", false,-1);
        tracep->declBit(c+85,"PIPELINE HazardDetect io_pc_forward", false,-1);
        tracep->declBit(c+86,"PIPELINE HazardDetect io_ctrl_forward", false,-1);
        tracep->declBus(c+6,"PIPELINE HazardDetect io_inst_out", false,-1, 31,0);
        tracep->declBus(c+4,"PIPELINE HazardDetect io_pc_out", false,-1, 31,0);
        tracep->declBus(c+5,"PIPELINE HazardDetect io_current_pc_out", false,-1, 31,0);
        tracep->declBus(c+87,"PIPELINE HazardDetect Rs1", false,-1, 4,0);
        tracep->declBus(c+88,"PIPELINE HazardDetect Rs2", false,-1, 4,0);
        tracep->declBus(c+25,"PIPELINE Branch_Forward io_ID_EX_RD", false,-1, 4,0);
        tracep->declBus(c+44,"PIPELINE Branch_Forward io_EX_MEM_RD", false,-1, 4,0);
        tracep->declBus(c+50,"PIPELINE Branch_Forward io_MEM_WB_RD", false,-1, 4,0);
        tracep->declBit(c+30,"PIPELINE Branch_Forward io_ID_EX_memRd", false,-1);
        tracep->declBit(c+39,"PIPELINE Branch_Forward io_EX_MEM_memRd", false,-1);
        tracep->declBit(c+49,"PIPELINE Branch_Forward io_MEM_WB_memRd", false,-1);
        tracep->declBus(c+87,"PIPELINE Branch_Forward io_rs1", false,-1, 4,0);
        tracep->declBus(c+88,"PIPELINE Branch_Forward io_rs2", false,-1, 4,0);
        tracep->declBit(c+59,"PIPELINE Branch_Forward io_ctrl_branch", false,-1);
        tracep->declBus(c+89,"PIPELINE Branch_Forward io_forward_rs1", false,-1, 3,0);
        tracep->declBus(c+90,"PIPELINE Branch_Forward io_forward_rs2", false,-1, 3,0);
        tracep->declBus(c+87,"PIPELINE Structural io_rs1", false,-1, 4,0);
        tracep->declBus(c+88,"PIPELINE Structural io_rs2", false,-1, 4,0);
        tracep->declBit(c+42,"PIPELINE Structural io_MEM_WB_regWr", false,-1);
        tracep->declBus(c+50,"PIPELINE Structural io_MEM_WB_Rd", false,-1, 4,0);
        tracep->declBit(c+91,"PIPELINE Structural io_fwd_rs1", false,-1);
        tracep->declBit(c+92,"PIPELINE Structural io_fwd_rs2", false,-1);
    }
}

void VPIPELINE::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VPIPELINE::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VPIPELINE__Syms* __restrict vlSymsp = static_cast<VPIPELINE__Syms*>(userp);
    VPIPELINE* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VPIPELINE::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VPIPELINE__Syms* __restrict vlSymsp = static_cast<VPIPELINE__Syms*>(userp);
    VPIPELINE* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(((IData)(vlTOPp->PIPELINE__DOT__HazardDetect_io_pc_forward)
                                    ? ((IData)(4U) 
                                       + vlTOPp->PIPELINE__DOT__PC__DOT__PC)
                                    : ((1U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                        ? (((IData)(vlTOPp->PIPELINE__DOT__Branch_M_io_br_taken) 
                                            & (IData)(vlTOPp->PIPELINE__DOT__control_module_io_branch))
                                            ? 0U : 
                                           ((IData)(4U) 
                                            + vlTOPp->PIPELINE__DOT__PC__DOT__PC))
                                        : ((2U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                            ? 0U : 
                                           ((3U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                             ? 0U : 
                                            ((IData)(4U) 
                                             + vlTOPp->PIPELINE__DOT__PC__DOT__PC)))))),32);
        tracep->fullIData(oldp+2,(((IData)(vlTOPp->PIPELINE__DOT__HazardDetect_io_pc_forward)
                                    ? vlTOPp->PIPELINE__DOT__PC_for
                                    : ((1U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                        ? (((IData)(vlTOPp->PIPELINE__DOT__Branch_M_io_br_taken) 
                                            & (IData)(vlTOPp->PIPELINE__DOT__control_module_io_branch))
                                            ? 0U : vlTOPp->PIPELINE__DOT__PC_for)
                                        : ((2U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                            ? 0U : 
                                           ((3U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                             ? 0U : vlTOPp->PIPELINE__DOT__PC_for))))),32);
        tracep->fullIData(oldp+3,(((IData)(vlTOPp->PIPELINE__DOT__HazardDetect_io_pc_forward)
                                    ? vlTOPp->PIPELINE__DOT__Instruction_F
                                    : ((1U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                        ? (((IData)(vlTOPp->PIPELINE__DOT__Branch_M_io_br_taken) 
                                            & (IData)(vlTOPp->PIPELINE__DOT__control_module_io_branch))
                                            ? 0U : vlTOPp->PIPELINE__DOT__Instruction_F)
                                        : ((2U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                            ? 0U : 
                                           ((3U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                             ? 0U : vlTOPp->PIPELINE__DOT__Instruction_F))))),32);
        tracep->fullIData(oldp+4,(vlTOPp->PIPELINE__DOT__IF_ID___DOT__Pc4_In),32);
        tracep->fullIData(oldp+5,(vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_pc),32);
        tracep->fullIData(oldp+6,(vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr),32);
        tracep->fullCData(oldp+7,(vlTOPp->PIPELINE__DOT__RegFile_io_rs1),5);
        tracep->fullCData(oldp+8,(vlTOPp->PIPELINE__DOT__RegFile_io_rs2),5);
        tracep->fullIData(oldp+9,(((IData)(vlTOPp->PIPELINE__DOT__Structural_io_fwd_rs1)
                                    ? ((IData)(vlTOPp->PIPELINE__DOT__Structural_io_fwd_rs1)
                                        ? vlTOPp->PIPELINE__DOT__RegFile_io_w_data
                                        : 0U) : vlTOPp->PIPELINE__DOT__RegFile_io_rdata1)),32);
        tracep->fullIData(oldp+10,(((IData)(vlTOPp->PIPELINE__DOT__Structural_io_fwd_rs2)
                                     ? ((IData)(vlTOPp->PIPELINE__DOT__Structural_io_fwd_rs2)
                                         ? vlTOPp->PIPELINE__DOT__RegFile_io_w_data
                                         : 0U) : vlTOPp->PIPELINE__DOT__RegFile_io_rdata2)),32);
        tracep->fullIData(oldp+11,(((2U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_extend))
                                     ? (0xfffff000U 
                                        & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                     : vlTOPp->PIPELINE__DOT___ImmValue_T_3)),32);
        tracep->fullCData(oldp+12,((0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                             >> 7U))),5);
        tracep->fullCData(oldp+13,((7U & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                          >> 0xcU))),3);
        tracep->fullBit(oldp+14,((1U & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                        >> 0x1eU))));
        tracep->fullBit(oldp+15,(((~ (IData)(vlTOPp->PIPELINE__DOT__HazardDetect_io_ctrl_forward)) 
                                  & ((0x33U != (0x7fU 
                                                & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                     & ((0x13U != (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                        & (0x23U == 
                                           (0x7fU & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)))))));
        tracep->fullBit(oldp+16,(((~ (IData)(vlTOPp->PIPELINE__DOT__HazardDetect_io_ctrl_forward)) 
                                  & ((0x33U != (0x7fU 
                                                & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                     & (IData)(vlTOPp->PIPELINE__DOT__control_module__DOT___GEN_51)))));
        tracep->fullBit(oldp+17,(((~ (IData)(vlTOPp->PIPELINE__DOT__HazardDetect_io_ctrl_forward)) 
                                  & ((0x33U == (0x7fU 
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
                                                       | (IData)(vlTOPp->PIPELINE__DOT__control_module__DOT___GEN_5)))))))))));
        tracep->fullCData(oldp+18,(((IData)(vlTOPp->PIPELINE__DOT__HazardDetect_io_ctrl_forward)
                                     ? 0U : ((0x33U 
                                              == (0x7fU 
                                                  & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                              ? 0U : 
                                             ((0x13U 
                                               == (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                               ? 1U
                                               : ((0x23U 
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
        tracep->fullCData(oldp+19,(((0x33U == (0x7fU 
                                               & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                     ? 0U : ((0x13U 
                                              == (0x7fU 
                                                  & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                              ? 0U : 
                                             ((0x23U 
                                               == (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                               ? 0U
                                               : ((3U 
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
        tracep->fullBit(oldp+20,(((~ (IData)(vlTOPp->PIPELINE__DOT__HazardDetect_io_ctrl_forward)) 
                                  & ((0x33U != (0x7fU 
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
                                                       & (IData)(vlTOPp->PIPELINE__DOT__control_module__DOT___GEN_5)))))))))));
        tracep->fullCData(oldp+21,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs1_out_REG),5);
        tracep->fullCData(oldp+22,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs2_out_REG),5);
        tracep->fullIData(oldp+23,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs1_data_out_REG),32);
        tracep->fullIData(oldp+24,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs2_data_out_REG),32);
        tracep->fullCData(oldp+25,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG),5);
        tracep->fullIData(oldp+26,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_imm_out_REG),32);
        tracep->fullCData(oldp+27,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_func3_out_REG),3);
        tracep->fullBit(oldp+28,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_func7_out_REG));
        tracep->fullBit(oldp+29,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_MemWr_out_REG));
        tracep->fullBit(oldp+30,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_MemRd_out_REG));
        tracep->fullBit(oldp+31,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_Reg_W_out_REG));
        tracep->fullBit(oldp+32,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_MemToReg_out_REG));
        tracep->fullCData(oldp+33,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_AluOp_out_REG),3);
        tracep->fullCData(oldp+34,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_OpA_out_REG),2);
        tracep->fullBit(oldp+35,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_ctrl_OpB_out_REG));
        tracep->fullIData(oldp+36,(vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_IFID_pc4_out_REG),32);
        tracep->fullIData(oldp+37,(((0U == (IData)(vlTOPp->PIPELINE__DOT__Forwarding_io_forward_b))
                                     ? vlTOPp->PIPELINE__DOT__ID_EX___DOT__io_rs2_data_out_REG
                                     : vlTOPp->PIPELINE__DOT___GEN_42)),32);
        tracep->fullIData(oldp+38,((IData)(vlTOPp->PIPELINE__DOT__ALU__DOT___GEN_10)),32);
        tracep->fullBit(oldp+39,(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_memRd_out_REG));
        tracep->fullBit(oldp+40,(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_memWr_out_REG));
        tracep->fullBit(oldp+41,(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_memToReg_out_REG));
        tracep->fullBit(oldp+42,(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_reg_w_out_REG));
        tracep->fullIData(oldp+43,(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rs2_out_REG),32);
        tracep->fullCData(oldp+44,(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG),5);
        tracep->fullIData(oldp+45,(vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG),32);
        tracep->fullIData(oldp+46,(vlTOPp->PIPELINE__DOT__DataMemory_io_dataOut),32);
        tracep->fullBit(oldp+47,(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_memToReg_out_REG));
        tracep->fullBit(oldp+48,(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG));
        tracep->fullBit(oldp+49,(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_memRd_out_REG));
        tracep->fullCData(oldp+50,(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG),5);
        tracep->fullIData(oldp+51,(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_dataMem_out_REG),32);
        tracep->fullIData(oldp+52,(vlTOPp->PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_alu_out_REG),32);
        tracep->fullIData(oldp+53,(((IData)(vlTOPp->PIPELINE__DOT__HazardDetect_io_pc_forward)
                                     ? vlTOPp->PIPELINE__DOT__IF_ID___DOT__Pc4_In
                                     : ((1U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                         ? (((IData)(vlTOPp->PIPELINE__DOT__Branch_M_io_br_taken) 
                                             & (IData)(vlTOPp->PIPELINE__DOT__control_module_io_branch))
                                             ? ((((
                                                   (0x80000000U 
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
                                         : ((2U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel))
                                             ? ((((
                                                   (0x80000000U 
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
                                             : ((3U 
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
        tracep->fullIData(oldp+54,(vlTOPp->PIPELINE__DOT__PC__DOT__PC),32);
        tracep->fullIData(oldp+55,(((IData)(4U) + vlTOPp->PIPELINE__DOT__PC__DOT__PC)),32);
        tracep->fullIData(oldp+56,(vlTOPp->PIPELINE__DOT__InstMemory__DOT__imem
                                   [(0xfffU & (vlTOPp->PIPELINE__DOT__PC__DOT__PC 
                                               >> 2U))]),32);
        tracep->fullCData(oldp+57,((0x7fU & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)),7);
        tracep->fullBit(oldp+58,(((0x33U != (0x7fU 
                                             & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                  & ((0x13U != (0x7fU 
                                                & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                     & (0x23U == (0x7fU 
                                                  & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))))));
        tracep->fullBit(oldp+59,(vlTOPp->PIPELINE__DOT__control_module_io_branch));
        tracep->fullBit(oldp+60,(((0x33U != (0x7fU 
                                             & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                  & (IData)(vlTOPp->PIPELINE__DOT__control_module__DOT___GEN_51))));
        tracep->fullBit(oldp+61,(((0x33U == (0x7fU 
                                             & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                  | ((0x13U == (0x7fU 
                                                & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                     | ((0x23U != (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                        & ((3U == (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                           | ((0x63U 
                                               != (0x7fU 
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
        tracep->fullCData(oldp+62,(((0x33U == (0x7fU 
                                               & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                     ? 0U : ((0x13U 
                                              == (0x7fU 
                                                  & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                              ? 1U : 
                                             ((0x23U 
                                               == (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr))
                                               ? 5U
                                               : ((3U 
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
        tracep->fullBit(oldp+63,(((0x33U != (0x7fU 
                                             & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                  & ((0x13U == (0x7fU 
                                                & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                     | ((0x23U == (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                        | ((3U == (0x7fU 
                                                   & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)) 
                                           | ((0x63U 
                                               != (0x7fU 
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
        tracep->fullCData(oldp+64,(vlTOPp->PIPELINE__DOT__control_module_io_extend),2);
        tracep->fullCData(oldp+65,(vlTOPp->PIPELINE__DOT__control_module_io_next_pc_sel),2);
        tracep->fullIData(oldp+66,(((((0x80000000U 
                                       & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                       ? 0xfffffU : 0U) 
                                     << 0xcU) | (0xfffU 
                                                 & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                    >> 0x14U)))),32);
        tracep->fullIData(oldp+67,(((((0x80000000U 
                                       & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                       ? 0xfffffU : 0U) 
                                     << 0xcU) | ((0xfe0U 
                                                  & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                     >> 0x14U)) 
                                                 | (0x1fU 
                                                    & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                       >> 7U))))),32);
        tracep->fullIData(oldp+68,((((((0x80000000U 
                                        & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                        ? 0x7ffffU : 0U) 
                                      << 0xdU) | ((0x1000U 
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
        tracep->fullIData(oldp+69,((0xfffff000U & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)),32);
        tracep->fullIData(oldp+70,((((((0x80000000U 
                                        & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                        ? 0x7ffU : 0U) 
                                      << 0x15U) | (
                                                   (0x100000U 
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
        tracep->fullIData(oldp+71,(vlTOPp->PIPELINE__DOT__RegFile_io_w_data),32);
        tracep->fullIData(oldp+72,(vlTOPp->PIPELINE__DOT__RegFile_io_rdata1),32);
        tracep->fullIData(oldp+73,(vlTOPp->PIPELINE__DOT__RegFile_io_rdata2),32);
        tracep->fullCData(oldp+74,((0x1fU & (IData)(vlTOPp->PIPELINE__DOT__ALU_Control__DOT___GEN_4))),5);
        tracep->fullIData(oldp+75,(vlTOPp->PIPELINE__DOT__ALU_io_in_A),32);
        tracep->fullIData(oldp+76,(vlTOPp->PIPELINE__DOT__ALU_io_in_B),32);
        tracep->fullIData(oldp+77,(vlTOPp->PIPELINE__DOT__Branch_M_io_arg_x),32);
        tracep->fullIData(oldp+78,(vlTOPp->PIPELINE__DOT___Branch_M_io_arg_y_T_7),32);
        tracep->fullBit(oldp+79,(vlTOPp->PIPELINE__DOT__Branch_M_io_br_taken));
        tracep->fullIData(oldp+80,(((0xaU == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                     ? vlTOPp->PIPELINE__DOT__RegFile_io_w_data
                                     : ((9U == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                         ? vlTOPp->PIPELINE__DOT__DataMemory_io_dataOut
                                         : ((8U == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                             ? vlTOPp->PIPELINE__DOT__RegFile_io_w_data
                                             : ((7U 
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
        tracep->fullIData(oldp+81,((0xfffffffeU & (
                                                   ((2U 
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
                                                               : 0U)))))))))))))),32);
        tracep->fullCData(oldp+82,(vlTOPp->PIPELINE__DOT__Forwarding_io_forward_a),2);
        tracep->fullCData(oldp+83,(vlTOPp->PIPELINE__DOT__Forwarding_io_forward_b),2);
        tracep->fullBit(oldp+84,(vlTOPp->PIPELINE__DOT__HazardDetect_io_inst_forward));
        tracep->fullBit(oldp+85,(vlTOPp->PIPELINE__DOT__HazardDetect_io_pc_forward));
        tracep->fullBit(oldp+86,(vlTOPp->PIPELINE__DOT__HazardDetect_io_ctrl_forward));
        tracep->fullCData(oldp+87,((0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+88,((0x1fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                             >> 0x14U))),5);
        tracep->fullCData(oldp+89,(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1),4);
        tracep->fullCData(oldp+90,(vlTOPp->PIPELINE__DOT__Branch_Forward__DOT___GEN_28),4);
        tracep->fullBit(oldp+91,(vlTOPp->PIPELINE__DOT__Structural_io_fwd_rs1));
        tracep->fullBit(oldp+92,(vlTOPp->PIPELINE__DOT__Structural_io_fwd_rs2));
        tracep->fullIData(oldp+93,(vlTOPp->PIPELINE__DOT__PC_for),32);
        tracep->fullIData(oldp+94,(vlTOPp->PIPELINE__DOT__Instruction_F),32);
        tracep->fullIData(oldp+95,(vlTOPp->PIPELINE__DOT__d),32);
        tracep->fullSData(oldp+96,((0xfffU & (vlTOPp->PIPELINE__DOT__PC__DOT__PC 
                                              >> 2U))),12);
        tracep->fullIData(oldp+97,(vlTOPp->PIPELINE__DOT__DataMemory__DOT__Dmemory
                                   [(0x3ffU & vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG)]),32);
        tracep->fullSData(oldp+98,((0x3ffU & vlTOPp->PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG)),10);
        tracep->fullIData(oldp+99,(((0x80000000U & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                     ? 0xfffffU : 0U)),20);
        tracep->fullSData(oldp+100,((0xfffU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                               >> 0x14U))),12);
        tracep->fullCData(oldp+101,((0x7fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                              >> 0x19U))),7);
        tracep->fullIData(oldp+102,(((0x80000000U & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                      ? 0x7ffffU : 0U)),19);
        tracep->fullBit(oldp+103,((1U & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                         >> 7U))));
        tracep->fullCData(oldp+104,((0x3fU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                              >> 0x19U))),6);
        tracep->fullCData(oldp+105,((0xfU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                             >> 8U))),4);
        tracep->fullIData(oldp+106,(((((0x80000000U 
                                        & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                        ? 0x7ffffU : 0U) 
                                      << 0xdU) | ((0x1000U 
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
        tracep->fullIData(oldp+107,((0xfffffU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                                 >> 0xcU))),20);
        tracep->fullSData(oldp+108,(((0x80000000U & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                      ? 0x7ffU : 0U)),11);
        tracep->fullCData(oldp+109,((0xffU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                              >> 0xcU))),8);
        tracep->fullBit(oldp+110,((1U & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                         >> 0x14U))));
        tracep->fullSData(oldp+111,((0x3ffU & (vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr 
                                               >> 0x15U))),10);
        tracep->fullIData(oldp+112,(((((0x80000000U 
                                        & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                        ? 0x7ffU : 0U) 
                                      << 0x15U) | (
                                                   (0x100000U 
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
        tracep->fullIData(oldp+113,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_0),32);
        tracep->fullIData(oldp+114,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_1),32);
        tracep->fullIData(oldp+115,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_2),32);
        tracep->fullIData(oldp+116,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_3),32);
        tracep->fullIData(oldp+117,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_4),32);
        tracep->fullIData(oldp+118,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_5),32);
        tracep->fullIData(oldp+119,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_6),32);
        tracep->fullIData(oldp+120,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_7),32);
        tracep->fullIData(oldp+121,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_8),32);
        tracep->fullIData(oldp+122,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_9),32);
        tracep->fullIData(oldp+123,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_10),32);
        tracep->fullIData(oldp+124,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_11),32);
        tracep->fullIData(oldp+125,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_12),32);
        tracep->fullIData(oldp+126,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_13),32);
        tracep->fullIData(oldp+127,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_14),32);
        tracep->fullIData(oldp+128,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_15),32);
        tracep->fullIData(oldp+129,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_16),32);
        tracep->fullIData(oldp+130,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_17),32);
        tracep->fullIData(oldp+131,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_18),32);
        tracep->fullIData(oldp+132,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_19),32);
        tracep->fullIData(oldp+133,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_20),32);
        tracep->fullIData(oldp+134,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_21),32);
        tracep->fullIData(oldp+135,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_22),32);
        tracep->fullIData(oldp+136,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_23),32);
        tracep->fullIData(oldp+137,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_24),32);
        tracep->fullIData(oldp+138,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_25),32);
        tracep->fullIData(oldp+139,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_26),32);
        tracep->fullIData(oldp+140,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_27),32);
        tracep->fullIData(oldp+141,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_28),32);
        tracep->fullIData(oldp+142,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_29),32);
        tracep->fullIData(oldp+143,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_30),32);
        tracep->fullIData(oldp+144,(vlTOPp->PIPELINE__DOT__RegFile__DOT__regfile_31),32);
        tracep->fullIData(oldp+145,((((2U == (IData)(vlTOPp->PIPELINE__DOT__control_module_io_extend))
                                       ? (0xfffff000U 
                                          & vlTOPp->PIPELINE__DOT__IF_ID___DOT__S_instr)
                                       : vlTOPp->PIPELINE__DOT___ImmValue_T_3) 
                                     + ((0xaU == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                         ? vlTOPp->PIPELINE__DOT__RegFile_io_w_data
                                         : ((9U == (IData)(vlTOPp->PIPELINE__DOT__Branch_Forward_io_forward_rs1))
                                             ? vlTOPp->PIPELINE__DOT__DataMemory_io_dataOut
                                             : ((8U 
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
        tracep->fullBit(oldp+146,(vlTOPp->clock));
        tracep->fullBit(oldp+147,(vlTOPp->reset));
        tracep->fullCData(oldp+148,(vlTOPp->io_out),4);
        tracep->fullBit(oldp+149,(1U));
    }
}
