#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include<sys/wait.h>

#define MAXLEN 1024
int main()
{
    pid_t fret;
    int fd, status;
    printf("PID = %d\n", getpid());
    fret = fork();
    char *buffer[] = {"gcc", "perfectnum.c", "-o", "perfect.out", "-lm", NULL};
    /*while(command[iter++])
    {
        if(command[iter] == ' ')
        {
            bindex++;
            sindex=0;
            continue;
        }
        buffer[bindex][sindex] = command[iter];
    }*/

    if(fret < 0)
    {
        perror("Fork Error");
    }

    if(fret == 0)
    {
        printf("Child - %d Initiatiating execl command", getpid());
        int execlf;
        execlf = execv("/usr/bin/gcc", buffer);
        if(execlf < 0)
        {
            perror("execv error");
            exit(1);
        }
        exit(0);
    }

    else
    {
        printf("Parent - %d\n", getpid());
        waitpid(-1,&status,0);
        printf("parent--child exit status=%d\n", WEXITSTATUS(status));
    }
    return 0;
}

//"gcc", "perfectnum.c", "-o", "perfect.out", "-lm"