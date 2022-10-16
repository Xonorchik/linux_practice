OBJS = main.o str.o
C = gcc
DEBUG = -g
CFLAGS = -Wall -Werror -c $(DEBUG)
LDFLAGS = -lm

run : $(OBJS)
	$(C) $(LDFLAGS) $(OBJS) -o task2
	./task2 arg arg2 1234567890
main.o : main.c str.h
	$(C) $(CFLAGS) main.c -o $@
str.o : str.c str.h
	$(C) $(CFLAGS) str.c -o $@
clean :
	rm -f *.o *~ str
