package Pipeline
import chisel3._
import chisel3.util._

class Branch extends Module {
  val io = IO(new Bundle {
    val fnct3 = Input(UInt(3.W))
    val branch = Input(Bool())
    val arg_x = Input(SInt(32.W))
    val arg_y = Input(SInt(32.W))
    val pred = Input(Bool())   // predicted result of whether branch is taken or not
    val actual = Output(Bool()) // actual result of whether branch is taken or not
    val flush = Output(Bool())
  })
  io.actual := false.B
  io.flush := false.B
  when(io.branch) {
    io.actual := MuxLookup(io.fnct3, false.B, Seq(
      0.U -> (io.arg_x === io.arg_y),              // beq
      1.U -> (io.arg_x =/= io.arg_y),              // bne
      4.U -> (io.arg_x < io.arg_y),                // blt
      5.U -> (io.arg_x >= io.arg_y),               // bge
      6.U -> (io.arg_x.asUInt < io.arg_y.asUInt),  // bltu
      7.U -> (io.arg_x.asUInt >= io.arg_y.asUInt)  // bgeu
    ))
  }
  io.flush := io.pred ^ io.actual
}
