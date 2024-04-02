CC=gcc
CFLAGS=-fPIC
LDFLAGS=-shared
LIBS=-ldl
RM=rm -rf

all: libplus.so libminus.so libdivide.so libmultiply.so libisValid.so main

%.o : %.c
	$(CC) $^ -c

libplus.so: plus.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

libminus.so: minus.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

libdivide.so: divide.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

libmultiply.so: multiply.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

libisValid.so: isValid.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

main: main.o
	$(CC) -o $@ $^ -lisValid $(LIBS) -L. -Wl,-rpath=.

.PHONY: clean

clean:
	$(RM) libplus.so libminus.so libdivide.so libmultiply.so libisValid.so main plus.o minus.o divide.o multiply.o isValid.o main.o
