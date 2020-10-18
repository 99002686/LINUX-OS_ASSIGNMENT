#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <pthread.h>
#include <stdlib.h>
#define SIZE 21
#define THREAD_S 4
#define MUL 5

void* thread_handler(void* *arg)
{
    int iter, *arr;
    arr = (int*)arg;
    int *max1 = (int*) malloc(1*sizeof(int));
    *max1 = arr[0];
    if(arr[SIZE-1])
    {
        for(iter = arr[SIZE]*MUL; iter<((arr[SIZE]+1)*MUL); iter++)
        {
           printf("thread[%d]: %d - %d\n", arr[SIZE], iter, *max1);
            if(arr[iter] > *max1)
            {
                *max1 = arr[iter];
            }
        }
    }

    if(!arr[SIZE-1])
    {
        for(iter = arr[SIZE]*MUL; iter<((arr[SIZE]+1)*MUL); iter++)
        {
            //printf("thread[%d]: %d - %d\n", arr[SIZE], arr[iter], max1);
            if(arr[iter] < *max1)
            {
                *max1 = arr[iter];
            }
        }
    }
    return max1;
}

int main(void)
{
    int arr[SIZE] = {122, 132, 434, 45, 454, 65, 789, 777,
     865, 988, 454, 354, 987, 675, 757, 87, 90, 22, 292, 89};
    int choice, iter, *retval, max=arr[1];
    pthread_t threads[THREAD_S];
    printf("This programs create 5 threads to find Maximum or minimum element in the array\n maximum Number:Press 1\n Minimum Number:Press 0\n");
    scanf("%d", &choice);
    arr[SIZE-1] = choice;
    
    for(iter=0; iter<THREAD_S; iter++)
    {
        arr[SIZE] = iter;
        pthread_create(&threads[iter], NULL, thread_handler, (void*)arr);
    }
    
    for(iter=0; iter<THREAD_S; iter++)
    {
        pthread_join(threads[iter],(void *) &retval);
        printf("%d = %d\n", iter, *retval);
        if(choice)
        {
            if(*retval > max)
                max = *retval;
        }
        else
        {
            if(*retval < max)
                max = *retval;
        }        
    }
 
    printf("Your choice %d results %d\n", choice, max);
    return 0;
}