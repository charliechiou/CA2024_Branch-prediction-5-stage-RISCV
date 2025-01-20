package Pipeline

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class EX_MEM_Test extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "EX_MEM" 
  it should "Pass inputs to outputs after one clock cycle" in {
    test(new EX_MEM) { c =>

      c.io.IDEX_MEMRD.poke(false.B)
      c.io.IDEX_MEMWR.poke(false.B)
      c.io.IDEX_MEMTOREG.poke(false.B)
      c.io.IDEX_REG_W.poke(false.B)
      c.io.IDEX_rs2.poke(0.S)
      c.io.IDEX_rd.poke(0.U)
      c.io.alu_out.poke(0.S)

      c.clock.step(1) 

      c.io.EXMEM_memRd_out.expect(false.B)
      c.io.EXMEM_memWr_out.expect(false.B)
      c.io.EXMEM_memToReg_out.expect(false.B)
      c.io.EXMEM_reg_w_out.expect(false.B)
      c.io.EXMEM_rs2_out.expect(0.S)
      c.io.EXMEM_rd_out.expect(0.U)
      c.io.EXMEM_alu_out.expect(0.S)

      c.io.IDEX_MEMRD.poke(true.B)
      c.io.IDEX_MEMWR.poke(true.B)
      c.io.IDEX_MEMTOREG.poke(true.B)
      c.io.IDEX_REG_W.poke(true.B)
      c.io.IDEX_rs2.poke(42.S)
      c.io.IDEX_rd.poke(5.U)
      c.io.alu_out.poke(123.S)

      c.clock.step(1)

      c.io.EXMEM_memRd_out.expect(true.B)
      c.io.EXMEM_memWr_out.expect(true.B)
      c.io.EXMEM_memToReg_out.expect(true.B)
      c.io.EXMEM_reg_w_out.expect(true.B)
      c.io.EXMEM_rs2_out.expect(42.S)
      c.io.EXMEM_rd_out.expect(5.U)
      c.io.EXMEM_alu_out.expect(123.S)

      c.io.IDEX_MEMRD.poke(false.B)
      c.io.IDEX_MEMWR.poke(false.B)
      c.io.IDEX_MEMTOREG.poke(false.B)
      c.io.IDEX_REG_W.poke(false.B)
      c.io.IDEX_rs2.poke(-100.S)
      c.io.IDEX_rd.poke(10.U)
      c.io.alu_out.poke(-50.S)

      c.clock.step(1) 

      c.io.EXMEM_memRd_out.expect(false.B)
      c.io.EXMEM_memWr_out.expect(false.B)
      c.io.EXMEM_memToReg_out.expect(false.B)
      c.io.EXMEM_reg_w_out.expect(false.B)
      c.io.EXMEM_rs2_out.expect(-100.S)
      c.io.EXMEM_rd_out.expect(10.U)
      c.io.EXMEM_alu_out.expect(-50.S)
    }
  }
}
