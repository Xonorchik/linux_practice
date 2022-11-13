#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
	if (argc != 5) {
		printf("Incorrect amount of args");
		exit(1);
	}
	int fd1[2];
	int fd2[2];
//p1 < file1 | p2 > file2
	if(pipe(fd1) == -1 || pipe(fd2) == -1) {
		perror(NULL);
		exit(2);
	}
	if(fork() == 0) {
		int fd = open(argv[2], O_RDWR);
		if(fd == -1) {
			perror(NULL);
			exit(2);
		}
		dup2(fd, 0);
		close(fd);
		write(fd1[1], &fd, sizeof(fd));
		int _fd;
		read(fd2[0], &_fd, sizeof(fd));
		close(fd1[0]);
		close(fd1[1]);
		close(fd2[0]);
		close(fd2[1]);
		execlp(argv[1], argv[1], NULL);
		exit(0);
	}
	if(fork() == 0) {
		int fd = open(argv[4], O_RDWR|O_TRUNC|O_CREAT, 0777);
		if(fd == -1) {
			perror(NULL);
			exit(2);
		}
		dup2(1, fd);
		//close(fd);
		write(fd2[1], &fd, sizeof(fd));
		int _fd;
		read(fd1[0], &_fd, sizeof(fd));
		close(fd1[0]);
		close(fd1[1]);
		close(fd2[0]);
		close(fd2[1]);
		execlp(argv[3], argv[3], NULL);
		exit(0);
	}
	return 0;
}
