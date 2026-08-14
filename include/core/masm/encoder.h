#ifndef ENCODER_H
#define ENCODER_H
#include <stdint.h>
#include "parser.h"
#define MAX_INS_SIZE 16
typedef struct {
    uint8_t data[MAX_INS_SIZE];
    uint8_t size;
} Encoded;

Encoded encoder(ParsedIns);

#endif