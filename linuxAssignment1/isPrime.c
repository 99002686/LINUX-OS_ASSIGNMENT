#include "myutils.h"

int isPrime(int num)
{
    int iter;
    for(iter = 2; iter <= num/2; iter++)
    {
        if(!(num%iter))
            return 0;
    }   
    return 1;
} 