#include "encoder.h"

Encoded encoder(ParsedIns ins) {
    Encoded result;
    
    result.data[0] = ins.op.code;
    result.size = 1;

    if (ins.ope1.type != NONE) {
        result.data[result.size++] = ins.ope1.value;
    }

    if (ins.ope2.type != NONE) {
        result.data[result.size++] = ins.ope2.value;
    }

    return result;
}