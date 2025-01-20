package Pipeline

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class ControlTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "Control" 
  it should "generate correct signals for each opcode" in {
    test(new Control) { c =>
      // Function to test opcodes
      def testOpcode(opcode: Int, expectedSignals: (Bool, Bool, Bool, Bool, Bool, UInt, UInt, Bool, UInt, UInt)) = {
        c.io.opcode.poke(opcode.U)
        c.clock.step(1)

        val (memWrite, branch, memRead, regWrite, menToReg, aluOp, opA, opB, ext, nextPcSel) = expectedSignals
        c.io.mem_write.expect(memWrite)
        c.io.branch.expect(branch)
        c.io.mem_read.expect(memRead)
        c.io.reg_write.expect(regWrite)
        c.io.men_to_reg.expect(menToReg)
        c.io.alu_operation.expect(aluOp)
        c.io.operand_A.expect(opA)
        c.io.operand_B.expect(opB)
        c.io.extend.expect(ext)
        c.io.next_pc_sel.expect(nextPcSel)
      }

      // R-type instruction (opcode 51)
      testOpcode(51, (false.B, false.B, false.B, true.B, false.B, 0.U, 0.U, false.B, 0.U, 0.U))

      // I-type instruction (opcode 19)
      testOpcode(19, (false.B, false.B, false.B, true.B, false.B, 1.U, 0.U, true.B, 0.U, 0.U))

      // S-type instruction (opcode 35)
      testOpcode(35, (true.B, false.B, false.B, false.B, false.B, 5.U, 0.U, true.B, 1.U, 0.U))

      // Load instruction (opcode 3)
      testOpcode(3, (false.B, false.B, true.B, true.B, true.B, 4.U, 0.U, true.B, 0.U, 0.U))

      // SB-type instruction (opcode 99)
      testOpcode(99, (false.B, true.B, false.B, false.B, false.B, 2.U, 0.U, false.B, 0.U, 1.U))

      // UJ-type instruction (opcode 111)
      testOpcode(111, (false.B, false.B, false.B, true.B, false.B, 3.U, 1.U, false.B, 0.U, 2.U))

      // Jalr instruction (opcode 103)
      testOpcode(103, (false.B, false.B, false.B, true.B, false.B, 3.U, 1.U, false.B, 0.U, 3.U))

      // U-type (LUI) instruction (opcode 55)
      testOpcode(55, (false.B, false.B, false.B, true.B, false.B, 6.U, 3.U, true.B, 2.U, 0.U))

      // U-type (AUIPC) instruction (opcode 23)
      testOpcode(23, (false.B, false.B, false.B, true.B, false.B, 7.U, 2.U, true.B, 2.U, 0.U))
    }
  }
}
