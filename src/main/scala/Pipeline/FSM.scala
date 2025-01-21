package Pipeline
import chisel3._
import chisel3.util._
import Branch_predict_state._

object Branch_predict_state{
    val STRONG_TAKEN = 0.U(2.W)
    val WEAK_TAKEN = 1.U(2.W)
    val STRONG_NOT_TAKEN = 2.U(2.W)
    val WEAK_NOT_TAKEN = 3.U(2.W)

    def stateToString(state: UInt): String = {
        state.litValue.toInt match {
        case 0 => "STRONG_TAKEN"
        case 1 => "WEAK_TAKEN"
        case 2 => "STRONG_NOT_TAKEN"
        case 3 => "WEAK_NOT_TAKEN"
        case _ => "UNKNOWN"
        }
    }
}

class branch_predict extends Module{
    val io = IO(new Bundle{
        val taken = Input(Bool())
        val branch_predict = Output(Bool())
    })

    val current_state = RegInit(STRONG_NOT_TAKEN)
    val next_state = Wire(UInt(2.W))

    next_state := current_state
    when(current_state === STRONG_TAKEN){
        next_state := Mux(io.taken, STRONG_TAKEN, WEAK_TAKEN)
    }.elsewhen(current_state === WEAK_TAKEN){
        next_state := Mux(io.taken, STRONG_TAKEN, WEAK_NOT_TAKEN)
    }.elsewhen(current_state === STRONG_NOT_TAKEN){
        next_state := Mux(io.taken, WEAK_NOT_TAKEN, STRONG_NOT_TAKEN)
    }.elsewhen(current_state === WEAK_NOT_TAKEN){
        next_state := Mux(io.taken, WEAK_TAKEN, STRONG_NOT_TAKEN)
    }.otherwise{
        next_state := current_state
    }
    current_state := next_state

    printf(p"taken: ${io.taken}, current_state: ${current_state}, next_state: ${next_state}, predict: ${(next_state === STRONG_TAKEN) || (next_state === WEAK_TAKEN)}\n")
    io.branch_predict := (next_state === STRONG_TAKEN) || (next_state === WEAK_TAKEN)
}
