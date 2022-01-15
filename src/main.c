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

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");

	if (n < 0) err_sys("read error");

	exit(0);
}
