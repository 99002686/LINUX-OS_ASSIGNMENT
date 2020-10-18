#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include<sys/wait.h>
#include <pthread.h>

#define SIZE 102
int array[SIZE];

void* thread_handler(void* index)
{
    int iter, sum=0, ind;
    ind = (int)index;
    for(iter=ind*10; iter<(ind*10)+10; iter++)
    {
        sum += array[iter];
    }    
    printf("Thread[%d], SUM = %d\n", ind, sum);
}

int main(void)
{
    int iter, id, n=10, i;

    pthread_t ptarr[n];
    for(iter=0; iter<SIZE-1; iter++)
    {
        array[iter] = iter;
    }
    
    for(iter=0; iter<n; iter++)
    {
        //array[iter] = iter;
        pthread_create(&ptarr[iter], NULL, thread_handler, (void*) iter);
    }
    for(iter=0; iter<n; iter++)
        pthread_join(ptarr[iter], NULL);
    return 0;
}