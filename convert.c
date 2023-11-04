#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char *s;

void check() {
	int fd = open("input.txt", O_RDONLY);
	printf("%d", fd);
}

int main() {
	int fd = open("input.txt", O_RDONLY);
	if(fd == -1) {
		printf("Nothing to read! Please input something.");	
		exit(0);
	}
	else {
		s = (char*)malloc(10);
		read(fd, s, 10);
		printf("Input are: %s", s);	
	}
	return 0;
}
