/*27. Write a program to receive messages from the message queue.
b. with IPC_NOWAIT as a flag*/


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
   
    int msgid;
    struct msg_buffer message;
    ssize_t msg_size;

   

   
    msgid = msgget(1090846721, 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

   
    for (int i = 0; i < 5; i++) {
        msg_size = msgrcv(msgid, &message, sizeof(message.msg_text), 1, IPC_NOWAIT);
        if (msg_size == -1) {
            if (errno == ENOMSG) {
                printf("No messages available right now.\n");
            } else {
                perror("msgrcv");
                exit(EXIT_FAILURE);
            }
        } else {
            printf("Received: %s\n", message.msg_text);
        }

       
        sleep(1);
    }

    return 0;
}
/*eceived: Message 4
Received: Message 5
No messages available right now.
No messages available right now.
No messages available right now.
*/
