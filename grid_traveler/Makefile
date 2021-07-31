# _*_ Makefile _*_

CFLAGS = -pipe -Wall -O3
EXECUTABLES = grid_traveler_recursive
OBJECTS = grid_traveler.o ../args_loader/args_loader.o
GRID_TRAVELER_RECURSIVE_OBJECTS = grid_traveler_recursive.o $(OBJECTS)
INCLUDES = -I../vector -I../args_loader

all: $(EXECUTABLES)

grid_traveler_recursive: $(GRID_TRAVELER_RECURSIVE_OBJECTS)
	gcc $(CFLAGS) $(GRID_TRAVELER_RECURSIVE_OBJECTS) -o $@

%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -c $<

%.c: %.h

clean:
	rm -f *.o $(EXECUTABLES)
