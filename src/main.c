// IASM (Interpreted Assembler)
/*
A program made to compile assembly using a custom architecture called M8
*/
#include <string.h>
#include <stdio.h>
#include "main.h"



int main(int argc, char* argv[]) {
    CPU* cpu;
    init(cpu);
    FILE* filename = fopen(argv[1], "r");
    if (filename == NULL) {
        printf("Failed to open file %s", argv[1]);
        return 1;
    }

    fseek(filename, 0, SEEK_END);
    long filesize = ftell(filename);
    rewind(filename);
    char* buffer = malloc(filesize + 1);
    if (!buffer) {
        fclose(filename);
        return 2;
    }
    
    size_t read = fread(buffer, 1, filesize, filename);
    buffer[read] = '\0';
    fclose(filename);
    FILE* output = fopen(argv[2], "w");
    if (output == NULL) {
        printf("Failed to create output file\n");
        return 1;
    }

    fclose(output);
}