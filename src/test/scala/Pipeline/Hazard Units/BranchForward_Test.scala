package Pipeline

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class BranchForwardTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "BranchForward"
  it should "handle ALU hazards correctly" in {
    test(new BranchForward) { c =>
      c.io.ID_EX_RD.poke(5.U)
      c.io.EX_MEM_RD.poke(0.U)
      c.io.MEM_WB_RD.poke(0.U)
      c.io.ID_EX_memRd.poke(0.U)
      c.io.EX_MEM_memRd.poke(0.U)
      c.io.MEM_WB_memRd.poke(0.U)
      c.io.rs1.poke(5.U)
      c.io.rs2.poke(5.U)
      c.io.ctrl_branch.poke(1.U)

      // ALU hazard forwarding
      c.clock.step(1)
      c.io.forward_rs1.expect("b0001".U)
      c.io.forward_rs2.expect("b0001".U)
    }
  }

  it should "handle EX/MEM hazards correctly" in {
    test(new BranchForward) { c =>
      c.io.ID_EX_RD.poke(0.U)
      c.io.EX_MEM_RD.poke(5.U)
      c.io.MEM_WB_RD.poke(0.U)
      c.io.ID_EX_memRd.poke(0.U)
      c.io.EX_MEM_memRd.poke(0.U)
      c.io.MEM_WB_memRd.poke(0.U)
      c.io.rs1.poke(5.U)
      c.io.rs2.poke(5.U)
      c.io.ctrl_branch.poke(1.U)

      c.clock.step(1)
      c.io.forward_rs1.expect("b0010".U)
      c.io.forward_rs2.expect("b0010".U)
    }
  }

  it should "handle MEM/WB hazards correctly" in {
    test(new BranchForward) { c =>
      c.io.ID_EX_RD.poke(0.U)
      c.io.EX_MEM_RD.poke(0.U)
      c.io.MEM_WB_RD.poke(5.U)
      c.io.ID_EX_memRd.poke(0.U)
      c.io.EX_MEM_memRd.poke(0.U)
      c.io.MEM_WB_memRd.poke(0.U)
      c.io.rs1.poke(5.U)
      c.io.rs2.poke(5.U)
      c.io.ctrl_branch.poke(1.U)

      c.clock.step(1)
      c.io.forward_rs1.expect("b0011".U)
      c.io.forward_rs2.expect("b0011".U)
    }
  }

  it should "handle Jalr forwarding logic correctly" in {
    test(new BranchForward) { c =>
      c.io.ID_EX_RD.poke(5.U)
      c.io.EX_MEM_RD.poke(0.U)
      c.io.MEM_WB_RD.poke(0.U)
      c.io.ID_EX_memRd.poke(0.U)
      c.io.EX_MEM_memRd.poke(0.U)
      c.io.MEM_WB_memRd.poke(0.U)
      c.io.rs1.poke(5.U)
      c.io.ctrl_branch.poke(0.U)

      c.clock.step(1)
      c.io.forward_rs1.expect("b0110".U)
    }
  }
}
