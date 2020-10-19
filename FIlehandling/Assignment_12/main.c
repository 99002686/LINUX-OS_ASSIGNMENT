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
    if(getrlimit(RLIMIT_NPROC, &limitproc) < 0)
    {
        fprintf(stderr, "%s\n", strerror(errno));
        exit(0);
    }
    return limitproc;
}

void checkSetr(struct rlimit *resource)
{
    checkSetr(resource);
    if(setrlimit(RLIMIT_NOFILE, resource) < 0) 
        fprintf(stderr, "%s\n", strerror(errno)); 
}

struct rlimit getNewResource(void)
{
    struct rlimit limitproc;
    printf("\nEnter New Soft Limit:");
    scanf("%ld", &limitproc.rlim_cur);
    printf("\nEnter New Hard Limit:");
    scanf("%ld", &limitproc.rlim_max);
    
    if(getrlimit(RLIMIT_NPROC, &limitproc) < 0)
    {
        fprintf(stderr, "%s\n", strerror(errno));
        exit(0);
    }
    return limitproc;
}

int main()
{
    struct rlimit *oldLimit, *newLimit, setLimit;
    *oldLimit = maxResourceAllocation();
    printf(" OldLimit soft limit= %ld \t OldLimit hard limit= %ld \n", 
        oldLimit->rlim_cur, oldLimit->rlim_max);  

    *newLimit = getNewResource();
    printf("New limits -> soft limit= %ld \t hard limit= %ld \n", 
        newLimit->rlim_cur, newLimit->rlim_max); 

    return 0;
}