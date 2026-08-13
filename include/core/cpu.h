#ifndef CPU_H
#define CPU_H
// Unused file (yet)
#include "registers.h"
typedef struct {
    Registers regs;
    uint8_t pc; // Program Counter
    uint8_t memory[1024];
} CPU;
#endif