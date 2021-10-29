#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>

using namespace std;
#define PORT 8888

class TcpSocket
{
public:
    TcpSocket();
    TcpSocket(int socket);
    ~TcpSocket();
    int connectToHost(string ip, unsigned short port);
    int sendMsg(string msg);
    string recvMsg();
    //下面是没有封装过的函数
    // int connectToHost(int fd, const char* ip, unsigned short port);
    // int sendMsg(int fd, const char* msg);
    // int recvMsg(int fd, char* msg, int size);
    // int createSocket();
    // int closeSocket(int fd);
    
protected:
    int readn(char* buf, int size);
    int writen(const char* msg, int size);
    // int readn(int fd, char* buf, int size);
    // int writen(int fd, const char* msg, int size);

    int socket_fd;	// 通信的套接字
};

class 


#endif