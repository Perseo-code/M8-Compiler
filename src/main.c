#include "main.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Use: masm <-e (emulate)> <file_to_emulate (or file to compile)> <output_file (if compiling)>\n");
        return 1;
    }
    
    FILE* filename;
    bool emulate = strcmp(argv[1], "-e") == 0;
    if (emulate) {
        filename = fopen(argv[2], "rb");
    } else {
        filename = fopen(argv[1], "r");
    }
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

    if (emulate) {
        emulator((const uint8_t*)buffer, read);
    } else {
        FILE* output = fopen(argv[2], "wb");
        if (output == NULL) {
            printf("Failed to create output file\n");
            return 1;
        }
        int returns = compiler(buffer, output);
        if (returns != OKAY) {
            printf("Error\n");
        }
    }

    return 0;
}