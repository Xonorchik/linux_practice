#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
  int pid = getpid();
  printf("%i\n", pid);
  while(1) {
    sleep(1);
  }
  return 0;
}