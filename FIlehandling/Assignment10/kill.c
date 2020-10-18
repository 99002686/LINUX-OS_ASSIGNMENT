#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int pid, choice;

int main(void)
{
    printf("Enter Process ID to be KILLED\n");
    scanf("%d", &pid);
    printf("Enter the choice:\n 1)Iterrupt: Press 1\n2)Kill PID: Press 0\n");
    scanf("%d", & choice);
    if(choice)
    {
        printf("CTRL^C, EXCUTED SIGINT COMMAND\n");
        kill(pid, SIGINT);
    }
    if(!choice)
    {
        printf("EXECUTED SIGKILL COMMAND\n");
        kill(pid, SIGKILL);
    }
    return 0;
}