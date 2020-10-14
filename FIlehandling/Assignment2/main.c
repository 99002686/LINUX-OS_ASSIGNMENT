#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAXLEN 256 

int main(void)
{
    int filed;
    filed = open("source.txt", O_RDONLY);
    if(filed < 0)
    {
        perror("open");
        exit(1);
    }
    char buffer[MAXLEN];
    write(1, buffer, read(filed, buffer, MAXLEN));
    close(filed);
    return 0;
}