#ifdef _WIN32
#include <io.h>
#else
#include <unistd.h>
#endif


#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#define BUFFSIZE  4096

void err_sys(char* msg)
{
	fprintf(stderr, "%s (%s)\n", msg, strerror(errno));
	exit(1);
}


int main(int argc, char *argv[])
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

	if (n < 0) err_sys("read error");
}