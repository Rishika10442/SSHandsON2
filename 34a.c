/*
============================================================================
Name : 34a.c
Author : Rishika Gupta
Date: 20/9/24
34. Write a program to create a concurrent server.
a. use fork*/
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024



void handle_client(int cs) {
    char buff[BUFFER_SIZE];
    int read_size;

    printf("Server has forked child with id %d to handle client\n", getpid());

   
    while (1) {
   
        read_size = read(cs, buff, sizeof(buff) - 1);
        if (read_size > 0) {
            buff[read_size] = '\0'; 
            printf("Message from client: %s\n", buff);

            
            if (strcmp(buff, "exit") == 0) {
                printf("Client sent 'exit', closing connection...\n");
                break; 
            }

            
            const char *response = "Hello from the server, received your message";
            send(cs, response, strlen(response), 0);
        } else if (read_size == 0) {
            
            printf("Client disconnected unexpectedly.\n");
            break;
        } else {
            
            perror("Read error");
            break;
        }
    }

    
    close(cs);
    printf("Connection with client closed.\n");
}

int main() {
    int sfd, cs;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    
    bind(sfd, (struct sockaddr *)&address, sizeof(address));
    listen(sfd, 5);

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
    
        cs = accept(sfd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        
        pid_t pid = fork();
        if (pid == 0) {
           
            close(sfd); 
            handle_client(cs); 
            exit(0); 
        } else if (pid > 0) {
            
            close(cs);
        } else {
            perror("Fork failed");
	}     
    }

   
    close(sfd);
    return 0;
}
//============================================================================
/*Server is listening on port 8080...
Server has forked child with id 7262 to handle client
Server has forked child with id 7266 to handle client
Message from client: heyy
Message from client: sdf
Message from client: ad
Message from client: ad
Message from client: exit
Client sent 'exit', closing connection...
Connection with client closed.
Message from client: jhk
Message from client: exit
Client sent 'exit', closing connection...
Connection with client closed.
*/
