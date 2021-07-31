# _*_ Makefile _*_

CFLAGS = -pipe -Wall -O3
EXECUTABLES = test
OBJECTS = test.o args_loader.o
INCLUDES= ../vector

all: $(EXECUTABLES)

test: $(OBJECTS)
	gcc $(CFLAGS) $(OBJECTS) -o $@

%.o: %.c
	gcc $(CFLAGS) -I$(INCLUDES) -c $<

%.c: %.h

clean:
	rm -f *.o $(EXECUTABLES)
