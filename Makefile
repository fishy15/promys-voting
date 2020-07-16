CC = g++
CFLAGS = -Wall -O2

fraction.o: fraction.h fraction.cpp
    $(CC) $(CFLAGS) -c fraction.cpp
