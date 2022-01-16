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

#define BUFFSIZE 4096

void err_sys(char *msg)
{
	fprintf(stderr, "%s (%s)\n", msg, strerror(errno));
	exit(1);
}

int main(void)
{
	int n;
	char buf[BUFFSIZE];

	int filedesc = open("output.log", O_WRONLY | O_APPEND | O_CREAT, 0666);

	if (filedesc < 0)
	{
		err_sys("error opening file");
	}
	if (write(filedesc, "==========================\n", 28) != 28)
	{
		err_sys("write to file error");
	}
	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
	{
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");
		if (write(filedesc, buf, n) != n)
		{
			err_sys("write to file error");
		}
	}
	if (n < 0)
		err_sys("read error");

	if (write(filedesc, "==========================\n", 28) != 28)
	{
		err_sys("write to file error");
	}

	exit(0);
}
