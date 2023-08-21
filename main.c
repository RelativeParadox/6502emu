#include <stdio.h>

#define MAX_MEM 65536 //1024 * 64 Bytes

typedef unsigned char Byte;
typedef unsigned short Word;
typedef unsigned int u32;

//Consts//
const Byte INS_LDA_IM = 0xA9; //Load A (Immediate Mode)


//Hardware Data//
typedef struct Mem{
    Byte Data[MAX_MEM];
} Mem;

typedef struct CPU {
    Word PC; //Program Counter
    Word SP; //Stack Pointer

    Byte A; //Accumulator Reg
    Byte X; //Index Reg "X"
    Byte Y; //Index Reg "Y"

    //Processor Status Flags
    Byte C : 1;
    Byte Z : 1;
    Byte I : 1;
    Byte D : 1;
    Byte B : 1;
    Byte V : 1;
    Byte N : 1;

} CPU;

//CPU Functions//
void reset(CPU cpu, Mem mem){
    //Init PC and SP to starting addresses
    cpu.PC = 0xFFFC;
    cpu.SP = 0x0100;

    //Zero All Regs
    cpu.A = 0;
    cpu.X = 0;
    cpu.Y = 0;

    //Clear all flags
    cpu.C = 0;
    cpu.Z = 0;
    cpu.I = 0;
    cpu.D = 0;
    cpu.B = 0;
    cpu.V = 0;
    cpu.N = 0;

    //Clear Memory
    for(u32 i = 0; i < MAX_MEM; i++){
        mem.Data[i] = 0;
    }

    printf("CPU and MEM Init Success!\n");

}

int execute(CPU cpu, Mem mem, u32 cycles){
    for(u32 i = cycles; i > 0; i--){
        Byte instruction = mem.Data[cpu.PC]; //Fetch next instruction
        cpu.PC++; //Increment Upon Fetch
        printf("Next Instruction: %x \n", instruction);
    }
    return 0;
}

//Main//
int main() {
    printf("Hello World, I am a 6502!\n");
    Mem mem;
    CPU cpu;
    reset(cpu, mem); //This inits cpu and mem
    execute(cpu, mem, 2);


    return 0;
}

