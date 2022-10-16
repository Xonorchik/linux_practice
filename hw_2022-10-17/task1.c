#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  for(int i = 0;i<argc-1;++i) {
    if(fork() == 0) {
      execlp(argv[i+1],argv[i+1],NULL);
      return 0;
    }
    int status;
    wait(&status);
    if(WIFEXITED(status) && WEXITSTATUS(status) == 0) {
      break;
    }
  }
  wait(NULL);
  return 0;
}
