OBJS = prog1.o prog2.o
C = gcc
DEBUG = -g
CFLAGS = -Wall -Werror -Wno-unused-result -c $(DEBUG)
LDFLAGS = -lm

run : $(OBJS)
	./prog2
prog1.o : prog1.c
	$(C) $(CFLAGS) prog1.c -o $@
prog2.o : prog2.c
	$(C) $(CFLAGS) prog2.c -o $@
prog1 : prog1.o
	$(C) prog1.o -o prog1
prog2 : prog2.o
	$(C) prog2.o -o prog2

clean :
	rm -f *.o *~ str
