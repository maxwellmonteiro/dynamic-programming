# _*_ Makefile _*_

CFLAGS = -pipe -Wall -O3
EXECUTABLES = can_sum_recursive can_sum_dp
OBJECTS = can_sum.o ../args_loader/args_loader.o
CAN_SUM_RECURSIVE_OBJECTS = can_sum_recursive.o $(OBJECTS)
CAN_SUM_DP_OBJECTS = can_sum_dp.o $(OBJECTS)
INCLUDES = -I../vector -I../args_loader

all: $(EXECUTABLES)

can_sum_recursive: $(CAN_SUM_RECURSIVE_OBJECTS)
	gcc $(CFLAGS) $(CAN_SUM_RECURSIVE_OBJECTS) -o $@

can_sum_dp: $(CAN_SUM_DP_OBJECTS)
	gcc $(CFLAGS) $(CAN_SUM_DP_OBJECTS) -o $@

%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -c $<

%.c: %.h

clean:
	rm -f *.o $(EXECUTABLES)
