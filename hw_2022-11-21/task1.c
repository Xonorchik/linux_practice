#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
  int fd[2];
  int fd2[2];
  if (pipe(fd) == -1 && pipe(fd2) == -1) {
		perror(NULL);
		exit(1);
	}
  if(fork() == 0) { //p1
    close(fd[0]);
    close(fd2[1]);
    close(fd2[0]);
    dup2(fd[1], 1);
    close(fd[1]);
    execlp(argv[1], argv[1], NULL);
    exit(0);
  }
  if(fork() == 0) { //p2
    close(fd[1]);
    dup2(fd[0], 0);
    close(fd[0]);
    dup2(fd2[1], 1);
    close(fd2[1]);
    close(fd2[0]);
    execlp(argv[2], argv[2], NULL);
    exit(0);
  }
  char* args[argc-3];
  for(int i = 0; i < argc-3; ++i) {
    args[i] = argv[i+3];
  }
  args[argc-3] = NULL;
  if(fork() == 0) { //p3
    close(fd[1]);
    dup2(fd[0], 0);
    close(fd[0]);
    dup2(fd2[1], 1);
    close(fd2[1]);
    close(fd2[0]);
    execvp(argv[3], args);
    exit(0);
  }
  wait(NULL);
  close(fd[0]);
  close(fd[1]);
  close(fd2[0]);
  close(fd2[1]);
  return 0;
}
