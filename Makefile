CC=gcc
CFLAGS=-g -Wall
EXE=proj4
HEADERS=types.h tree.h stack.h
CODE=tree.c stack.c proj4.c

OBJECTS = $(CODE:.c=.o)

proj3: $(OBJECTS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXE)

clean:
	rm -f *.o *.exe *.out