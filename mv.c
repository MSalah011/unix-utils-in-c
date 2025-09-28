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
		printf("Usage: %s source-file destination-file\n", argv[0]);
		exit(-1);
	}

	i_fd = open(argv[1], O_RDONLY);
	if (i_fd < 0){
		perror("could not open source file\n");
		exit(-2);
	}
	o_fd = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644); // -rw-r--r--
	if (o_fd < 0){
		perror("could not open destination file\n");
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
		perror("Error closing source file\n");
	if(close(o_fd)<0)
		perror("Error closing destination file\n");

	if(remove(argv[1])<0)
		perror("Error removing source file\n");

	return 0;

}
