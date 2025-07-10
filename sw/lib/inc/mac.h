#pragma once
#include <stdint.h>

// OP 0110011
#define MAC_OPCODE 0x33
#define MAC_FUNCT3 0x0
#define MAC_FUNCT7 0x3
// R type for gnu assembler: opcode, func3, func7, rd, rs1, rs2
#define MAC(a, b, c)                                                           \
  asm volatile(".insn r %1, %2, %3, %0, %4, %5"                                \
               : "=r"(a)                                                       \
               : "i"(MAC_OPCODE), "i"(MAC_FUNCT3), "i"(MAC_FUNCT7), "r"(b),    \
                 "r"(c))
