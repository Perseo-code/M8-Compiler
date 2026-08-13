#ifndef LEXER
#define LEXER
#include "registers.h"
#define DIR_SIZE 5
#define STREQ(a, b) (strcmp((a), (b)) == 0)
typedef enum {
    INSTRUCTION,
    REGISTER, // Registers (AR, BR, CR, RR, L7...)
    LABEL, // label: code...
    DIRECTIVE, // db, dw, equ, .bss, .data, .rodata...
    NUMBER, // A Number
    NEWLINE, // Can be ; or enter.
    EOF, // End of file
    NONE,
    END
} TokenType;

typedef struct {
    TokenType type;
    char* literal;
} Token;

char* regss[REND] = {
    "ar",
    "br",
    "cr",
    "rr",
    "l1",
    "l2",
    "l3",
    "l4",
    "l5",
    "l6",
    "l7"
};

char* directives[DIR_SIZE] = {
    "db", "equ", ".bss",
    ".data", ".rodata"
}; 

Token* list[2048];
Token* lexer(const char*);
extern Token* current_token; // If needed in the parser or another file
extern uint32_t token_count;
#endif