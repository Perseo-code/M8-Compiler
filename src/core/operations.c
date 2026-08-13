#include "operations.h"

/*Operation GetOP(CPU* cpu) {
    uint8_t opcode = cpu->memory[cpu->pc++];
    for (uint32_t i = 0; i < INS_SET_SIZE; i++) {
        if (OPS[i].code == opcode) {
            return OPS[i]; // Find one and return it
        }
    }
    return (Operation){true, 0, 0, NULL}; // It didn't work
} //Comes with the emulator */