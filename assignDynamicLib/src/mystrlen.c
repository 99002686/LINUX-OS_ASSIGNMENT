#include "mystring.h"

int mystrlen(char *in)
{
    int count=0, iter;
    for(iter=0; in[iter] != '\0'; iter++)
    {
        count++;
    }
    return count;
}

