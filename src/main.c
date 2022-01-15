#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <io.h>
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
		if ((write(STDOUT_FILENO, buf, n) || (write(filedesc, buf, n))!= n))
			err_sys("write error");

	if (n < 0) err_sys("read error");

	exit(0);
}
