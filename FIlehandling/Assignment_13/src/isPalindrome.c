#include "myutils.h"

long int reverse(long int num)
{
    long int sum=0;
    while(num)
    {
        sum = (sum*10)+(num%10);
        num /= 10;
    }
    return sum;
}

int isPalindrome(long int num)
{
    if(num == reverse(num))
        return 1;
    return 0;
}

