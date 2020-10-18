#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAXLEN 256

int main(void)
{
    int fp, size, count[3]={0}, iter=0;
    fp = open("source.txt", O_RDONLY);
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
    while(buffer[iter])
    {
        if(buffer[iter] == ' ')
            count[0]++;
        if(buffer[iter] == '\n')
            count[1]++;
        else
        {
            if((buffer[iter] >= 'a' && buffer[iter] <= 'z') || 
                (buffer[iter] >= 'A' && buffer[iter] <= 'Z'))
            count[2]++;
        } 
        iter++;
    }
    printf("WORDS = %d\nLINES = %d\nALPHABETS = %d\n", count[0], count[1], count[2]);
    //write(1, count, 2);
    return 0;
}