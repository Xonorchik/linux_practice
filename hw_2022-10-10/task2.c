#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    if(fork() == 0) {
      execlp(argv[1],argv[1],argv[2],argv[3],NULL);
      return 0;
    wait(NULL);
  }
  printf("Finish\n");
  return 0;
}