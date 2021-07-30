# _*_ Makefile _*_

CFLAGS = -pipe -Wall -O3
EXECUTABLES = fibonacci_recursive fibonacci_dp
FIBONACCI_RECURSIVE_OBJECTS = fibonacci_recursive.o fibonacci.o
FIBONACCI_DP_OBJECTS = fibonacci_dp.o fibonacci.o

all: $(EXECUTABLES)

fibonacci_recursive: $(FIBONACCI_RECURSIVE_OBJECTS)
	gcc $(CFLAGS) $(FIBONACCI_RECURSIVE_OBJECTS) -o $@

fibonacci_dp: $(FIBONACCI_DP_OBJECTS)
	gcc $(CFLAGS) $(FIBONACCI_DP_OBJECTS) -o $@

%.o: %.c
	gcc $(CFLAGS) -c $<

%.c: %.h

clean:
	rm -f *.o $(EXECUTABLES)
