#include "mystring.h"

int mystrcmp(char *in1, char *in2)
{
    char *p1 = in1;
    char *p2 = in2;
    int iter, count=1;
     while (*p1 != '\0') {
        if (*p2 == '\0') return  1;
        if (*p2 > *p1)   return -1;
        if (*p1 > *p2)   return  1;

        p1++;
        p2++;
    }

    if (*p2 != '\0') return -1;
    return 0;
}