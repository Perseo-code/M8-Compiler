#include "operations.h"

void nop(CPU* cpu, uint8_t operand) {}
void mov(CPU* cpu, uint8_t reg) {
    uint8_t value = cpu->memory[cpu->pc++];

    cpu->regs.r[reg] = value;
}

void add(CPU* cpu, uint8_t reg) {
    uint8_t destination = reg >> 4;
    uint8_t source = reg & 0x0F;
    cpu->regs.r[destination] += cpu->regs.r[source];
}

void sub(CPU* cpu, uint8_t reg) {
    uint8_t reg1 = reg >> 4;
    uint8_t reg2 = reg & 0x0F;
    cpu->regs.r[AR] = cpu->regs.r[reg1] - cpu->regs.r[reg2];
}

void jmp(CPU* cpu, uint8_t address) {
    cpu->pc = address;
}

void showreg(CPU* cpu, uint8_t reg) {
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

Expects ins_expect[INS_SET_SIZE] = {
    [_NOP] = {NOTHING, NOTHING},
    [_MOV] = {REG, NUM},
    [_ADD] = {REG, REG},
    [_SUB] = {REG, REG},
    [_JMP] = {NUM, NOTHING},
    [_SHOWREG] = {REG, NOTHING}
};