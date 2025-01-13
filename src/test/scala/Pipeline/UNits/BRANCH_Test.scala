package Pipeline

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class BranchTester extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "Branch" 
  it should "correctly evaluate branch conditions" in {
    test(new Branch) { c =>
      // Function to test a single case
      def testBranch(fnct3: Int, branch: Boolean, x: Int, y: Int, expected: Boolean): Unit = {
        c.io.fnct3.poke(fnct3.U)
        c.io.branch.poke(branch.B)
        c.io.arg_x.poke(x.S)
        c.io.arg_y.poke(y.S)
        c.clock.step()
        c.io.br_taken.expect(expected.B)
      }

      // beq (fnct3 = 0)
      testBranch(0, branch = true, x = 10, y = 10, expected = true)  // Equal
      testBranch(0, branch = true, x = 10, y = 5, expected = false) // Not equal

      // bne (fnct3 = 1)
      testBranch(1, branch = true, x = 10, y = 10, expected = false) // Equal
      testBranch(1, branch = true, x = 10, y = 5, expected = true)  // Not equal

      // blt (fnct3 = 4)
      testBranch(4, branch = true, x = 5, y = 10, expected = true)  // Less than
      testBranch(4, branch = true, x = 10, y = 5, expected = false) // Not less than

      // bge (fnct3 = 5)
      testBranch(5, branch = true, x = 10, y = 5, expected = true)  // Greater than or equal
      testBranch(5, branch = true, x = 5, y = 10, expected = false) // Not greater than or equal

      // bltu (fnct3 = 6)
      testBranch(6, branch = true, x = -1, y = 10, expected = false) // Unsigned: -1 is large
      testBranch(6, branch = true, x = 5, y = 10, expected = true)  // Unsigned less than

      // bgeu (fnct3 = 7)
      testBranch(7, branch = true, x = -1, y = 10, expected = true)  // Unsigned: -1 is large
      testBranch(7, branch = true, x = 5, y = 10, expected = false) // Unsigned not greater than or equal

      // branch = false (should always be false)
      testBranch(0, branch = false, x = 10, y = 10, expected = false)
      testBranch(1, branch = false, x = 10, y = 5, expected = false)
      testBranch(4, branch = false, x = 5, y = 10, expected = false)
    }
  }
}
