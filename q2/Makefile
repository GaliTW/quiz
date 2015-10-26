CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = iterative recursive
all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ main.c $@.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ main.c $@.c

clean:
	$(RM) $(EXEC) *.o perf.*
