/*
============================================================================
Name : 24.c
Author : Rishika Gupta
Date: 20/9/24
24. Write a program to create a message queue and print the key and message queue id.*/
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>


#define PERMISSIONS 0666

int main() {
    key_t key;
    int msgid;


    key = ftok("/tmp",'A');
 if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }    
    msgid = msgget(key, IPC_CREAT | PERMISSIONS);
 if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }
    
    printf("Message Queue Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);

    return 0;
}
//============================================================================
//ipcs-q to see all current queues

/*
Message Queue Key: 1090846721
Message Queue ID: 0
*/
