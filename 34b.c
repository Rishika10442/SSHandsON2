/*
============================================================================
Name : 34b.c
Author : Rishika Gupta
Date: 20/9/24
34. Write a program to create a concurrent server.
b. use pthread_create*/
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024


void *handle_client(void *cp) {
    int cs = *(int *)cp;
    free(cp);

    char buffer[BUFFER_SIZE];
    int read_size;

    printf("Thread %lu started to handle client.\n", pthread_self());

   
    while ((read_size = read(cs, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[read_size] = '\0';
        printf("Message from client: %s\n", buffer);

       
        if (strcmp(buffer, "exit") == 0) {
            printf("Client sent 'exit', closing connection...\n");
            break;
        }

       
        const char *response = "Hello from the server, got your message";
        send(cs, response, strlen(response), 0);
    }

    
    close(cs);
    printf("Thread %lu: Client disconnected.\n", pthread_self());
    return NULL;
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    

    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3) < 0;
       printf("Server is listening on port %d...\n", PORT);

    while (1) {
    
        client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    
        int *client_socket_ptr = malloc(sizeof(int));
        *client_socket_ptr = client_socket;

    
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)client_socket_ptr) != 0) {
            perror("Thread creation failed");
            free(client_socket_ptr);
            close(client_socket);
            continue;
        }

    
        pthread_detach(thread_id);
    }

    
    close(server_fd);
    return 0;
}
//============================================================================
/*Server is listening on port 8080...
Thread 139973428770496 started to handle client.
Thread 139973420377792 started to handle client.
Message from client: hey
Message from client: jsbcla
Message from client: ad
Message from client:  nmv,x
Message from client: exit
Client sent 'exit', closing connection...
Thread 139973420377792: Client disconnected.
Message from client: exit
Client sent 'exit', closing connection...
Thread 139973428770496: Client disconnected.
*/
