/*4. Implement a simple client-server scenario using message queues
   * Client process send a string over message queue
   * Server process toggles the string and send back to client.*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer 
{
   long msg_type;
   char msg[100];
};

int main() 
{
   //char key;
   key_t my_key;
   struct msg_buffer message;
   int msg_id;
   my_key = ftok("progfile", 65); 
   msg_id = msgget(my_key, 0666 | IPC_CREAT); 
   message.msg_type = 1;
   printf("Terminal command:");
   fgets(message.msg, 128, stdin);
   msgsnd(msg_id, &message, sizeof(message), 0); 
   msgrcv(msg_id, &message, sizeof(message), 1, 0); 
   return 0;
}
