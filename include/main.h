#ifndef MAIN_IASM
#define MAIN_IASM
#include <stdlib.h>
#include "operations.h"
#include "registers.h"
inline void init(CPU* cpu) {
    cpu = malloc(sizeof(cpu));
}
#endif