/*
============================================================================
Name : 27a.c
Author : Rishika Gupta
Date: 20/9/24
27. Write a program to receive messages from the message queue.
a. with 0 as a flag*/
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>


struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;
    key = ftok("/tmp", 'A');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    
    msgid = msgget(key, 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < 3; i++) {
        if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }

        printf("Received: %s\n", message.msg_text);
    }

    return 0;
}
//============================================================================
/*Received: Message 1
Received: Message 2
Received: Message 3
*/
