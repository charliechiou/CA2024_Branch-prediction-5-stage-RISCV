package Pipeline
import chisel3._
import chisel3.util._

class BTB extends Module {
  val io = IO(new Bundle {
    val inst = Input(UInt(32.W))
    val PC = Input(UInt(32.W))
    val isBtype = Output(Bool())
    val target = Output(SInt(32.W))
  })

  // Compute immediate value
  val bImm = Cat(
    Fill(19, io.inst(31)),       // sign-extension from bit 31
    io.inst(31),                 // imm[12]
    io.inst(7),                  // imm[11]
    io.inst(30, 25),             // imm[10:5]
    io.inst(11, 8),              // imm[4:1]
    0.U(1.W)                     // imm[0] = 0
  )
  // Compute target
  io.target := Mux(io.inst(6, 0) === "b1100011".U, io.PC.asSInt + bImm.asSInt, io.PC.asSInt + 4.S)

  // Determine if instruction is B-type
  io.isBtype := io.inst(6, 0) === "b1100011".U
}
