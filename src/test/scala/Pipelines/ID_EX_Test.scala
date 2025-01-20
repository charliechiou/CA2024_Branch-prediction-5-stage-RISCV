package Pipeline

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class ID_EX_Test extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "ID_EX" 
  it should "Pass inputs to outputs after one clock cycle" in {
    test(new ID_EX) { c =>
      // Initialize inputs
      c.io.rs1_in.poke(1.U)
      c.io.rs2_in.poke(2.U)
      c.io.rs1_data_in.poke(10.S)
      c.io.rs2_data_in.poke(20.S)
      c.io.imm.poke(100.S)
      c.io.rd_in.poke(5.U)
      c.io.func3_in.poke(3.U)
      c.io.func7_in.poke(true.B)
      c.io.ctrl_MemWr_in.poke(true.B)
      c.io.ctrl_Branch_in.poke(false.B)
      c.io.ctrl_MemRd_in.poke(true.B)
      c.io.ctrl_Reg_W_in.poke(true.B)
      c.io.ctrl_MemToReg_in.poke(false.B)
      c.io.ctrl_AluOp_in.poke(2.U)
      c.io.ctrl_OpA_in.poke(1.U)
      c.io.ctrl_OpB_in.poke(true.B)
      c.io.ctrl_nextpc_in.poke(1.U)
      c.io.IFID_pc4_in.poke(4.U)

      // Clock step to register inputs
      c.clock.step(1)

      // Validate outputs
      c.io.rs1_out.expect(1.U)
      c.io.rs2_out.expect(2.U)
      c.io.rs1_data_out.expect(10.S)
      c.io.rs2_data_out.expect(20.S)
      c.io.imm_out.expect(100.S)
      c.io.rd_out.expect(5.U)
      c.io.func3_out.expect(3.U)
      c.io.func7_out.expect(true.B)
      c.io.ctrl_MemWr_out.expect(true.B)
      c.io.ctrl_Branch_out.expect(false.B)
      c.io.ctrl_MemRd_out.expect(true.B)
      c.io.ctrl_Reg_W_out.expect(true.B)
      c.io.ctrl_MemToReg_out.expect(false.B)
      c.io.ctrl_AluOp_out.expect(2.U)
      c.io.ctrl_OpA_out.expect(1.U)
      c.io.ctrl_OpB_out.expect(true.B)
      c.io.ctrl_nextpc_out.expect(1.U)
      c.io.IFID_pc4_out.expect(4.U)
    }
  }
}
