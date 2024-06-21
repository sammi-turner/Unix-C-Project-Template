# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Iinclude -Wall -Wextra -std=c11

# Linker flags
LDFLAGS = -liconv

# Target executable name
TARGET = main

# Directories
SRC_DIR = src
BIN_DIR = obj
INCLUDE_DIR = include

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRCS))

# Rule for building the target
$(TARGET): $(OBJS)
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -lm -o $@

# Rule for generating object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(BIN_DIR)/*.o $(TARGET)