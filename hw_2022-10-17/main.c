#include <stdio.h>
#include <unistd.h>
#include "str.h"

int main(int argc, char *argv[]) {
  for(int i = 0;i<argc-1;++i) {
    printf("%d ", string_length(argv[i+1]));
    printf("%d\n", num_digits(argv[i+1]));
  }
  return 0;
}