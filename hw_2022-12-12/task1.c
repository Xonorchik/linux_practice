#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
  srand(time(0));
  int N = atoi(argv[1]);
  int M = atoi(argv[2]);
  int K = atoi(argv[3]);
  int fd = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0666);
  if(fd == -1) {
    printf("Error opening file");
    exit(1);
  }
  write(fd, &N, sizeof(N));
  for(int i = 0; i < N; ++i) {
    int random = M + rand() % (K-M + 1);
    write(fd, &random, sizeof(random));
  }
  close(fd);
  return 0;
}
