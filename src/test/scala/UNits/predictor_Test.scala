package Pipeline

import chisel3._
import chisel3.tester._
import org.scalatest.flatspec.AnyFlatSpec

class PredictorTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "Predictor" 
  it should "correctly handle state transitions and predictions" in {
    test(new Predictor) { c =>
      //initialize
      c.io.isBtype.poke(false.B)
      c.io.taken.poke(false.B)
      c.clock.step(1) //Strongly not taken
 
      c.io.isBtype.poke(false.B)
      c.io.taken.poke(false.B)
      c.clock.step(1)
      c.io.prediction.expect(false.B) 

      c.io.isBtype.poke(true.B)
      c.io.taken.poke(false.B)
      c.clock.step(1)
      c.io.prediction.expect(false.B) //Strongly not taken

      c.io.isBtype.poke(true.B)
      c.io.taken.poke(true.B)
      c.clock.step(1)
      c.io.prediction.expect(false.B) //Weakly not taken

      c.io.isBtype.poke(true.B)
      c.io.taken.poke(true.B)
      c.clock.step(1)
      c.io.prediction.expect(true.B) // Weakly taken

      c.io.isBtype.poke(true.B)
      c.io.taken.poke(false.B)
      c.clock.step(1)
      c.io.prediction.expect(false.B) // Weakly not taken

      c.io.isBtype.poke(true.B)
      c.io.taken.poke(true.B)
      c.clock.step(1)
      c.clock.step(1)
      c.io.prediction.expect(true.B) // Strongly taken
    }
  }
}
