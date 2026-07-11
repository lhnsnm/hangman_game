.PHONY: build run clean

CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17 -g

build:
	mkdir -p build
	$(CC) $(CFLAGS) -Iinclude src/*.c -o build/main

run: build
	./build/main

clean:
	rm -rf build