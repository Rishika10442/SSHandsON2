//16. Write a program to send and receive data from parent to child vice versa. Use two way
//communication.


#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pc[2];
    int cp[2];
    char p_msg[] = "Hello from parent!";
    char c_msg[] = "Hello from child!";
    char read_buffer[100];
    pid_t pid;

   
   pipe(pc);
pipe(cp);
    pid = fork();

    if (pid > 0) {
        
        close(pc[0]);
        close(cp[1]);

        
        write(pc[1], p_msg, strlen(p_msg) + 1);

        
        read(cp[0], read_buffer, sizeof(read_buffer));
        printf("Parent received: %s\n", read_buffer);

        
        close(pc[1]);
        close(cp[0]);
    } else {
        
        close(pc[1]);
        close(cp[0]);
        read(pc[0], read_buffer, sizeof(read_buffer));
        printf("Child received: %s\n", read_buffer);

        
        write(cp[1], c_msg, strlen(c_msg) + 1);
        close(pc[0]);
        close(cp[1]);
    }

    return 0;
}
/*Child received: Hello from parent!
Parent received: Hello from child!*/
