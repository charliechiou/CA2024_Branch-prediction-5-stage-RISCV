package Pipeline

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class RegisterFileTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "RegisterFile"
  it should "initialize and perform read/write correctly" in {
    test(new RegisterFile) { c =>
      // initialize
      for (i <- 0 until 32) {
        c.io.rs1.poke(i.U)
        c.io.rs2.poke(i.U)
        c.io.reg_write.poke(false.B)
        c.io.w_reg.poke(0.U)
        c.io.w_data.poke(0.S)
        c.clock.step(1)

        // check the initialize data
        c.io.rdata1.expect(0.S)
        c.io.rdata2.expect(0.S)
      }

      // write and read
      c.io.reg_write.poke(true.B)
      c.io.w_reg.poke(5.U)
      c.io.w_data.poke(42.S)
      c.clock.step(1)

      // check
      c.io.rs1.poke(5.U)
      c.io.rs2.poke(5.U)
      c.io.reg_write.poke(false.B)
      c.clock.step(1)

      c.io.rdata1.expect(42.S)
      c.io.rdata2.expect(42.S)

      // check write x0
      c.io.reg_write.poke(true.B)
      c.io.w_reg.poke(0.U)
      c.io.w_data.poke(123.S)
      c.clock.step(1)

      // check x0
      c.io.rs1.poke(0.U)
      c.io.rs2.poke(0.U)
      c.io.reg_write.poke(false.B)
      c.clock.step(1)

      c.io.rdata1.expect(0.S)
      c.io.rdata2.expect(0.S)
    }
  }
}
