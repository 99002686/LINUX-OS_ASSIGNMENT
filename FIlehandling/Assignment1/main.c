#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLEN 256
int main()
{
    int fp, size, fo;
    fp = open("source.txt", O_RDONLY);
    fo = open("destination.txt", O_WRONLY|O_CREAT, 0666);
    if(fp < 0)
    {
        perror("Open");
        exit(1);
    }

    char buffer[MAXLEN];
    size = read(fp, buffer, MAXLEN);
    if(size < 0)
    {
        perror("Read");
        exit(2);
    }
    write(1, buffer, size);
    fo = write(fo, buffer, size);
    if(fo < 0)
    {
        perror("Write");
        exit(3);
    }
    printf("Written Successfully, Size=%d\n", fo);
    close(fo);
    close(fp);
    return 0;
}