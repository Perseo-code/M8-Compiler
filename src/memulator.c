#include <stdio.h>
#include <string.h>
#include "main.h"

void emulator(const uint8_t* buffer, size_t size) {
    CPU* cpu = calloc(1, sizeof(CPU));
    if (size >= MEMORY_SIZE) {
        return;
    }
    for (size_t i = 0; i < size; i++) {
        cpu->memory[i] = buffer[i];
    }
    execute(cpu);
}

