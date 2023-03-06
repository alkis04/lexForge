# makefile that builds the lexcf.c 
.SILENT: 
CC=gcc
#VALFLAGS=--leak-check=full --show-leak-kinds=all --track-origins=yes -s
# FORVAL=-c -Wall -Wextra -g3
CFLAGS=-c -O2 $(FORVAL)
PROGRAMPARAMS=
PNAME=lexcf
SOURCES= lexf.c
OBJECTS= $(SOURCES:.c=.o)
all: program
program: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PNAME)
.c.o:
	$(CC) $(CFLAGS) $<
run: program
	./$(PNAME) $(PROGRAMPARAMS)
val: $(OBJECTS)
	gcc -g3 -Wall -Werror -Wextra -o $(PNAME) $(OBJECTS)
	valgrind $(VALFLAGS) ./$(PNAME) $(PROGRAMPARAMS)
clean:
	rm -f *.o
	rm -f $(PNAME)