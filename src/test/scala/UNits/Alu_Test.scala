package Pipeline

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import AluOpCode._

class ALUTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "ALU" 
  it should "perform correct operations" in {
    test(new ALU) { c =>

      // Test ALU_ADD and ALU_ADDI
      c.io.in_A.poke(10.S)
      c.io.in_B.poke(15.S)
      c.io.alu_Op.poke(ALU_ADD)
      c.io.out.expect(25.S)

      c.io.alu_Op.poke(ALU_ADDI)
      c.io.out.expect(25.S)

      // Test ALU_SUB
      c.io.alu_Op.poke(ALU_SUB)
      c.io.out.expect(-5.S)

      // Test ALU_SLL and ALU_SLLI
      c.io.in_A.poke(3.S) // 3 = 0b11
      c.io.in_B.poke(2.S) // Shift left by 2
      c.io.alu_Op.poke(ALU_SLL)
      c.io.out.expect(12.S) // 12 = 0b1100

      c.io.alu_Op.poke(ALU_SLLI)
      c.io.out.expect(12.S)

      // Test ALU_SLT and ALU_SLTI
      c.io.in_A.poke(5.S)
      c.io.in_B.poke(10.S)
      c.io.alu_Op.poke(ALU_SLT)
      c.io.out.expect(1.S)

      c.io.alu_Op.poke(ALU_SLTI)
      c.io.out.expect(1.S)

      // Test ALU_SLTU and ALU_SLTUI
      c.io.in_A.poke(-1.S) // Treated as unsigned: max value
      c.io.in_B.poke(0.S)
      c.io.alu_Op.poke(ALU_SLTU)
      c.io.out.expect(0.S)

      c.io.alu_Op.poke(ALU_SLTUI)
      c.io.out.expect(0.S)

      // Test ALU_XOR and ALU_XORI
      c.io.in_A.poke(6.S) // 6 = 0b110
      c.io.in_B.poke(3.S) // 3 = 0b011
      c.io.alu_Op.poke(ALU_XOR)
      c.io.out.expect(5.S) // 5 = 0b101

      c.io.alu_Op.poke(ALU_XORI)
      c.io.out.expect(5.S)

      // Test ALU_OR and ALU_ORI
      c.io.alu_Op.poke(ALU_OR)
      c.io.out.expect(7.S) // 7 = 0b111

      c.io.alu_Op.poke(ALU_ORI)
      c.io.out.expect(7.S)

      // Test ALU_AND and ALU_ANDI
      c.io.alu_Op.poke(ALU_AND)
      c.io.out.expect(2.S) // 2 = 0b010

      c.io.alu_Op.poke(ALU_ANDI)
      c.io.out.expect(2.S)

      // Test ALU_SRL and ALU_SRLI
      c.io.in_A.poke(16.S) // 16 = 0b10000
      c.io.in_B.poke(2.S)
      c.io.alu_Op.poke(ALU_SRL)
      c.io.out.expect(4.S) // 4 = 0b100

      c.io.alu_Op.poke(ALU_SRLI)
      c.io.out.expect(4.S)

      // Test ALU_SRA and ALU_SRAI
      c.io.in_A.poke(-16.S) // -16 = 0b1111111111110000 (sign-extended)
      c.io.alu_Op.poke(ALU_SRA)
      c.io.out.expect(-4.S) // -4 = 0b1111111111111100

      c.io.alu_Op.poke(ALU_SRAI)
      c.io.out.expect(-4.S)

      // Test ALU_JAL and ALU_JALR
      c.io.in_A.poke(42.S)
      c.io.alu_Op.poke(ALU_JAL)
      c.io.out.expect(42.S)

      c.io.alu_Op.poke(ALU_JALR)
      c.io.out.expect(42.S)
    }
  }
}
