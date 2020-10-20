#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>
#define SIZE 8

int stack[SIZE];     
int top = -1;  
const int max = 10;
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
sem_t sema1;

int stackEmpty() 
{

   if(top == -1)
      return 1;
	return 0;
}
   
int stackFull() 
{

   if(top == SIZE)
      return 1;
    return 0;
}

int peek() 
{
   return stack[top];
}

int pop() 
{
   int data;
   if(!stackEmpty()) 
   {
      data = stack[top];
      top = top - 1;   
      return data;
   } 
   else 
   {
      printf("Stack is empty.\n");
   }
}

int push(int data)
{
	if(!stackFull()) 
   	{
    	top = top + 1;   
    	stack[top] = data;
   	}
	else 
	{
      printf("Stack is full.\n");
    }
}


void* pushFunction(void* pv)		
{
	int i;
	printf("Pushing 11,22,93,46 in stack\n");
	pthread_mutex_lock(&mutex1);
	push(11);
	push(22);
	push(93);
	push(46);
	pthread_mutex_unlock(&mutex1);
	sem_post(&sema1);
}

void* popFunction(void* pv)		
{
	int i;
	printf("Popping 11 and 22, and 93,46 are in the stack\n");
	sem_wait(&sema1);			
	pthread_mutex_lock(&mutex1);
	pop();
	pop();	
	pthread_mutex_unlock(&mutex1);
}

int main()
{
	printf("Producer Consumer problem using semaphores\n");
	pthread_t parThread1,parThread2;	//thread handles
	sem_init(&sema1,0,0);
	pthread_create(&parThread1,NULL,pushFunction,NULL);
	pthread_create(&parThread2,NULL,popFunction,NULL);
	pthread_join(parThread1,NULL);
	pthread_join(parThread2,NULL);
	printf("Element at top: %d\n" ,peek());
	printf("Stack full: %s\n" , stackFull()?"Y":"N");
   	printf("Stack empty: %s\n" , stackEmpty()?"Y":"N");
	sem_destroy(&sema1);
	pthread_mutex_destroy(&mutex1);
	printf("main-- Job done\n"); 
	return 0;
}

