#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define CWD_MAX 1000
int main() {
	    char buf[CWD_MAX];
	    if((getcwd(buf, sizeof(buf)))==NULL)
	    {
	    	perror("Error getting current working directory!\n");
	    	exit(-1);                            
	    }
	      printf("%s\n", buf);
	return 0;
}
