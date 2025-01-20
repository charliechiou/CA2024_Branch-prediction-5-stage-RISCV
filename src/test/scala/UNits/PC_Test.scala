package Pipeline

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class PCTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "PC" 
  it should "update and hold the correct value" in {
    test(new PC) { c =>
      // Initial state: PC register should initialize to 0
      c.io.out.expect(0.S)

      // Test case 1: Update PC to 4
      c.io.in.poke(4.S)
      c.clock.step(1) // Advance one clock cycle
      c.io.out.expect(4.S)

      // Test case 2: Update PC to 100
      c.io.in.poke(100.S)
      c.clock.step(1)
      c.io.out.expect(100.S)

      // Test case 3: Update PC to -8
      c.io.in.poke(-8.S)
      c.clock.step(1)
      c.io.out.expect(-8.S)

      // Test case 4: Hold PC value (no change to input)
      c.io.in.poke(-8.S)
      c.clock.step(1)
      c.io.out.expect(-8.S)
    }
  }
}
