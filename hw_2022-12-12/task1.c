#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  clock_t t;
  t = clock();
  srand(time(0));
  int N;
  int M;
  int K;
  sscanf(argv[1], "%i", &N);
  sscanf(argv[2], "%i", &M);
  sscanf(argv[3], "%i", &K);
  int fd = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0666);
  if (fd == -1) {
    printf("Error opening file");
    exit(1);
  }
  write(fd, &N, sizeof(N));
  for (int i = 0; i < N; ++i) {
    int random = M + rand() % (K - M + 1);
    write(fd, &random, sizeof(random));
  }
  close(fd);
  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
  printf("task1 took %f seconds to execute \n", time_taken);
  return 0;
}
