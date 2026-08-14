CC = gcc
CFLAGS = -Iinclude -Iinclude/core -Iinclude/core/common -Iinclude/core/masm -Iinclude/core/memulator -g

BUILD_DIR = build
BIN = $(BUILD_DIR)/masm
SOURCE = $(shell find . -name "*.c")
OBJECTS = $(SOURCE:%.c=$(BUILD_DIR)/%.o)

$(BIN): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(BIN)

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(BIN)