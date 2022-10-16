#include "str.h"

int string_length(const char *buff) {
  int res = 0;
  for(int i = 0;buff[i] != '\0';++i) {
    res++;
  }
  return res;
}
int num_digits(const char *buff) {
  int res = 0;
  for(int i = 0;buff[i] != '\0';++i) {
    if(buff[i] <= 57 && buff[i] >= 48) {
      res++;
    }
  }
  return res;
}