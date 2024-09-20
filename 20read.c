//
/*============================================================================
Name : 20read.c
Author : Rishika Gupta
Date: 19/9/24*/
//20. Write two programs so that both can communicate by FIFO -Use one way communication.
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    char buff[256];
    const char *path = "myfifo";

   
    fd = open(path, O_RDONLY);
   
    ssize_t bytes_read = read(fd, buff, sizeof(buff) - 1);
    buff[bytes_read] = '\0';

    printf("Message read from FIFO: %s\n", buff);

    
    close(fd);

    return 0;
}
//============================================================================
//Message read from FIFO: Hello from writer!

