// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VPIPELINE_H_
#define _VPIPELINE_H_  // guard

#include "verilated_heavy.h"

//==========

class VPIPELINE__Syms;
class VPIPELINE_VerilatedVcd;


//----------

VL_MODULE(VPIPELINE) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(io_out,3,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ PIPELINE__DOT__control_module_io_branch;
        CData/*1:0*/ PIPELINE__DOT__control_module_io_extend;
        CData/*1:0*/ PIPELINE__DOT__control_module_io_next_pc_sel;
        CData/*4:0*/ PIPELINE__DOT__RegFile_io_rs1;
        CData/*4:0*/ PIPELINE__DOT__RegFile_io_rs2;
        CData/*0:0*/ PIPELINE__DOT__Branch_M_io_br_taken;
        CData/*1:0*/ PIPELINE__DOT__Forwarding_io_forward_a;
        CData/*1:0*/ PIPELINE__DOT__Forwarding_io_forward_b;
        CData/*0:0*/ PIPELINE__DOT__HazardDetect_io_inst_forward;
        CData/*0:0*/ PIPELINE__DOT__HazardDetect_io_pc_forward;
        CData/*0:0*/ PIPELINE__DOT__HazardDetect_io_ctrl_forward;
        CData/*3:0*/ PIPELINE__DOT__Branch_Forward_io_forward_rs1;
        CData/*0:0*/ PIPELINE__DOT__Structural_io_fwd_rs1;
        CData/*0:0*/ PIPELINE__DOT__Structural_io_fwd_rs2;
        CData/*4:0*/ PIPELINE__DOT__ID_EX___DOT__io_rs1_out_REG;
        CData/*4:0*/ PIPELINE__DOT__ID_EX___DOT__io_rs2_out_REG;
        CData/*4:0*/ PIPELINE__DOT__ID_EX___DOT__io_rd_out_REG;
        CData/*2:0*/ PIPELINE__DOT__ID_EX___DOT__io_func3_out_REG;
        CData/*0:0*/ PIPELINE__DOT__ID_EX___DOT__io_func7_out_REG;
        CData/*0:0*/ PIPELINE__DOT__ID_EX___DOT__io_ctrl_MemWr_out_REG;
        CData/*0:0*/ PIPELINE__DOT__ID_EX___DOT__io_ctrl_MemRd_out_REG;
        CData/*0:0*/ PIPELINE__DOT__ID_EX___DOT__io_ctrl_Reg_W_out_REG;
        CData/*0:0*/ PIPELINE__DOT__ID_EX___DOT__io_ctrl_MemToReg_out_REG;
        CData/*2:0*/ PIPELINE__DOT__ID_EX___DOT__io_ctrl_AluOp_out_REG;
        CData/*1:0*/ PIPELINE__DOT__ID_EX___DOT__io_ctrl_OpA_out_REG;
        CData/*0:0*/ PIPELINE__DOT__ID_EX___DOT__io_ctrl_OpB_out_REG;
        CData/*0:0*/ PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_memRd_out_REG;
        CData/*0:0*/ PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_memWr_out_REG;
        CData/*0:0*/ PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_memToReg_out_REG;
        CData/*0:0*/ PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_reg_w_out_REG;
        CData/*4:0*/ PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rd_out_REG;
        CData/*0:0*/ PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_memToReg_out_REG;
        CData/*0:0*/ PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_reg_w_out_REG;
        CData/*0:0*/ PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_memRd_out_REG;
        CData/*4:0*/ PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_rd_out_REG;
        CData/*0:0*/ PIPELINE__DOT__control_module__DOT___GEN_5;
        CData/*0:0*/ PIPELINE__DOT__control_module__DOT___GEN_51;
        CData/*5:0*/ PIPELINE__DOT__ALU_Control__DOT___GEN_4;
        CData/*1:0*/ PIPELINE__DOT__ALU__DOT___result_T_8;
        CData/*1:0*/ PIPELINE__DOT__ALU__DOT___result_T_12;
        CData/*0:0*/ PIPELINE__DOT__Forwarding__DOT___T_4;
        CData/*0:0*/ PIPELINE__DOT__Forwarding__DOT___T_11;
        CData/*1:0*/ PIPELINE__DOT__Forwarding__DOT___GEN_3;
        CData/*0:0*/ PIPELINE__DOT__Forwarding__DOT___T_32;
        CData/*0:0*/ PIPELINE__DOT__Forwarding__DOT___T_44;
        CData/*0:0*/ PIPELINE__DOT__Branch_Forward__DOT___T_4;
        CData/*0:0*/ PIPELINE__DOT__Branch_Forward__DOT___T_5;
        CData/*0:0*/ PIPELINE__DOT__Branch_Forward__DOT___GEN_5;
        CData/*0:0*/ PIPELINE__DOT__Branch_Forward__DOT___GEN_6;
        CData/*0:0*/ PIPELINE__DOT__Branch_Forward__DOT___T_12;
        CData/*0:0*/ PIPELINE__DOT__Branch_Forward__DOT___T_13;
        CData/*0:0*/ PIPELINE__DOT__Branch_Forward__DOT___T_17;
        CData/*0:0*/ PIPELINE__DOT__Branch_Forward__DOT___T_20;
        CData/*1:0*/ PIPELINE__DOT__Branch_Forward__DOT___GEN_12;
        CData/*1:0*/ PIPELINE__DOT__Branch_Forward__DOT___GEN_13;
        CData/*0:0*/ PIPELINE__DOT__Branch_Forward__DOT___T_37;
        CData/*0:0*/ PIPELINE__DOT__Branch_Forward__DOT___T_49;
        CData/*1:0*/ PIPELINE__DOT__Branch_Forward__DOT___GEN_28;
        IData/*31:0*/ PIPELINE__DOT__PC_io_in;
        IData/*31:0*/ PIPELINE__DOT__DataMemory_io_dataOut;
        IData/*31:0*/ PIPELINE__DOT__RegFile_io_w_data;
        IData/*31:0*/ PIPELINE__DOT__RegFile_io_rdata1;
        IData/*31:0*/ PIPELINE__DOT__RegFile_io_rdata2;
        IData/*31:0*/ PIPELINE__DOT__ALU_io_in_A;
    };
    struct {
        IData/*31:0*/ PIPELINE__DOT__ALU_io_in_B;
        IData/*31:0*/ PIPELINE__DOT__Branch_M_io_arg_x;
        IData/*31:0*/ PIPELINE__DOT__PC_for;
        IData/*31:0*/ PIPELINE__DOT__Instruction_F;
        IData/*31:0*/ PIPELINE__DOT___ImmValue_T_3;
        IData/*31:0*/ PIPELINE__DOT___Branch_M_io_arg_y_T_7;
        IData/*31:0*/ PIPELINE__DOT___GEN_45;
        IData/*31:0*/ PIPELINE__DOT__d;
        IData/*31:0*/ PIPELINE__DOT___GEN_42;
        IData/*31:0*/ PIPELINE__DOT__IF_ID___DOT__Pc4_In;
        IData/*31:0*/ PIPELINE__DOT__IF_ID___DOT__S_pc;
        IData/*31:0*/ PIPELINE__DOT__IF_ID___DOT__S_instr;
        IData/*31:0*/ PIPELINE__DOT__ID_EX___DOT__io_rs1_data_out_REG;
        IData/*31:0*/ PIPELINE__DOT__ID_EX___DOT__io_rs2_data_out_REG;
        IData/*31:0*/ PIPELINE__DOT__ID_EX___DOT__io_imm_out_REG;
        IData/*31:0*/ PIPELINE__DOT__ID_EX___DOT__io_IFID_pc4_out_REG;
        IData/*31:0*/ PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_rs2_out_REG;
        IData/*31:0*/ PIPELINE__DOT__EX_MEM_M__DOT__io_EXMEM_alu_out_REG;
        IData/*31:0*/ PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_dataMem_out_REG;
        IData/*31:0*/ PIPELINE__DOT__MEM_WB_M__DOT__io_MEMWB_alu_out_REG;
        IData/*31:0*/ PIPELINE__DOT__PC__DOT__PC;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_0;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_1;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_2;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_3;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_4;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_5;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_6;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_7;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_8;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_9;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_10;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_11;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_12;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_13;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_14;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_15;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_16;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_17;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_18;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_19;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_20;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_21;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_22;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_23;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_24;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_25;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_26;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_27;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_28;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_29;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_30;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT__regfile_31;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT___GEN_21;
        IData/*31:0*/ PIPELINE__DOT__RegFile__DOT___GEN_53;
        IData/*31:0*/ PIPELINE__DOT__ALU__DOT___result_T_2;
        IData/*31:0*/ PIPELINE__DOT__ALU__DOT___GEN_6;
        IData/*31:0*/ PIPELINE__DOT__ALU__DOT___GEN_8;
        QData/*62:0*/ PIPELINE__DOT__ALU__DOT___GEN_10;
        IData/*31:0*/ PIPELINE__DOT__InstMemory__DOT__imem[4096];
        IData/*31:0*/ PIPELINE__DOT__DataMemory__DOT__Dmemory[65536];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clock;
    CData/*0:0*/ __Vm_traceActivity[2];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VPIPELINE__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VPIPELINE);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VPIPELINE(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VPIPELINE();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VPIPELINE__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VPIPELINE__Syms* symsp, bool first);
  private:
    static QData _change_request(VPIPELINE__Syms* __restrict vlSymsp);
    static QData _change_request_1(VPIPELINE__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VPIPELINE__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VPIPELINE__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VPIPELINE__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(VPIPELINE__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(VPIPELINE__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(VPIPELINE__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
