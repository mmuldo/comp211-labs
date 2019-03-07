# COMP 211, Spring 2019, Wesleyan University
#

# Required flags for compilation.
CFLAGS+=-std=c99 -fdiagnostics-color=auto -Wall

driver : driver.c linsearch.c linsearch.h comp211.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -o driver driver.c linsearch.c

tests : tests.c linsearch.c linsearch.h comp211.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -o tests tests.c linsearch.c

clean :
	rm -f driver driver.o
	rm -f tests tests.o
	rm -f linsearch.o


