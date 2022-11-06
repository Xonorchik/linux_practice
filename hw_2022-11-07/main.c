#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

enum{BUFF_SIZE = 256};

int main(int argc, char* argv[]) {
  if(argv[1] == NULL) {
    perror("No args");
    return 1;
  }
  int fd = open(argv[1],O_RDONLY,0666);
  if(fd == -1) {
    char* msg = strerror(errno);
    write(2, argv[1], strlen(argv[1]));
    write(2, ": ", 2);
    write(2, msg, strlen(msg));
    write(2, "\n", 1);
    return 2;
  }
  int ffd = creat("result",O_TRUNC|O_WRONLY|0666);
  char buf[BUFF_SIZE];
  int n;
  while((n = read(fd, buf,BUFF_SIZE))) {
    for(int i = 0; i < n; ++i) {
      if(buf[i] <= '9' && buf[i] >= '0') {
        buf[i] = '_';
      }
      else if(buf[i] <= 'x' && buf[i] >= 'a') {
        buf[i] = buf[i]-32;
      }
    }
    write(ffd,buf,n);
  }
  close(fd);
  close(ffd);
  return 0;
}