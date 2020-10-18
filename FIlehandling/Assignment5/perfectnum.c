#include <stdio.h>
#include <math.h>
int sum(int num)
{
    int res=0;
    while(num)
    {
        res += num%10;
        num /= 10;
    }
    return res;
}

int main(void)
{
    int num=36;
    if(sum(num) == sqrt(num))
    {
        printf("It's is a perfect number");
        return 0;
    }
    printf("It's not a perfect number");
    return 0;
}