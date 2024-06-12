CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11
TARGET = sqrt_main

.PHONY: all clean run

all: $(TARGET)
	@./$(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) $< -o $@

test: fls clz
	./fls
	rm -f clz fls

clz: clz.c
	$(CC) $(CFLAGS) $< -o $@

fls: fls.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGET) clz fls
