#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define COUNT 100

int main(int argc, char* argv[])
{
	int i_fd, o_fd;
        char buf[COUNT];
	ssize_t numRead;
	if (argc != 3)
	{
		printf("Usage: %s file-old file-new\n", argv[0]);
		exit(-1);
	}

	i_fd = open(argv[1], O_RDONLY);
	if (i_fd < 0){
		perror("could not open file1\n");
		exit(-2);
	}
	o_fd = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644); // -rw-r--r--
	if (o_fd < 0){
		perror("could not open file2\n");
		exit(-3);
	}
	while((numRead = read(i_fd, buf, COUNT))>0)
	{
		if(write(o_fd, buf, numRead)!=numRead)
		{
			perror("Write failed\n");
			exit(-4);
		}
	}
	if(close(i_fd)<0)
		perror("Error closing file1\n");
	if(close(o_fd)<0)
		perror("Error closing file2\n");

	return 0;

}
