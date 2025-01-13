package Pipeline

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class JalrTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "Jalr" 
  it should "compute the correct jump address with alignment" in {
    test(new Jalr) { c =>
      // Test case 1: imme = 0, rdata1 = 0
      c.io.imme.poke(0.U)
      c.io.rdata1.poke(0.U)
      c.clock.step(1)
      c.io.out.expect(0.U)

      // Test case 2: imme = 4, rdata1 = 8
      c.io.imme.poke(4.U)
      c.io.rdata1.poke(8.U)
      c.clock.step(1)
      c.io.out.expect(12.U) // 4 + 8 = 12 (no masking required)

      // Test case 3: imme = 5, rdata1 = 10 (unaligned address)
      c.io.imme.poke(5.U)
      c.io.rdata1.poke(10.U)
      c.clock.step(1)
      c.io.out.expect(14.U) // (5 + 10 = 15, aligned to 14)

      // Test case 4: imme = 0xFFFFFFFE, rdata1 = 1 (boundary test)
      c.io.imme.poke("hFFFFFFFE".U)
      c.io.rdata1.poke(1.U)
      c.clock.step(1)
      c.io.out.expect("hFFFFFFFE".U) // 0xFFFFFFFE + 1 = 0xFFFFFFFF, aligned to 0xFFFFFFFE

      // Test case 5: imme = 0x1234, rdata1 = 0x5678
      c.io.imme.poke("h1234".U)
      c.io.rdata1.poke("h5678".U)
      c.clock.step(1)
      c.io.out.expect("h68AC".U) // 0x1234 + 0x5678 = 0x68AC (already aligned)
    }
  }
}
