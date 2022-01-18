// ECE362
// Assignment 2 Problem 2
// Dr. Schubert
// by luke hoskam
// Solution for Problem2

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
#include <stdbool.h>
#include <string.h>

void err_sys(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int n = 1; // number of lines to read
    int i;     // indexing number for loops
    bool hasBuf = false;
    bool hasFilename = false;
    int filenamePos = 0; // position of the filename in argv[]
    char buffer[10];     // buffer size
    int hasError = 0;

    // check to see if there is
    if (argc < 4)
    {
        for (i = 1; i < argc; i++)
        {
            if (*(argv[i] + 0) == '-') // (*(argv[i]+0)) refrences the first character of each element
            {
                if (!hasBuf) // set the number of lines to read if not set
                {
                    n = atoi(argv[i]) * (-1);
                    hasBuf = true;
                }
                else // send error saying too many buffer modifiers sent
                {
                    hasError = write(STDERR_FILENO, "Argument Error", 14); // write the line read to STDOUT
                    if (hasError == -1)
                    {
                        err_sys("ERROR: Failed to write to STDERR!");
                    }
                    err_sys("ERROR: too many line modifiers for number of lines to read!\n Entry should be: \n [header -<numLines> <filename>]\n"); // maybe change this to a printf or write
                }
            }
            else
            {
                if (!hasFilename) // set the filename if not set
                {
                    filenamePos = i;
                    hasFilename = true;
                }
                else
                {
                    err_sys("ERROR: too many file names!\n Entry should be: \n [header -<numLines> <filename>]\n"); // maybe change this to a printf or write
                }
            }
        }
    }
    else
    {
        err_sys("ERROR: too many arguments! \n Entry should be: \n [header -<numLines> <filename>]\n"); // maybe change this to a printf or write
    }
    char filename[sizeof(argv[filenamePos]) + 1]; // create a variable to hold the filename to be in accordance with the instructions... argv[filenamePos] would work though.
    strcpy(filename, argv[filenamePos]);
    int fd;
    if (hasFilename) // if filename is set, open that file for reading
    {
        fd = open(filename, O_RDONLY);
        if (fd == -1)
        {
            err_sys("ERROR: failed to open file!");
        }
    }
    else // if no filename is set open STDIN for input
    {
        fd = STDIN_FILENO;
    }
    int numRead = 0;                                          // number of characters read by the read function
    int lineCount = 0;                                        // number of lines read by the read function
    while (lineCount < n && (numRead = read(fd, buffer, 10))) // keep reading until there is an error reading OR we have read all the desired lines
    {
        if (numRead == -1)
        { // read returns -1 if there was an error reading
            err_sys("ERROR: Failed to read!");
        }
        for (int i = 0; i < numRead; i++)
        { // cyle though the buffer to find the number of characters read before the '\n' character if no '\n' char numRead will be 10
            if (buffer[i] == '\n')
            {
                lineCount++;
                if (lineCount >= n)
                {
                    numRead = i + 1; // need to add 1 to include the '\n' character and set this as the buffer size.
                }
            }
        }
        hasError = write(STDOUT_FILENO, buffer, numRead); // write the line read to STDOUT
        if (hasError == -1)
        {
            err_sys("ERROR: Failed to write!");
        }
    }
    close(fd); // dont forget to close the file
}
