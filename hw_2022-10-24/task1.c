#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

enum {BUFF_SIZE = 256};

int main(int argc, char *argv[]) {
  int fd = open(argv[1], O_RDONLY);
  char buff[BUFF_SIZE];
  if(fd == -1) {
    char* msg = strerror(errno);
    write(2, argv[1], strlen(argv[1]));
    write(2, ": ", 2);
    write(2, msg, strlen(msg));
    write(2, "\n", 1);
  }
  int n;
  int ffd = creat(argv[2],O_CREAT|S_IRWXO|S_IRWXU);
  if(ffd == -1) {
    char* msg = strerror(errno);
    write(2, argv[2], strlen(argv[2]));
    write(2, ": ", 2);
    write(2, msg, strlen(msg));
    write(2, "\n", 1);
  }
  while((n = read(fd, buff,BUFF_SIZE))) {
    for(int i = 0; i < n; ++i) {
      if(buff[i] <= 57 && buff[i] >= 48) {
        buff[i] = 'X';
      }
    }
    write(ffd,buff,n);
  }
  close(ffd);
  close(fd);
  return 0;
}
