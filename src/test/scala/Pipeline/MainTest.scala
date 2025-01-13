package Pipeline
import chisel3._
import org.scalatest.flatspec.AnyFlatSpec
import chiseltest._

class MainTest extends AnyFlatSpec with ChiselScalatestTester{
   behavior of "5-Stage test" 
   it should "Go through" in {
    test(new PIPELINE){c =>
      //while (!c.io.exit.peek()){
      //  c.clock.step(1)
      //}
      c.clock.step(600)
    }
   }
}