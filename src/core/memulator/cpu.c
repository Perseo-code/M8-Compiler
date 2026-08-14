#include "cpu.h"




void execute(CPU* cpu) {
    while (cpu->pc < MEMORY_SIZE) {
        Operation op = OPS[cpu->memory[cpu->pc]];
        if (cpu->memory[cpu->pc] == op.code) {
            GivenCommands result;
            bool jmp = op.code == _JMP;
            result.operand1 = 0;
            result.operand2 = 0;
            if (op.size >= 2) result.operand1 = cpu->memory[cpu->pc + 1];
            if (op.size >= 3) result.operand2 = cpu->memory[cpu->pc + 2];
            

            op.ins(cpu, result);
            if (!jmp) cpu->pc += op.size;
        } else {
            cpu->pc++;
        }
    }
}