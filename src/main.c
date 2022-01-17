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
// function for printing error messages
void err_sys(char *msg)
{
    perror(msg);
    exit(1);
}

int main(void)
{
	int n;
	char buf[BUFFSIZE];
	// open the file or create a file if it doesn't exist' for writing or appending
	int fd = open("output.log", O_WRONLY | O_APPEND | O_CREAT, 0666); 
	
	if (fd < 0)
	{ // Error handling for opening the file
		err_sys("error opening file");
	}
	if (write(fd, "==========================\n", 28) != 28)  // write required seperator bars in the file
	{ // Error handling for writing to file
		err_sys("write to file error"); 
	}
	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) 
	{
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");
		if (write(fd, buf, n) != n)
		{// Error handling for writing to file
			err_sys("write to file error"); 
		}
	}
	if (n < 0)
		err_sys("read error");
	// This is to create a double bar in between file openings. 
	if (write(fd, "==========================\n", 28) != 28) // write required seperator bars in the file
	{ // Error handling for writing to file
		err_sys("write to file error"); 
	}
	exit(0);
}
