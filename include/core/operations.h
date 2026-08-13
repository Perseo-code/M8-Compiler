#ifndef INSTRUCTIONS
#define INSTRUCTIONS
#define INS_SET_SIZE 256
#define CALCSIZE(array) (sizeof(array) / sizeof((array)[0]))
#define GETBITS(byte, bits, mask) ((byte >> bits) & mask) // If we need
#define CREATEOP(fn, byte, size) [byte] = {false, byte, size, fn} 

// Each instruction value
#define _NOP 0x00
#define _MOV 0x01
#define _ADD 0x02
#define _SUB 0x03
#define _JMP 0x04
#define _SHOWREG 0xAA

// The rest of the file. (structures, functions, instructions...)
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "cpu.h"
typedef void (*Instruction)(CPU* cpu, uint8_t operand);
typedef struct {
    bool empty;
    uint8_t code;
    uint8_t size;
    Instruction ins;
} Operation;

typedef struct {
    const char* name;
    uint8_t inst;
} OpName;
//uint8_t GetOp(CPU* cpu); 
inline void nop(CPU* cpu, uint8_t operand) {}
inline void mov(CPU* cpu, uint8_t reg) {
    uint8_t value = cpu->memory[cpu->pc++];

    cpu->regs.r[reg] = value;
}

inline void add(CPU* cpu, uint8_t reg) {
    uint8_t destination = reg >> 4;
    uint8_t source = reg & 0x0F;
    cpu->regs.r[destination] += cpu->regs.r[source];
}

inline void sub(CPU* cpu, uint8_t reg) {
    uint8_t reg1 = reg >> 4;
    uint8_t reg2 = reg & 0x0F;
    cpu->regs.r[AR] = cpu->regs.r[reg1] - cpu->regs.r[reg2];
}

inline void jmp(CPU* cpu, uint8_t address) {
    cpu->pc = address;
}

inline void showreg(CPU* cpu, uint8_t reg) {
    uint8_t type = reg >> 4;
}

Operation OPS[INS_SET_SIZE] = {
    CREATEOP(nop, _NOP, 1),
    CREATEOP(mov, _MOV, 3),
    CREATEOP(add, _ADD, 2),
    CREATEOP(sub, _SUB, 2),
    CREATEOP(jmp, _JMP, 2),
    CREATEOP(showreg, _SHOWREG, 1)
};

OpName opname[INS_SET_SIZE] = {
    {"nop", _NOP},
    {"mov", _MOV},
    {"add", _ADD},
    {"sub", _SUB},
    {"jmp", _JMP},
    {"sreg", _SHOWREG}
};

typedef enum Args {
    REG,
    NUM,
    NOTHING
};


typedef struct {
    uint8_t arg1;
    uint8_t arg2;
} Expects;

Expects ins_expect[INS_SET_SIZE] = {
    [_NOP] = {NOTHING, NOTHING},
    [_MOV] = {REG, NUM},
    [_ADD] = {REG, REG},
    [_SUB] = {REG, REG},
    [_JMP] = {NUM, NOTHING},
    [_SHOWREG] = {REG, NOTHING}
};
#endif