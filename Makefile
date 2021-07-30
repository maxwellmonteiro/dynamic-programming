# _*_ Makefile _*_

CFLAGS = -pipe -Wall -O3

SUB_SYSTEMS = ss_grid_traveler ss_fibonacci ss_can_sum

all: $(SUB_SYSTEMS)

ss_grid_traveler:
	$(MAKE) -C grid_traveler

ss_fibonacci:
	$(MAKE) -C fibonacci

ss_can_sum: 
	$(MAKE) -C can_sum

clean:
	$(MAKE) clean -C can_sum 
	$(MAKE) clean -C fibonacci 
	$(MAKE) clean -C grid_traveler


