# -*- MakeFile -*-

CC = gcc
RM = rm

# Linking all objectfiles to executable
main: build/main.o build/setup_teardown.o
	$(CC) $^ -o $@ -lSDL2

# Object file for main.c
build/main.o: main.c libs/include/dikkilona.h
	$(CC) -c $< -o $@

# Object file for setup_teardown.c
build/setup_teardown.o: libs/setup_teardown.c libs/include/dikkilona.h
	$(CC) -c $< -o $@
