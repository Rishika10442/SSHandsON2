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
    const char *message = "Hello from Program 1!";
    char buffer[128];

    
    fd1 = open(path1, O_WRONLY);
    fd2 = open(path2, O_RDONLY);
        if (write(fd1, message, strlen(message) + 1) == -1) {
        perror("write fifo1_to_2");
        close(fd1);
        close(fd2);
        exit(EXIT_FAILURE);
    }
    printf("Message sent to Program 2\n");
    ssize_t bytes_read = read(fd2, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1) {
        perror("read fifo2_to_1");
        close(fd1);
        close(fd2);
        exit(EXIT_FAILURE);
    }
    buffer[bytes_read] = '\0';
    printf("Message received from Program 2: %s\n", buffer);
    close(fd1);
    close(fd2);

    return 0;
}
/*Message sent to Program 2
Message received from Program 2: Hello from Program 2!*/
