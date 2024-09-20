/*============================================================================
Name : 26.c
Author : Rishika Gupta
Date: 20/9/24*/
//26. Write a program to send messages to the message queue. Check $ipcs -q
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>


#define PERMISSIONS 0666


struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

key = ftok("/tmp",'A');
    msgid = msgget(key, IPC_CREAT | PERMISSIONS);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    
    for (int i = 1; i <= 5; i++) {
        message.msg_type = 1; 
        snprintf(message.msg_text, sizeof(message.msg_text), "Message %d", i);

        if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }

        printf("Sent: %s\n", message.msg_text);
    }

    return 0;
}
//============================================================================
/*------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x41050001 0          rishika-gu 666        500          5     */
