CC=gcc
RM=rm -fr
CFLAGS=-Wall  -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18
CFLAGS += -Wno-unused-result
LDFLAGS=
LDLIBS=
SOURCES=main.c matrix.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

debug: CFLAGS+=-Og -g
debug: all

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o $(EXECUTABLE)
