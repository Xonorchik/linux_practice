#include <unistd.h>
#include <fcntl.h>

enum{BUFSIZE = 1024};

int main(int argc, char* argv[]) {
  int fd = open(argv[1], O_RDWR);
  int n, i = 0;
  char *buf[BUFSIZE];
  while((n = read(fd, buf, BUFSIZE)) > 0) {
    if(*buf[i] == ' ' || *buf[i] == '\n') {
      *buf[i] = '\0';
    }
    ++i;
  }
  close(fd);
  if(fork() == 0) {
    execvp(argv[1], buf);
    return 0;
  }
  return 0;
}
