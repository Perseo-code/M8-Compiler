#include "parser.h"

ParsedIns parse(ParsingError* error) {
    ParsedIns result;
    result.op.broken = true;
    result.ope1.type = NONE;
    result.ope2.type = NONE;
    // We look at the list the lexer has built by itself, and go ahead by compiling with the encoder (my fav part honestly)
    for (int i = 0; i < token_count; i++) {
        if (result.ope1.type != NONE && result.ope2.type != NONE && !(result.op.broken)) {
            break;
        }
        switch (list[i]->type) {
            case INSTRUCTION:
                OpName op;
                bool broken = true;
                for (int j = 0; j < INS_SET_SIZE; j++) {
                    if (STREQ(list[i]->literal, opname[j])) {
                        broken = false;
                        op = opname[j];
                        break;
                    }
                }
                if (broken) {
                    *error = UNKNOWN_INSTRUCTION;
                    return (ParsedIns){};
                } // No such instruction...
                if (result.op.broken) result.op = OPS[op.inst];
                else {*error = TOO_MANY_OPERANDS; return (ParsedIns){};}
                break;
            case REGISTER:
                uint16_t reg;
                bool broken = true;
                for (int j = 0; j < REND; j++) {
                    if (STREQ(list[i]->literal, regss[j])) {
                        reg = j; 
                        broken = false;
                        break;
                    }
                }
                if (broken) {
                    *error = UNKNOWN_REGISTER;
                    return (ParsedIns){};
                }
                if (result.ope1.type == NONE) result.ope1 = (Operand){REGISTER, reg};
                else if (result.ope2.type == NONE) result.ope2 = (Operand){REGISTER, reg};
                else {*error = TOO_MANY_OPERANDS; return (ParsedIns){};}
                break;
            case DIRECTIVE:
                uint16_t dir;
                bool broken = true;
                for (int j = 0; j < DIR_SIZE; j++) {
                    if (STREQ(list[i]->literal, directives[j])) {
                        dir = j;
                        broken = false;
                        break;
                    }
                }
                if (broken) {
                    *error = UNKNOWN_DIRECTIVE;
                    return (ParsedIns){};
                }
                if (result.ope1.type == NONE) result.ope1 = (Operand){DIRECTIVE, dir};
                else if (result.ope2.type == NONE) result.ope2 = (Operand){DIRECTIVE, dir};
                else {*error = TOO_MANY_OPERANDS; return (ParsedIns){};}
                break;
        }
    }

    return result;
}