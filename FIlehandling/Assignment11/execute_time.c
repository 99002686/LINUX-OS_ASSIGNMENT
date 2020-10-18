#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

#define MICRO 1000000

int sum(int num)
{
    int res=0;
    while(num)
    {
        res += num%10;
        num /= 10;
    }
    sleep(1);
    return res;
}

void testfun()
{
    int num=36;
    if(sum(num) == sqrt(num))
    {
        printf("It's is a perfect number\n");
    }
    printf("It's not a perfect number\n");
}

void clockgettime()
{
    double elapsed_time = 0.0;
    clock_t time;
    time = clock();
    testfun();
    time = clock() - time;
    elapsed_time = ((double)time)/CLOCKS_PER_SEC;
    printf("Time to execute testfun snipper = %fs\n", elapsed_time);
}

void gettime_day()
{
    struct timeval begin, end;
    //struct timezone place;
    long second = 0.0, micro_sec = 0.0;
    gettimeofday(&begin, NULL);
    testfun();
    sleep(2);
    gettimeofday(&end, NULL);
    second = (end.tv_sec - begin.tv_sec);
    micro_sec = ((second * MICRO) + end.tv_usec) - (begin.tv_usec);
    printf("Time of Execution is %lds %ldus \n", second, micro_sec);
}

int main(void)
{
    int choice;
     printf("Enter the choice:\n 1)clock_gettime: Press 1\n2)gettime_day: Press 0\n");
    scanf("%d", & choice);
    if(choice)
    {
        printf("Get time from clock\n");
        clockgettime();
    }
        
    else
    {
        printf("Get time of the day\n");
        gettime_day();
    }
    return 0;
}
