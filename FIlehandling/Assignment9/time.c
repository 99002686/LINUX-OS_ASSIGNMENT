#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <stdio.h>

void alarm_sig_handler(int signum)
{
    printf("Set Alarm function - %d\n", signum);
    alarm(2);
}

int main(void)
{
    int iter;
    time_t currtime;
    time(&currtime);
    signal(SIGALRM, alarm_sig_handler);
    alarm(3);
    for(iter=1;;iter++)
    {
        printf("[%d] Currentime: %s\n", iter, ctime(&currtime));
        pause();
    }
    return 0;
}