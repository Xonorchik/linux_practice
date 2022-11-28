#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

void sighandler(int);

int M;

int main(int argc, char *argv[]) {
	int N;
	N = atoi(argv[1]);
	M = N;
	if(N <= 0) {
		char* msg = "Incorrect N\n";
		write(2, msg, strlen(msg));
		exit(1);
	}
	while(1) {
		printf("%d signals remaining\n", M);
		signal(SIGINT, sighandler);
		sleep(2);
		if(M <= 0)
			break;
	}
	return 0;
}

void sighandler(int signum) {
	printf("\n");
	--M;
	exit(signum);
}
