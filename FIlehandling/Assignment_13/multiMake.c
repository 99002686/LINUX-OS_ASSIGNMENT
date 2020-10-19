#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
    int childProc1, childProc2, childProc3, status;
    childProc1 = fork();
    if(childProc1==0)
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
    else if(childProc1 < 0)
    {
        perror("childProc1 Error");
        exit(0);
    }
    else
    {
        printf("Inside childProc1\n");
        waitpid(childProc1, &status, 0);
        childProc2 = fork();
    }

    if(childProc2 == 0)
    {
        char *buffer[] = {"gcc","-Iinclude","factorial.o",
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
                            "test.o" ,"-o", "ALLFUN.out", NULL };
        execv("/usr/bin/gcc", buffer);
    }
    else if(childProc2 < 0)
    {
        perror("Error childProc2");
        exit(1);
    }    
    else
    {
        printf("Inside childProc2\n");
        waitpid(childProc2, &status, 0);
        childProc3 = fork();
    }

    if(childProc3 == 0)
    {
        execl("ALLFUN.out","./ALLFUN.out",NULL);
    }
    else if(childProc3 < 0)
    {
        perror("Error childProc3");
        exit(3);
    }    
    else
    {
        waitpid(childProc3, &status, 0);
    }
    
    return 0;
}