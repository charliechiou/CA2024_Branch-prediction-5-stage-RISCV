package Pipeline

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class HazardDetectionTest extends AnyFlatSpec with ChiselScalatestTester {
  "HazardDetection" should "detect hazards correctly" in {
    test(new HazardDetection) { c =>
      // Case 1: Hazard detected (Rs1 matches ID_EX_rd)
      c.io.IF_ID_inst.poke("h00028033".U) // Rs1 = 0x02, Rs2 = 0x00
      c.io.ID_EX_memRead.poke(true.B)
      c.io.ID_EX_rd.poke(5.U)
      c.io.pc_in.poke(100.S)
      c.io.current_pc.poke(96.S)

      c.clock.step(1)

      c.io.inst_forward.expect(true.B)
      c.io.pc_forward.expect(true.B)
      c.io.ctrl_forward.expect(true.B)
      c.io.inst_out.expect("h00028033".U)
      c.io.pc_out.expect(100.S)
      c.io.current_pc_out.expect(96.S)

      // Case 2: Hazard detected (Rs2 matches ID_EX_rd)
      c.io.IF_ID_inst.poke("h0002A033".U) // Rs1 = 0x00, Rs2 = 0x02
      c.io.ID_EX_memRead.poke(true.B)
      c.io.ID_EX_rd.poke(5.U)
      c.io.pc_in.poke(104.S)
      c.io.current_pc.poke(100.S)

      c.clock.step(1)

      c.io.inst_forward.expect(true.B)
      c.io.pc_forward.expect(true.B)
      c.io.ctrl_forward.expect(true.B)
      c.io.inst_out.expect("h0002A033".U)
      c.io.pc_out.expect(104.S)
      c.io.current_pc_out.expect(100.S)
    }
  }
}
