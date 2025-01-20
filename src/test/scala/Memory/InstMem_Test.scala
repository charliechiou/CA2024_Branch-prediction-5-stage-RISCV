package Pipeline

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class InstMem_Tester extends AnyFlatSpec  with ChiselScalatestTester {
  behavior of "InstMem" 
  it should "Read data from file" in {
    test(new InstMem("./src/riscv/rv32ui-p-add.hex")) { c =>
      val testCases = Seq(
        (0.U, "h0500006f".U), // Address 0, Expect 0x0500006f
        (4.U, "h34202f73".U), // Address 4, Expect 0x34202f73
        (8.U, "h00800f93".U), // Address 8, Expect 0x00800f93
        (12.U, "h03ff0863".U) // Address 12, Expect 0x03ff0863
      )

      for ((addr, expectedData) <- testCases) {
        c.io.addr.poke(addr)           
        c.clock.step(1)                

        println(s"Address: $addr, Expected: $expectedData, Actual: 0x ${c.io.data.peek().litValue}")

        c.io.data.expect(expectedData) 
      }
    }
  }
}

