package Pipeline

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class DataMemoryTester extends AnyFlatSpec  with ChiselScalatestTester {
    behavior of "DataMemory" 
    it should "Write and read data from memory" in {
    test(new DataMemory) { c =>
      // Initialize
      c.io.addr.poke(0.U)       // Address 0
      c.io.dataIn.poke(42.S)    // Write data = 42
      c.io.mem_write.poke(false.B) // Disable write initially
      c.io.mem_read.poke(false.B)  // Disable read initially
      c.clock.step(1)           // Advance clock

      // Write data
      c.io.mem_write.poke(true.B)  // Enable write
      c.clock.step(1)              // Advance clock
      c.io.mem_write.poke(false.B) // Disable write after one cycle

      // Read data
      c.io.mem_read.poke(true.B)   // Enable read
      c.clock.step(1)              // Advance clock
      c.io.dataOut.expect(42.S)    // Expect dataOut = 42
      c.io.mem_read.poke(false.B)  // Disable read

      // Write and read from another address
      c.io.addr.poke(1.U)          // Address 1
      c.io.dataIn.poke(-15.S)      // Write data = -15
      c.io.mem_write.poke(true.B)  // Enable write
      c.clock.step(1)              // Advance clock
      c.io.mem_write.poke(false.B) // Disable write

      c.io.mem_read.poke(true.B)   // Enable read
      c.clock.step(1)              // Advance clock
      c.io.dataOut.expect(-15.S)   // Expect dataOut = -15
    }
  }
}
