#ifndef PARSER
#define PARSER
#include "lexer.h"
#include "operations.h"
#include "registers.h"

typedef struct {
    TokenType type;
    uint8_t value;
} Operand;

enum ParseType {
    NON,
    DIRECT,
    INSTRUCT
};
typedef struct {
    Operation op;
    Operand ope1;
    Operand ope2;
    uint8_t ptype;
    uint8_t directive;
} ParsedIns;

typedef enum ParsingError {
    OKAY,
    UNKNOWN_INSTRUCTION,
    UNKNOWN_DIRECTIVE,
    UNKNOWN_REGISTER,
    SYNTAX_ERROR,
    INVALID_OPCODE,
    INVALID_ARGUMENT,
    INVALID_NUMBER,
    MISSING_INSTRUCTION,
    MISSING_ARGUMENT,
    MISSING_LINE,
    OUT_OF_BOUNDS,
    TOO_MANY_OPERANDS
} ParsingError;

ParsedIns parse(ParsingError*);

extern uint64_t parser_position;
#endif