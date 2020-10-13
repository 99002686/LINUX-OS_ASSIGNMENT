#include "mystring.h"

void* mystrcat(char * in1, char * in2)
{
    int size1, iter, size2, iter1;
    char *cpy;
    size1 = mystrlen(in1) + 2;
    size2 = mystrlen(in2);
    cpy = malloc((size1+size2)*sizeof(char));
    for(iter=0; in1[iter] != '\0'; iter++)
    {
        cpy[iter] = in1[iter];
    }
    cpy[iter] = ' ';
    iter++;
    for(iter, iter1=0; in2[iter1] != '\0'; iter1++, iter++)
    {
        cpy[iter] = in2[iter1];
    }
    cpy[iter] = '\0';
    return cpy;
}