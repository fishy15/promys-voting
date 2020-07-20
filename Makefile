CC = g++
CFLAGS = -Wall -O2 -std=c++17

all: fraction.o banzhaf.o

fraction.o: fraction.h fraction.cpp
	$(CC) $(CFLAGS) -c fraction.cpp

banzhaf.o: banzhaf.h banzhaf.cpp
	$(CC) $(CFLAGS) -c banzhaf.cpp

# tests
tests: tests/banzhaf_test.out

tests/banzhaf_test.out: fraction.o banzhaf.o tests/banzhaf_test.o
	$(CC) $(CFLAGS) fraction.o banzhaf.o tests/banzhaf_test.o -o tests/banzhaf_test.out

tests/banzhaf_test.o: tests/banzhaf_test.cpp
	$(CC) $(CFLAGS) -c tests/banzhaf_test.cpp -o tests/banzhaf_test.o

# clean
clean:
	find . -type f -name '*.o' -delete
	find . -type f -name '*.out' -delete
