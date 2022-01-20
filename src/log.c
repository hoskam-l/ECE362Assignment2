// ECE362
// Assignment 2 Problem 1
// Dr. Schubert
// by luke hoskam
// Solution for Problem1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
	{ 
		err_sys("error opening file"); // Error handling for opening the file
	}
	if (write(fd, "==========================\n", 28) != 28)  // write required seperator bars in the file
	{ 
		err_sys("write to file error"); // Error handling for writing to file
	}
	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)  // Read from STDIN and set the number read to n 
	{
		if (write(STDOUT_FILENO, buf, n) != n) // write to STDOUT
			err_sys("write error"); // Error handling for STDOUT
		if (write(fd, buf, n) != n) // Write to file
		{
			err_sys("write to file error"); // Error handling for writing to file
		}
	}
	if (n < 0)
		err_sys("read error");
	// This is to create a double bar in between file openings. 
	if (write(fd, "==========================\n", 28) != 28) // write required seperator bars in the file
	{ 
		err_sys("write to file error"); // Error handling for writing to file
	}
	exit(0);
}
