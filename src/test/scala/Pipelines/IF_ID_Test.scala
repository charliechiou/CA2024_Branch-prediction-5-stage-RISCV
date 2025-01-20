package Pipeline

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class IF_ID_Test extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "IF_ID" 

  it should "Initialize registers with default values" in {
    test(new IF_ID) { c =>

      c.io.pc_out.expect(0.S)          
      c.io.pc4_out.expect(0.U)         
      c.io.target_old.expect(0.S)         
      c.io.SelectedInstr_out.expect(0.U)   
      c.io.pred_out.expect(false.B)         
    }
  }

  it should "Pass inputs to outputs after one clock cycle" in {
    test(new IF_ID) { c =>

      val testPcIn = 42.S
      val testPc4In = 46.U
      val testTarget = 100.S
      val testSelectedInstr = "h12345678".U
      val testPredIn = true.B

      c.io.pc_in.poke(testPcIn)
      c.io.pc4_in.poke(testPc4In)
      c.io.target.poke(testTarget)
      c.io.SelectedInstr.poke(testSelectedInstr)
      c.io.pred_in.poke(testPredIn)

      c.clock.step(1) 

      c.io.pc_out.expect(testPcIn)
      c.io.pc4_out.expect(testPc4In)
      c.io.target_old.expect(testTarget)
      c.io.SelectedInstr_out.expect(testSelectedInstr)
      c.io.pred_out.expect(testPredIn)
    }
  }
}
