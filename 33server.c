/*
============================================================================
Name : 33server.c
Author : Rishika Gupta
Date: 20/9/24
33. Write a program to communicate between two machines using socket.*/
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sfd, ns;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buff[1024] = {0};
    char *msg = "Hello from server";

  
    (sfd = socket(AF_INET, SOCK_STREAM, 0));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);


    bind(sfd, (struct sockaddr *)&address, sizeof(address));

    
   listen(sfd, 5);

    printf("Server is listening on port %d\n", PORT);

    
    ns = accept(sfd, (struct sockaddr *)&address, (socklen_t*)&addrlen); 

    
    read(ns, buff, 1024);
    printf("Message from client: %s\n", buff);

    
    send(ns, msg, strlen(msg), 0);
    printf("Hello message sent to client\n");

    
    close(ns);
    close(sfd);

    return 0;
}
//============================================================================
/*Server is listening on port 8080
Message from client: Hello from client
Hello message sent to client
*/

