#include <io.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>


int main()
{
    int fd;
    int sz;
    char *c = (char *) callooc(100, sizeof(char));

    fd = open("output.log", O_RDONLY);
}