/*============================================================================
Name : 29.c
Author : Rishika Gupta
Date: 20/9/24
//29. Write a program to remove the message queue.
*///============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>



int main() {
    key_t key;
    int msgid;


    key = ftok("/tmp", 'B');
    
    msgid = msgget(key,IPC_CREAT|0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

	printf("msg queue created\n");    
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl (IPC_RMID)");
        exit(EXIT_FAILURE);
    }

    printf("Message queue removed successfully.\n");

    return 0;
}
//============================================================================
/*msg queue created
Message queue removed successfully.
*/
