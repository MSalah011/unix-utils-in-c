#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define COUNT 100

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		printf("Usage: %s file-name", argv[0]);
		exit(-1);
	}
	int buf[COUNT];
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0){
		perror("could not open a file\n");
		exit(-2);
	}
	int num_read;
	num_read = read(fd, buf, COUNT);
	while(num_read> 0)
	{
		if(write(1, buf, num_read) < 0)
		{
			perror("Write failed\n");
                	exit(-3);
		}
		num_read = read(fd, buf, COUNT);
	}
	close(fd);
	return 0;
}
