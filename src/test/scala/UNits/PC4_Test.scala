package Pipeline

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class PC4Test extends AnyFlatSpec with ChiselScalatestTester {
  "PC4" should "correctly compute PC + 4" in {
    test(new PC4) { c =>
      // Test case 1: Input PC = 0
      c.io.pc.poke(0.U)
      c.clock.step(1)
      c.io.out.expect(4.U)

      // Test case 2: Input PC = 4
      c.io.pc.poke(4.U)
      c.clock.step(1)
      c.io.out.expect(8.U)

      // Test case 3: Input PC = 100
      c.io.pc.poke(100.U)
      c.clock.step(1)
      c.io.out.expect(104.U)
    }
  }
}
