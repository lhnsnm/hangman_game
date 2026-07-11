.PHONY: build run clean

CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17

build:
	mkdir -p build
	${CC} -g ${CFLAGS} src/*.c -o build/main

run: build
	./build/main

clean:
	rm -rf build