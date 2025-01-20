package Pipeline

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class BranchTester extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "Branch" 
  it should "correctly evaluate branch conditions" in {
    test(new Branch) { c =>
      // Function to test a single case
      def testBranch(fnct3: Int, branch: Boolean, x: Int, y: Int, pred: Boolean, expectedActual: Boolean, expectedFlush: Boolean): Unit = {
        c.io.fnct3.poke(fnct3.U)
        c.io.branch.poke(branch.B)
        c.io.arg_x.poke(x.S)
        c.io.arg_y.poke(y.S)
        c.io.pred.poke(pred.B)
        c.clock.step()
        c.io.actual.expect(expectedActual.B)
        c.io.flush.expect(expectedFlush.B)
      }

      // beq (fnct3 = 0)
      testBranch(0, branch = true, x = 10, y = 10, pred = false, expectedActual = true, expectedFlush = true)  // Equal
      testBranch(0, branch = true, x = 10, y = 5, pred = true, expectedActual = false, expectedFlush = true)  // Not equal

      // bne (fnct3 = 1)
      testBranch(1, branch = true, x = 10, y = 10, pred = true, expectedActual = false, expectedFlush = true)  // Equal
      testBranch(1, branch = true, x = 10, y = 5, pred = false, expectedActual = true, expectedFlush = true)  // Not equal

      // blt (fnct3 = 4)
      testBranch(4, branch = true, x = 5, y = 10, pred = false, expectedActual = true, expectedFlush = true)   // Less than
      testBranch(4, branch = true, x = 10, y = 5, pred = true, expectedActual = false, expectedFlush = true)  // Not less than

      // bge (fnct3 = 5)
      testBranch(5, branch = true, x = 10, y = 5, pred = false, expectedActual = true, expectedFlush = true)  // Greater than or equal
      testBranch(5, branch = true, x = 5, y = 10, pred = true, expectedActual = false, expectedFlush = true) // Not greater than or equal

      // bltu (fnct3 = 6)
      testBranch(6, branch = true, x = 1, y = 10, pred = true, expectedActual = true, expectedFlush = false)  // Unsigned less than
      testBranch(6, branch = true, x = -1, y = 10, pred = false, expectedActual = false, expectedFlush = false) // Unsigned: -1 is greater

      // bgeu (fnct3 = 7)
      testBranch(7, branch = true, x = 1, y = 10, pred = false, expectedActual = false, expectedFlush = false)  // Unsigned less than
      testBranch(7, branch = true, x = -1, y = 10, pred = true, expectedActual = true, expectedFlush = false)  // Unsigned: -1 is greater

      // branch = false (should always be false for actual and flush)
      testBranch(0, branch = false, x = 10, y = 10, pred = false, expectedActual = false, expectedFlush = false)
      testBranch(1, branch = false, x = 10, y = 5, pred = true, expectedActual = false, expectedFlush = true)
      testBranch(4, branch = false, x = 5, y = 10, pred = false, expectedActual = false, expectedFlush = false)
    }
  }
}
