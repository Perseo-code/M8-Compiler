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

extern Operation OPS[];

extern OpName opname[];

typedef enum Args {
    REG,
    NUM,
    NOTHING
} Args;


typedef struct {
    Args arg1;
    Args arg2;
} Expects;

extern Expects ins_expect[];
#endif