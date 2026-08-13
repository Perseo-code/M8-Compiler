#ifndef PARSER
#define PARSER
#include "lexer.h"
#include "operations.h"
#include "registers.h"
typedef struct {
    TokenType type;
    uint8_t value;
} Operand;

typedef struct {
    Operation op;
    Operand ope1;
    Operand ope2;
} ParsedIns;

typedef enum {
    OKAY,
    UNKNOWN_INSTRUCTION,
    UNKNOWN_DIRECTIVE,
    UNKNOWN_REGISTER,
    SYNTAX_ERROR,
    INVALID_OPCODE,
    TOO_MANY_OPERANDS
} ParsingError;

ParsedIns parse(ParsingError*);
#endif