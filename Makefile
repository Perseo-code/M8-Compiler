CC = gcc
CFLAGS = -Iinclude -Iinclude/core
SOURCE = $(shell find . -name "*.c")
BUILD_DIR = build 
BIN = $(SOURCE:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


SRCODE: $(BIN)
	mkdir -p $(BUILD_DIR)/core
	$(CC) $(OBJS) -o M8 