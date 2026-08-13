#include "lexer.h"
#include "operations.h"
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_DATA_SIZE 8
#define MAX_TOKEN_SIZE 16

Token* current_token = list;
uint32_t token_count;
TokenType identify(const char* data) {
    for (int i = 0; i < INS_SET_SIZE; i++) {
        if (STREQ(data, opname[i].name)) {
            return INSTRUCTION;
        }
    }

    for (int i = 0; i < REND; i++) {
        if (STREQ(data, regss[i])) {
            return REGISTER;
        }
    }

    for (int i = 0; i < DIR_SIZE; i++) {
        if (STREQ(data, directives[i])) {
            return DIRECTIVE;
        }
    }

    char last_char = data[strlen(data) - 1];
    if (last_char == ';' || last_char == '\n') return NEWLINE;
    if (is_number(data)) return NUMBER;
    return NONE;
}

bool is_number(const char* data) {
    int len = strlen(data);
    if (len == 0) return false; // Empty
    int i = 0;
    bool hex = false;
    if (data[0] == '0' && (data[1] == 'x' && len >= 2)) {
        i = 2;
        hex = true;
    }
    for (; i < len; i++) {
        if (!((data[i] <= '9' && data[i] >= '0') || ((data[i] <= 'a' && data[i] >= 'f') && hex))) {
            return false; // Not a number / hexadecimal number
        }
    }
    return true;
}

void lexer(const char* code) {
    Token result;
    int i = 0;
    int j = 0;
    int ins = 0;
    char data[MAX_DATA_SIZE][MAX_TOKEN_SIZE];
    uint32_t len = strlen(code);
    bool building_token = false;
    while (i < len) { // Get everything in the array
        if (code[i] == ' ' || code[i] == ',' || code[i] == 9) {
            if (building_token) {
                data[ins][j] = '\0';
                ins++;
                j = 0;
                building_token = false;
            }
        } else {
            building_token = true;
            data[ins][j] = tolower(code[i]);
            j++;
        }
        i++;
    }
    if (building_token) {
        data[ins][j] = '\0';
        ins++;
    }
    // And here, we start generating the tokens depending on what the array has.
    token_count = ins + 1;
    ins = 0;
    for (i = 0; i < token_count; i++) {
        result.type = identify(data[i]);
        result.literal = data[i];
        *current_token = result;
        current_token++;
    }

}