CC = gcc
CFLAGS = -Wall -Wextra -g -fsanitize=address

P ?= none

SRC_DIR = src/$(P)
TEST_FILE = tests/test_$(P).c
BUILD_DIR = build
TARGET = $(BUILD_DIR)/runner

run: clean setup compile execute

setup:
	@mkdir -p $(BUILD_DIR)

compile: 
	@if [ "$(P)" = "none" ]; then \
		echo "Error: Please specify a problem. Usage: make run P=FolderName"; \
		exit 1; \
	fi
	@if [ ! -d "$(SRC_DIR)" ]; then \
		echo "Error: Directory $(SRC_DIR) does not exist."; \
		exit 1; \
	fi
	$(CC) $(CFLAGS) -I $(SRC_DIR) -o $(TARGET) $(SRC_DIR)/solution.c $(TEST_FILE)

execute:
	@echo "--- Running Tests for $(P) ---"
	@./$(TARGET)

clean:
	@rm -rf $(BUILD_DIR)

.PHONY: run setup compile execute clean
