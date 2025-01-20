package Pipeline

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class ImmGeneratorTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "ImmGenerator" 
  it should "generate correct immediate values for all types" in {
    test(new ImmGenerator) { c =>
      // Helper function to sign-extend a value
      def signExtend(value: BigInt, bits: Int): BigInt = {
        val shift = 32 - bits
        (value << shift) >> shift
      }

      // Test Case 1: I-type immediate
      c.io.instr.poke("h00000093".U) // ADDI x1, x0, 0 -> Immediate: 0x000
      c.clock.step(1)
      c.io.I_type.expect(0.S)

      c.io.instr.poke("hFFF00093".U) // ADDI x1, x0, -1 -> Immediate: 0xFFF
      c.clock.step(1)
      c.io.I_type.expect(-1.S)

      // Test Case 2: S-type immediate
      c.io.instr.poke("h00F02023".U) // SW x15, 0(x0) -> Immediate: 0x00F
      c.clock.step(1)
      c.io.S_type.expect(0.S)

      c.io.instr.poke("hF8002023".U) // SW x15, -128(x0) -> Immediate: 0xF80
      c.clock.step(1)
      c.io.S_type.expect(-128.S)

      // Test Case 3: SB-type immediate
      c.io.instr.poke("h00008063".U) // BEQ x0, x0, 0 -> Immediate: 0x000
      c.io.pc.poke(0.U)
      c.clock.step(1)
      c.io.SB_type.expect(0.S)

      c.io.instr.poke("hFE008EE3".U) // BEQ x15, x0, -4 -> Immediate: 0xFFC (negative offset)
      c.io.pc.poke(8.U)
      c.clock.step(1)
      c.io.SB_type.expect(4.S)

      // Test Case 4: U-type immediate
      c.io.instr.poke("h000000B7".U) // LUI x1, 0 -> Immediate: 0x00000000
      c.clock.step(1)
      c.io.U_type.expect(0.S)

      // Test Case 5: UJ-type immediate
      c.io.instr.poke("h0000006F".U) // JAL x0, 0 -> Immediate: 0x00000000
      c.io.pc.poke(0.U)
      c.clock.step(1)
      c.io.UJ_type.expect(0.S)

      c.io.instr.poke("hFF00006F".U) // JAL x0, -16 -> Immediate: 0xFFFFFFF0
      c.io.pc.poke(16.U)
      c.clock.step(1)
      c.io.UJ_type.expect(-1046528.S)
    }
  }
}
