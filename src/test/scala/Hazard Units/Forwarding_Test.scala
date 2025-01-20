package Pipeline

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class ForwardingTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "Forwarding" 
  it should "handle EX Hazard correctly" in {
    test(new Forwarding) { c =>
      c.io.IDEX_rs1.poke(5.U)
      c.io.IDEX_rs2.poke(5.U)
      c.io.EXMEM_rd.poke(5.U)
      c.io.EXMEM_regWr.poke(1.U)
      c.io.MEMWB_rd.poke(0.U)
      c.io.MEMWB_regWr.poke(0.U)

      c.clock.step(1)
      c.io.forward_a.expect("b10".U)
      c.io.forward_b.expect("b10".U)

      c.io.IDEX_rs1.poke(5.U)
      c.io.IDEX_rs2.poke(6.U)
      c.io.EXMEM_rd.poke(5.U)
      c.io.EXMEM_regWr.poke(1.U)
      c.io.MEMWB_rd.poke(0.U)
      c.io.MEMWB_regWr.poke(0.U)

      c.clock.step(1)
      c.io.forward_a.expect("b10".U)
      c.io.forward_b.expect("b00".U)

      c.io.IDEX_rs1.poke(6.U)
      c.io.IDEX_rs2.poke(5.U)
      c.io.EXMEM_rd.poke(5.U)
      c.io.EXMEM_regWr.poke(1.U)
      c.io.MEMWB_rd.poke(0.U)
      c.io.MEMWB_regWr.poke(0.U)

      c.clock.step(1)
      c.io.forward_a.expect("b00".U)
      c.io.forward_b.expect("b10".U)
    }
  }

  it should "handle MEM Hazard correctly" in {
    test(new Forwarding) { c =>
      c.io.IDEX_rs1.poke(5.U)
      c.io.IDEX_rs2.poke(5.U)
      c.io.EXMEM_rd.poke(0.U)
      c.io.EXMEM_regWr.poke(0.U)
      c.io.MEMWB_rd.poke(5.U)
      c.io.MEMWB_regWr.poke(1.U)

      c.clock.step(1)
      c.io.forward_a.expect("b01".U)
      c.io.forward_b.expect("b01".U)

      c.io.IDEX_rs1.poke(5.U)
      c.io.IDEX_rs2.poke(6.U)
      c.io.EXMEM_rd.poke(0.U)
      c.io.EXMEM_regWr.poke(0.U)
      c.io.MEMWB_rd.poke(5.U)
      c.io.MEMWB_regWr.poke(1.U)

      c.clock.step(1)
      c.io.forward_a.expect("b01".U)
      c.io.forward_b.expect("b00".U)

      c.io.IDEX_rs1.poke(6.U)
      c.io.IDEX_rs2.poke(5.U)
      c.io.EXMEM_rd.poke(0.U)
      c.io.EXMEM_regWr.poke(0.U)
      c.io.MEMWB_rd.poke(5.U)
      c.io.MEMWB_regWr.poke(1.U)

      c.clock.step(1)
      c.io.forward_a.expect("b00".U)
      c.io.forward_b.expect("b01".U)
    }
  }

  it should "handle no hazards correctly" in {
    test(new Forwarding) { c =>
      c.io.IDEX_rs1.poke(5.U)
      c.io.IDEX_rs2.poke(6.U)
      c.io.EXMEM_rd.poke(0.U)
      c.io.EXMEM_regWr.poke(0.U)
      c.io.MEMWB_rd.poke(0.U)
      c.io.MEMWB_regWr.poke(0.U)

      c.clock.step(1)
      c.io.forward_a.expect("b00".U)
      c.io.forward_b.expect("b00".U)
    }
  }
}
