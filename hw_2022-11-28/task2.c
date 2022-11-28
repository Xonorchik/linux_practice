#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int Bites = 0;

void sighandler(int signum) {
  printf("Broken Pipe!\n%d\n", Bites);
  exit(signum);
}

int main(void) {
  int fd[2];
  signal(SIGPIPE, sighandler);
  if(pipe(fd) == -1) {
    perror(NULL);
    exit(2);
  }
    char *msg = "Hello, World!";
  if(fork() == 0) {
    close(fd[0]);
    while(1) {
      Bites += write(fd[1], msg, sizeof(msg));
    }
    close(fd[1]);
    exit(0);
  }
  if(fork() == 0) {
    close(fd[1]);
    read(fd[0], msg, 5);
    write(1, msg, 5);
    printf("\n");
    close(fd[0]);
    exit(0);
  }
  close(fd[0]);
  close(fd[1]);
  wait(NULL);
  wait(NULL);
  return 0;
}