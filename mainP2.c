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
    fprintf(stderr, "%s (%s)\n", msg, strerror(errno));
    exit(1);
}

int main(int argc, char *argv[])
{
    int bufSize = 0;
    int i;
    int n;
    bool hasBuf = false;
    bool hasFilename = false;
    char *filename = NULL;
    int filenamePos = 0;

    if (argc < 4)
    {

        for (i = 1; i < argc; i++)
        {
            if (*(argv[i] + 0) == '-') // (*(argv[i]+0)) refrences the first character of each element
            {
                if (!hasBuf)
                {
                    bufSize = atoi(argv[i]) * (-1);
                    hasBuf = true;
                    printf("%d\n", bufSize);
                }
                else
                {
                    err_sys("ERROR: too many buffers!");
                }
            }

            else
            {
                if (!hasFilename)
                {
                    filenamePos = i;
                    hasFilename = true;
                }
                else
                {
                    err_sys("ERROR: too many file names!");
                }
            }
        }
    }
    else
    {
        err_sys("ERROR: too many arguments!");
    }
    printf("%s", argv[filenamePos]);

    system("clear");
    if (!hasBuf)
    {
        bufSize = 10;
    }
    if (!hasFilename)
    {
        char prompt[] = "Enter a filename then press ctrl-c: \n";
        
        {
            if (write(STDOUT_FILENO, prompt, 37) != 37)
            {
                err_sys("write error");
            }
        }
        while ((n = read(STDIN_FILENO, filename, bufSize)) > 0)
        {
            
        }
    }
    printf("%s", filename);
}
