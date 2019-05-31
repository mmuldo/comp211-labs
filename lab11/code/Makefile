# COMP 211 standard Makefile.
#
# Spring 2019

# Required flags for compilation.
CFLAGS+=-std=c99 -Wall

driver : driver.c set.c hash.c set.h hash.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -o driver driver.c set.c hash.c

clean :
	rm -f driver driver.o
	rm -f set.o


