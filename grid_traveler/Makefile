# _*_ Makefile _*_

CFLAGS = -pipe -Wall -O3
EXECUTABLES = grid_traveler_recursive
GRID_TRAVELER_RECURSIVE_OBJECTS = grid_traveler_recursive.o grid_traveler.o

all: $(EXECUTABLES)

grid_traveler_recursive: $(GRID_TRAVELER_RECURSIVE_OBJECTS)
	gcc $(CFLAGS) $(GRID_TRAVELER_RECURSIVE_OBJECTS) -o $@

%.o: %.c
	gcc $(CFLAGS) -c $<

%.c: %.h

clean:
	rm -f *.o $(EXECUTABLES)
