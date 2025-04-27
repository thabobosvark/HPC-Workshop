CC = gcc
CFLAGS = -Wall
OBJECTS = code.o
EXEC = app

all: $(EXEC)

$(EXEC): $(OBJECTS)
    $(CC) $(OBJECTS) -o $(EXEC)

code.o: code.c
    $(CC) $(CFLAGS) -c code.c

clean:
    rm -f $(OBJECTS) $(EXEC)

