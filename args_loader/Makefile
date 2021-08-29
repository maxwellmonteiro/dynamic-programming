# _*_ Makefile _*_

CFLAGS = -pipe -Wall -O3
EXECUTABLES = test
OBJECTS = test.o args_loader.o
INCLUDES= ../vector

all: $(EXECUTABLES)

test: $(OBJECTS)
	$(CXX) $(CFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) -I$(INCLUDES) -c $<

%.cpp: %.hpp

clean:
	rm -f *.o $(EXECUTABLES)
