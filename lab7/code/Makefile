# COMP 211 standard Makefile.
#
# Spring 2019

# Required flags for compilation.
CFLAGS+=-std=c99 -Wall

qdriver: qdriver.c queue.c queue.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -o qdriver qdriver.c queue.c

clean :
	rm -f qdriver *.o


