#include <stdio.h> 
#include <sys/resource.h> 
#include <string.h> 
#include <errno.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdlib.h>

struct rlimit maxResourceAllocation(void)
{
    struct rlimit limitproc;
    if(getrlimit(RLIMIT_NOFILE, &limitproc) < 0)
    {
        fprintf(stderr, "maxResource: %s\n", strerror(errno));
        exit(0);
    }
    return limitproc;
}

struct rlimit getNewResource(void)
{
    struct rlimit limitproc, newProc;
    printf("\nEnter New Soft Limit:");
    scanf("%ld", &limitproc.rlim_cur);
    printf("\nEnter New Hard Limit:");
    scanf("%ld", &limitproc.rlim_max);
    if(setrlimit(RLIMIT_NOFILE, &limitproc) < 0) 
    {
        fprintf(stderr, "setlimit: %s\n", strerror(errno)); 
        exit(1);
    }

    if(getrlimit(RLIMIT_NOFILE, &newProc) < 0)
    {
        fprintf(stderr, "getrLimit:%s\n", strerror(errno));
        exit(2);
    }
    printf("New limits soft limit= %ld \t hard limit= %ld \n", 
        newProc.rlim_cur, newProc.rlim_max);
    return newProc;
}

int main()
{
    struct rlimit *oldLimit;
    *oldLimit = maxResourceAllocation();
    printf(" OldLimit soft limit= %ld \t OldLimit hard limit= %ld \n", 
        oldLimit->rlim_cur, oldLimit->rlim_max);  

    getNewResource(); 
    
    return 0;
}
