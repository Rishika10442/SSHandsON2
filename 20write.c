/*============================================================================
Name : 20write.c
Author : Rishika Gupta
Date: 19/9/24*/
//20. Write two programs so that both can communicate by FIFO -Use one way communication.
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<string.h>
int main() {
    int fd;
    const char *path = "myfifo";
    const char *m = "Hello from writer!";
    size_t message_len = strlen(m) + 1;

   fd = open(path, O_WRONLY);
   write(fd, m, message_len);

    printf("Message written to FIFO: %s\n", m);

    
    close(fd);

    return 0;
}
//============================================================================
//Message written to FIFO: Hello from writer!

