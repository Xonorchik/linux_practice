OBJS = prog1.o prog2.o
C = gcc
DEBUG = -g
CFLAGS = -Wall -Werror -Wno-unused-result -c $(DEBUG)
LDFLAGS = -lm

run : $(OBJS)
	$(C) $(LDFLAGS) $(OBJS) -o task2
prog1.o : prog1.c
	$(C) $(CFLAGS) prog1.c -o $@
prog2.o : prog2.c
	$(C) $(CFLAGS) prog2.c -o $@
clean :
	rm -f *.o *~ str
