#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
  char *args[] = {argv[1]};
  if(fork() == 0) {
    for(int i = 0;i<argc;++i) {
      args[i+1] = argv[i+2];
    }
    execvp(argv[1],args);
    return 0;
  }
  wait(NULL);
  printf("Finish\n");
  return 0;
}
