#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct {
  int *arr;
  long long price;
  long long index; // index of the day with maximum value
  long long size;  // size of array
  long long start_pos;
} pthrData;

void *threadFunc(void *data) {
  int max = 0;
  int index = 0;
  pthrData *Data = (pthrData *)data;
  for (int i = Data->start_pos; i < Data->size; ++i) {
    Data->price += Data->arr[i];
    if (abs(max) <= abs(Data->arr[i])) {
      max = Data->arr[i];
      index = i;
    }
  }
  Data->index = index;
  data = Data;
  return NULL;
}

int main(int argc, char *argv[]) {
  clock_t t;
  t = clock();
  int S;
  int T;
  sscanf(argv[1], "%i", &S);
  sscanf(argv[2], "%i", &T);
  int fd = open(argv[3], O_RDONLY);
  if (fd == -1) {
    perror(argv[3]);
    exit(2);
  }
  int N;
  int x;
  int max = 0;
  int index_res = 0;
  x = read(fd, &N, sizeof(N));
  int *arr = (int *)malloc(N * sizeof(int));
  for (int i = 0; i < N; ++i) {
    x = read(fd, &arr[i], sizeof(arr[i]));
    // printf("arr[i] : %d\n", arr[i]);
  }
  pthread_t *thr = (pthread_t *)malloc(T * sizeof(pthread_t));
  pthrData *thrData = (pthrData *)malloc(T * sizeof(pthrData));
  for (int i = 0; i < T; ++i) {
    x = N / T * i;
    thrData[i].start_pos = x;
    thrData[i].arr = arr;
    thrData[i].price = 0;
    if (T == 1) {
      thrData[i].size = N;
      break;
    }
    if (N % T == 0) {
      x = N / T * (i + 1);
      thrData[i].size = x;
    } else if (N % T != 0 && i != T - 1) {
      x = N / T * (i + 1);
      thrData[i].size = x;
    } else {
      thrData[i].size = N;
    }
  }
  for (int i = 0; i < T; ++i) {
    pthread_create(&thr[i], NULL, threadFunc, (void *)&thrData[i]);
  }
  for (int i = 0; i < T; ++i) {
    pthread_join(thr[i], NULL);
    S += thrData[i].price;
    if (abs(max) <= abs(arr[thrData[i].index])) {
      max = arr[thrData[i].index];
      index_res = thrData[i].index;
    }
  }
  printf("Price : %d\n", S);
  printf("Day : %d\n", index_res);
  free(arr);
  free(thr);
  free(thrData);
  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
  printf("task2 took %f seconds to execute \n", time_taken);
  return 0;
}
