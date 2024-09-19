//21. Write two programs so that both can communicate by FIFO -Use two way communications.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd1, fd2;
    const char *path1 = "fifo1";
    const char *path2 = "fifo2";
    char buffer[128];
    const char *message = "Hello from Program 2!";

    
    fd1 = open(path1, O_RDONLY);
    fd2 = open(path2, O_WRONLY);
   

    ssize_t bytes_read = read(fd1, buffer, sizeof(buffer) - 1);
   
    buffer[bytes_read] = '\0';
    printf("Message received from Program 1: %s\n", buffer);

    
    if (write(fd2, message, strlen(message) + 1) == -1) {
        perror("write fifo2_to_1");
        close(fd1);
        close(fd2);
        exit(EXIT_FAILURE);
    }
    printf("Message sent to Program 1\n");

    
    close(fd1);
    close(fd2);

    return 0;
}

/*Message received from Program 1: Hello from Program 1!
Message sent to Program 1
*/
