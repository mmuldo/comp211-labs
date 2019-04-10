# COMP 211 standard Makefile.
#
# Spring 2019

# Required flags for compilation.
CFLAGS+=-std=c99 -Wall

driver : driver.c list.c list.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -o driver driver.c list.c

clean :
	rm -f driver driver.o
	rm -f list.o


