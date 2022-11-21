#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
  int pid;
  if((pid = fork()) == 0) {
    execl("prog1", "prog1", NULL);    
    exit(0);
  }
  int n;
  scanf("%d", &n);
  kill(pid, n);
  int status;
  wait(&status);
  if(WIFSIGNALED(status)) {
    printf("Signaled: %d\n", WTERMSIG(status));
  }
  if(WIFEXITED(status)) {
    printf("Exited: %d\n", WEXITSTATUS(status));
  }
  return 0;
}
