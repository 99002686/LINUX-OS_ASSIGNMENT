#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
    int childProc[3], status;
    childProc[0] = fork();
    if(childProc[0]==0)
    {
        char *buffer[] = { "gcc","-c","-Iinclude","src/factorial.c",
                            "src/flip.c",
                            "src/isPalindrome.c",
                            "src/isPrime.c",
                            "src/mystrcat.c",
                            "src/mystrcmp.c",
                            "src/mystrcpy.c",
                            "src/query.c",
                            "src/reset.c",
                            "src/set.c",
                            "src/vsum.c",
                            "src/mystrlen.c", 
                            "src/unity.c",
                            "src/test.c" ,NULL };
        execv("/usr/bin/gcc", buffer);
    }
    else if(childProc[0] < 0)
    {
        perror("childProc[0] Error");
        exit(0);
    }
    else
    {
        printf("Inside childProc[0]\n");
        waitpid(childProc[0], &status, 0);
        childProc[1] = fork();
    }

    if(childProc[1] == 0)
    {
        char *buffer[] = {"ar", "rc","libstatic.a","factorial.o",
                            "flip.o",
                            "isPalindrome.o",
                            "isPrime.o",
                            "mystrcat.o",
                            "mystrcmp.o",
                            "mystrcpy.o",
                            "query.o",
                            "reset.o",
                            "set.o",
                            "vsum.o",
                            "mystrlen.o", 
                            "unity.o",
                            "test.o", NULL };
        execv("/usr/bin/ar", buffer);
    }
    else if(childProc[1] < 0)
    {
        perror("Error childProc[1]");
        exit(1);
    }    
    else
    {
        printf("Inside childProc[1]\n");
        waitpid(childProc[1], &status, 0);
        childProc[2] = fork();
    }

    if(childProc[2] == 0)
    {
        char *buffer[] = {"gcc","test.o","-L.","-lstatic","-o","ALLFUN.out",NULL};
        execv("/usr/bin/gcc", buffer);
    }
    else if(childProc[2] < 0)
    {
        perror("Error childProc[2]");
        exit(2);
    }    
    else
    {
        printf("Inside childProc[2]\n");
        waitpid(childProc[2], &status, 0);
         childProc[3] = fork();
    }

    if(childProc[3] == 0)
    {
       execl("ALLFUN.out","./ALLFUN.out",NULL);
    }
    else if(childProc[3] < 0)
    {
        perror("Error childProc[3]");
        exit(3);
    }    
    else
    {
        printf("Inside childProc[3]\n");
        waitpid(childProc[3], &status, 0);
    }
    return 0;
}
