package Pipeline

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import Branch_predict_state._

class BranchPredictTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "branch_predict" 
  it should "correctly predict branch behavior" in {
    test(new branch_predict) { c =>
      val testCases = Seq(
        // (initial state, taken, expected state, expected prediction)
        (true.B, false.B),
       (true.B, true.B),
        (false.B, false.B),
        (true.B, true.B),
        (true.B, true.B),
        (true.B, true.B),
        (false.B, true.B)
      )

      for ((taken, expectedPrediction) <- testCases) {
        // 初始化輸入狀態
        c.io.taken.poke(taken)

        // 執行模組
        c.io.branch_predict.expect(expectedPrediction)
        c.clock.step()

      }
    }
  }
}
