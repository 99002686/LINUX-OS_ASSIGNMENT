#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int status, child1;
    if(argc == 2)
    {
        child1 = fork();
        if(child1 == 0)
        {
            execlp(argv[1], argv[1], NULL);
        }
        else if(child1 < 0)
        {
            perror("Error child1\n");
            exit(0);
        }
        else
        {
            printf("Inside child1...\n");
            waitpid(child1, &status, 0);
        }
   }
   else if(argc > 2)
   {
       printf("Error in Argument...\n");
   }
   else
   {
       printf("Need atleast one argument is expected\n");
   }
   
   return 0;    
}