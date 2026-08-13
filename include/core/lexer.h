#ifndef LEXER
#define LEXER
#include "registers.h"
#include "includes.h"
#define MAX_DATA_SIZE 8
#define MAX_TOKEN_SIZE 16
#define DIR_SIZE 5
#define STREQ(a, b) (strcmp((a), (b)) == 0)
typedef enum TokenType {
    INSTRUCTION,
    REGISTER, // Registers (AR, BR, CR, RR, L7...)
    LABEL, // label: code...
    DIRECTIVE, // db, dw, equ, .bss, .data, .rodata...
    NUMBER, // A Number
    NEWLINE, // Can be ; or enter.
    TEOF, // End of file
    NONE,
    END
} TokenType;

typedef struct {
    TokenType type;
    char literal[MAX_TOKEN_SIZE];
} Token;

extern char* regss[];
extern char* directives[];

extern Token list[2048];
void lexer(const char*);
extern Token* current_token; // If needed in the parser or another file
extern uint32_t token_count;
#endif