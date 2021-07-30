# _*_ Makefile _*_

CFLAGS = -pipe -Wall -O3
EXECUTABLES = can_sum_recursive can_sum_dp
CAN_SUM_RECURSIVE_OBJECTS = can_sum_recursive.o can_sum.o
CAN_SUM_DP_OBJECTS = can_sum_dp.o can_sum.o

all: $(EXECUTABLES)

can_sum_recursive: $(CAN_SUM_RECURSIVE_OBJECTS)
	gcc $(CFLAGS) $(CAN_SUM_RECURSIVE_OBJECTS) -o $@

can_sum_dp: $(CAN_SUM_DP_OBJECTS)
	gcc $(CFLAGS) $(CAN_SUM_DP_OBJECTS) -o $@

%.o: %.c
	gcc $(CFLAGS) -c $<

%.c: %.h

clean:
	rm -f *.o $(EXECUTABLES)
