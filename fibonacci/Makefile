# _*_ Makefile _*_

CFLAGS = -pipe -Wall -O3
EXECUTABLES = fibonacci_recursive fibonacci_dp
OBJECTS = fibonacci.o ../args_loader/args_loader.o
FIBONACCI_RECURSIVE_OBJECTS = fibonacci_recursive.o $(OBJECTS)
FIBONACCI_DP_OBJECTS = fibonacci_dp.o $(OBJECTS)
INCLUDES = -I../vector -I../args_loader

all: $(EXECUTABLES)

fibonacci_recursive: $(FIBONACCI_RECURSIVE_OBJECTS)
	gcc $(CFLAGS) $(FIBONACCI_RECURSIVE_OBJECTS) -o $@

fibonacci_dp: $(FIBONACCI_DP_OBJECTS)
	gcc $(CFLAGS) $(FIBONACCI_DP_OBJECTS) -o $@

%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -c $<

%.c: %.h

clean:
	rm -f *.o $(EXECUTABLES)
