package Pipeline

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class AluControlTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "AluControl" 
  it should "generate correct control signals" in {
    test(new AluControl) { c =>

      // Test R type
      c.io.func3.poke("b010".U)
      c.io.func7.poke(true.B)
      c.io.aluOp.poke(0.U)
      c.io.out.expect("b001010".U)

      c.io.func3.poke("b000".U)
      c.io.func7.poke(false.B)
      c.io.aluOp.poke(0.U)
      c.io.out.expect("b000000".U)

      // Test I type
      c.io.func3.poke("b101".U)
      c.io.func7.poke(false.B)
      c.io.aluOp.poke(1.U)
      c.io.out.expect("b00101".U)

      c.io.func3.poke("b011".U)
      c.io.aluOp.poke(1.U)
      c.io.out.expect("b00011".U)

      // Test SB type
      c.io.func3.poke("b110".U)
      c.io.aluOp.poke(2.U)
      c.io.out.expect("b010110".U)

      c.io.func3.poke("b001".U)
      c.io.aluOp.poke(2.U)
      c.io.out.expect("b010001".U)

      // Test Branch type
      c.io.aluOp.poke(3.U)
      c.io.out.expect("b11111".U)

      // Test Loads, S type, U type (lui), U type (auipc)
      c.io.aluOp.poke(4.U)
      c.io.out.expect("b00000".U)

      c.io.aluOp.poke(5.U)
      c.io.out.expect("b00000".U)

      c.io.aluOp.poke(6.U)
      c.io.out.expect("b00000".U)

      c.io.aluOp.poke(7.U)
      c.io.out.expect("b00000".U)

    }
  }
}
