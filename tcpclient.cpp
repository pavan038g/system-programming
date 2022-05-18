//The program to create a tcp  Client
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define ADDRSERV "127.0.0.1"
#define PORTNO 8022
#define MAX 256
using namespace std;

int main()
{
        struct sockaddr_in servaddr;
        char cmsg[MAX] = "Hi server this msg your reciving from client";
        char smsg[MAX];
        int sockfd,mlen,structlen;
        socklen_t servaddrlen;
        structlen = sizeof(sockaddr_in);
        memset(&servaddr,0,structlen);
        memset(smsg,0,MAX);
        servaddr.sin_family = AF_INET; // use of Internet family  Addressing
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        servaddr.sin_port = htons(PORTNO);

        sockfd = socket(AF_INET,SOCK_STREAM,0);
        connect(sockfd,(struct sockaddr *) &servaddr,structlen);

        mlen=send(sockfd,cmsg,strlen(cmsg),0);
        cout << mlen << " Bytes Message Sent from The Client to Server" << endl;
        mlen=recv(sockfd,smsg,MAX,0);
        cout << smsg << endl;
        close(sockfd);
}
