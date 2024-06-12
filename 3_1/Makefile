CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11
TARGET = sqrt_main

.PHONY: all clean run

all: $(TARGET)
	@./$(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) $< -o $@

test: test.c
	$(CC) $(CFLAGS) $< -o $@
	./test
	rm -rf test

clean:
	rm -f $(TARGET)
