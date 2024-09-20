/*
============================================================================
Name : 28.c
Author : Rishika Gupta
Date: 20/9/24
28. Write a program to change the exiting message queue permission. (use msqid_ds structure)
//============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>


struct msqid_ds mq_info;

int main() {

    int msgid;


key_t  key = ftok("/tmp", 'A'); 
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }


    msgid = msgget(key, 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    
    if (msgctl(msgid, IPC_STAT, &mq_info) == -1) {
        perror("msgctl (IPC_STAT)");
        exit(EXIT_FAILURE);
    }

   
    printf("Current Permissions: %o\n", mq_info.msg_perm.mode & 0777);

    
    mq_info.msg_perm.mode = (mq_info.msg_perm.mode & ~0777) | 0777;

    
    if (msgctl(msgid, IPC_SET, &mq_info) == -1) {
        perror("msgctl (IPC_SET)");
        exit(EXIT_FAILURE);
    }

    
    if (msgctl(msgid, IPC_STAT, &mq_info) == -1) {
        perror("msgctl (IPC_STAT)");
        exit(EXIT_FAILURE);
    }

   
    printf("Updated Permissions: %o\n", mq_info.msg_perm.mode & 0777);

    return 0;
}
//============================================================================
/*Current Permissions: 666
Updated Permissions: 777
*/
