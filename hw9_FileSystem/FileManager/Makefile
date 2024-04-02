CC=gcc
LIBS=-lncurses
RM=rm -rf

main: main.c
	$(CC) $^ -o $@ funcs.c $(LIBS) 

.PHONY: clean
clean:
	$(RM) main
