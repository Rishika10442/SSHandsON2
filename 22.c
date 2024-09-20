/*
============================================================================
Name : 22.c
Author : Rishika Gupta
Date: 19/9/24
22. Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.*/
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <errno.h>

#define FIFO_PATH "myfifo"
#define TIMEOUT_SEC 10

int main() {
    int fd;
    fd_set read_fds;
    struct timeval timeout;
    char buff[128];
    ssize_t bytes_read;

   
    fd = open(FIFO_PATH, O_RDONLY | O_NONBLOCK); 
    
    FD_ZERO(&read_fds);
    FD_SET(fd, &read_fds);

    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = 0;

   
    int res = select(fd + 1, &read_fds, NULL, NULL, &timeout);
    if (res == 0) {
      printf("Timeout: No data received.\n");
    } else {
        if (FD_ISSET(fd, &read_fds)) {
            bytes_read = read(fd, buff, sizeof(buff) - 1);
            
            buff[bytes_read] = '\0';
            printf("Data received from FIFO: %s\n", buff);
        }
    }
    close(fd);

    return 0;
}
//============================================================================
//Data received from FIFO: Hello from another terminal
//Timeout: No data received.
