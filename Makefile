# -*- MakeFile -*-

CC = gcc
RM = rm


all: bin/dikkilona

# Linking all objectfiles to executable
bin/dikkilona: build/main.o build/setup_teardown.o build/event_handler.o
	$(CC) $^ -o $@ -lSDL2

# Object file for main.c
build/main.o: src/main.c libs/include/dikkilona.h
	$(CC) -c $< -o $@

# Object file for setup_teardown.c
build/setup_teardown.o: libs/setup_teardown.c libs/include/dikkilona.h
	$(CC) -c $< -o $@

# Object file for event_handler.c
build/event_handler.o: libs/event_handler.c libs/include/dikkilona.h
	$(CC) -c $< -o $@

# Cleaning the build dir
clean:
	$(RM) -f build/*.o
	$(RM) -f bin/*
