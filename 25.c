/*25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>


struct msqid_ds mq_info;

void print_message_queue_info(int msgid) {
   msgctl(msgid, IPC_STAT, &mq_info);
    printf("Access Permissions: %o\n", mq_info.msg_perm.mode & 0777);
    printf("UID: %u\n", mq_info.msg_perm.uid);
    printf("GID: %u\n", mq_info.msg_perm.gid);
    printf("Last Message Sent: %s", ctime(&mq_info.msg_stime));
    printf("Last Message Received: %s", ctime(&mq_info.msg_rtime));
    printf("Last Change Time: %s", ctime(&mq_info.msg_ctime));
    printf("Queue Size (in bytes): %lu\n", mq_info.__msg_cbytes);
    printf("Number of Messages: %lu\n", mq_info.msg_qnum);
    printf("Maximum Bytes Allowed: %lu\n", mq_info.msg_qbytes);
    printf("PID of Last Message Sent: %u\n", mq_info.msg_lspid);
    printf("PID of Last Message Received: %u\n", mq_info.msg_lrpid);
}

int main() {
    key_t key = 1090846721;

    int msgid;

   
    msgid = msgget(key, 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    print_message_queue_info(msgid);

    return 0;
}

/*ccess Permissions: 666
UID: 1000
GID: 1000
Last Message Sent: Thu Jan  1 05:30:00 1970
Last Message Received: Thu Jan  1 05:30:00 1970
Last Change Time: Thu Sep 19 14:52:56 2024
Queue Size (in bytes): 0
Number of Messages: 0
Maximum Bytes Allowed: 16384
PID of Last Message Sent: 0
PID of Last Message Received: 0
*/
