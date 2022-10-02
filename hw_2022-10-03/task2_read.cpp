#include "task2_read.hpp"

  void read_and_invert() {
    char chr[81], c;
    int num = -1;
    for(int i = 0;i<80;++i) {
      c = getchar();
      if(c != '\n') {
        chr[i] = c;
      }
      else {
        break;
      }
      num++;
    }
    for(int i = 0;i<num+1;++i) {
      putchar(chr[num-i]);
    }
    putchar('\n');
  }
