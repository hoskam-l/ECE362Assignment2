#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <io.h>
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#else
#include <unistd.h>
#endif
#include <string.h>
#include <errno.h>
#include <fcntl.h>


#define BUFFSIZE  4096

void err_sys(char* msg)
{
	fprintf(stderr, "%s (%s)\n", msg, strerror(errno));
	exit(1);
}

int main(void)
{
	int n;
	char buf[BUFFSIZE];
	
    	int filedesc = open("testfile.txt", O_WRONLY | O_APPEND);
 
    	if (filedesc < 0) {
        	return -1;
   	 }	
	

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");
		if (write(filedesc, buf, n) != n) {
        		write(2, "There was an error writing to testfile.txt\n", 43);
        		return -1;
		}

	if (n < 0) err_sys("read error");

	exit(0);
}
