#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE];

    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return 1;
    }

    
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection to server failed");
        return 1;
    }

    printf("Connected to the server. Type your message:\n");

    while (1) {
    
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = 0;

        
        send(sock, message, strlen(message), 0);

        
        int valread = read(sock, buffer, sizeof(buffer) - 1);
        if (valread > 0) {
            buffer[valread] = '\0';
            printf("Server: %s\n", buffer);
        }

        
        if (strcmp(message, "exit") == 0) {
            break;
        }
    }

   
    close(sock);
    return 0;
}
/*
client 1
Connected to the server. Type your message:
sdf
Server: Hello from the server, received your message
ad
Server: Hello from the server, received your message
jhk
Server: Hello from the server, received your message
exit

client2
Connected to the server. Type your message:
heyy
Server: Hello from the server, received your message
ad
Server: Hello from the server, received your message
exit
*/

