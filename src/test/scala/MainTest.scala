package Pipeline
import chisel3._
import org.scalatest.FreeSpec
import chiseltest._

class TOPTest extends FreeSpec with ChiselScalatestTester {
  "5-Stage test with stop condition" in {
    test(new CPU) { c =>
      while (c.io.out.peek().litValue == 0) {
        c.clock.step(1)
      }
    }
  }
}