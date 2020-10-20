#include<stdio.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX 8

sem_t s_empty;
sem_t s_full;
int queue[MAX];
int front = -1;
int rear = -1;

void insert(int element);
void deletion();

void* pd(void* pp)
{ int element;
   sem_wait(&s_empty);
   scanf("%d",&element);
   insert(element);
   printf("\n");
   sem_post(&s_full);
}

void* cd(void* pp)
{
   sem_wait(&s_full);
   deletion();
   sem_post(&s_empty);
}

void insert(int element)
{
   if((front == 0 && rear == MAX-1) || (front == rear+1))
   {
      printf("Queue Overflow \n");
      return;
   }
   if(front == -1)
   {
      front = 0;
      rear = 0;
   }
   else
   {
      if(rear == MAX-1)
         rear = 0;
      else
       rear = rear+1;
   }
   queue[rear] = element ;
   printf("Element Produced : %d\n",element);
}

void deletion()
{
   if(front == -1)
   {
      printf("Queue on Underflow");
      return ;
   }
   printf("Element Consumed : %d\n",queue[front]);
   if(front == rear)
   {
      front = -1;
      rear=-1;
   }
   else
   {
      if(front == MAX-1)
         front = 0;
      else
         front = front+1;
   }
}


int main()
{
   int element, i;
   pthread_t pro[8],con[8];
   sem_init(&s_empty,0,MAX);
   sem_init(&s_full,0,0);
   printf("Enter the elements to be produced and consumed of buffer 8\n ");
   for(i=0; i<8; i++) 
      pthread_create(&pro[i], NULL, (void *)pd, NULL);

   for(i=0; i<8; i++)
      pthread_create(&con[i], NULL, (void *)cd,NULL);
   
   for(i=0; i<8; i++) 
      pthread_join(pro[i], NULL);
   
   for(int i = 0; i < 8; i++)
      pthread_join(con[i], NULL);
   sem_destroy(&s_empty);
   sem_destroy(&s_full);
   return 0;
}
