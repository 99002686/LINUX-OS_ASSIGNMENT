#include "mystring.h"

void* mystrcpy(char* in)
{
    int size, iter;
    char *cpy;
    size = mystrlen(in) + 1;
    cpy = malloc(size*sizeof(char));
    for(iter=0; iter != '\0'; iter++)
    {
        cpy[iter] = in[iter];
    }
    cpy[iter] = '\0';
    return cpy;
}