OBJS = task1 task2
C = gcc
DEBUG = -g
CFLAGS = -Wall -Werror -Wno-unused-result -c $(DEBUG)
LDFLAGS = -lm


run : $(OBJS)
	./task1 100000000 -214748369 214748369 file
	./task2 100 4 file
task1.o : task1.c
	$(C) $(CFLAGS) task1.c -o $@
task2.o : task2.c
	$(C) $(CFLAGS) task2.c -o $@
task1 : task1.o
	$(C) $(LDFLAGS) task1.o -o task1
task2 : task2.o
	$(C) $(LDFLAGS) task2.o -o task2
clean :
	rm -f *.o task1 task2
