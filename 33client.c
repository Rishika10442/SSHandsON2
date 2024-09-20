/*============================================================================
Name : 33client.c
Author : Rishika Gupta
Date: 20/9/24*/

//33. Write a program to communicate between two machines using socket.
////============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *msg = "Hello from client";
    char buff[1024] = {0};

   
   sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

   
  

    
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

   
    send(sock, msg, strlen(msg), 0);
    printf("Hello message sent to server\n");

    
    read(sock, buff, 1024);
    printf("Message from server: %s\n", buff);

    
    close(sock);

    return 0;
}
//============================================================================
/*Hello message sent to server
Message from server: Hello from server
*/
