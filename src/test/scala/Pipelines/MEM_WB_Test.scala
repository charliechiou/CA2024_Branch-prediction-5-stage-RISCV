package Pipeline

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class MEM_WBTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "MEM_WB" 
  it should "Pass inputs to outputs after one clock cycle" in {
    test(new MEM_WB) { c =>
      c.io.EXMEM_MEMTOREG.poke(true.B)
      c.io.EXMEM_REG_W.poke(true.B)
      c.io.EXMEM_MEMRD.poke(false.B)
      c.io.EXMEM_rd.poke(5.U)
      c.io.in_dataMem_out.poke(123.S)
      c.io.in_alu_out.poke(456.S)

      c.clock.step(1)

      c.io.MEMWB_memToReg_out.expect(true.B)
      c.io.MEMWB_reg_w_out.expect(true.B)
      c.io.MEMWB_memRd_out.expect(false.B)
      c.io.MEMWB_rd_out.expect(5.U)
      c.io.MEMWB_dataMem_out.expect(123.S)
      c.io.MEMWB_alu_out.expect(456.S)

      c.io.EXMEM_MEMTOREG.poke(false.B)
      c.io.EXMEM_REG_W.poke(false.B)
      c.io.EXMEM_MEMRD.poke(true.B)
      c.io.EXMEM_rd.poke(10.U)
      c.io.in_dataMem_out.poke(789.S)
      c.io.in_alu_out.poke(1011.S)

      c.clock.step(1)

      c.io.MEMWB_memToReg_out.expect(false.B)
      c.io.MEMWB_reg_w_out.expect(false.B)
      c.io.MEMWB_memRd_out.expect(true.B)
      c.io.MEMWB_rd_out.expect(10.U)
      c.io.MEMWB_dataMem_out.expect(789.S)
      c.io.MEMWB_alu_out.expect(1011.S)
    }
  }
}
