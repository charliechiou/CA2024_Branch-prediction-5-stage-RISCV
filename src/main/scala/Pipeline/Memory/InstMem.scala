package Pipeline
import chisel3._
import chisel3.util._
import chisel3.util.experimental.loadMemoryFromFile
import scala.io.Source

class InstMem(initFile: String) extends Module {
  val io = IO(new Bundle {
    val addr        =   Input(UInt(32.W))       // Address input to fetch instruction
    val data        =   Output(UInt(32.W))      // Output instruction
  })
  val imem = Mem(16384, UInt(8.W))
  loadMemoryFromFile(imem, initFile)
  io.data := Cat(
    imem(io.addr+3.U(32.W)),
    imem(io.addr+2.U(32.W)),
    imem(io.addr+1.U(32.W)),
    imem(io.addr)
   )
  // io.data := imem(io.addr/4.U)
  // printf(p"inst : 0x${Hexadecimal(io.data)}\n")
}
