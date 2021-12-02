/**
 * @file tcpsocket.h
 * @author wuyifff (wuyifff@qq.com)
 * @brief 
 * @date 2021-10-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <fcntl.h>
#include <string>
#include <iostream>

using namespace std;
// #define PORT 8888

class TcpSocket
{
public:
    TcpSocket();
    TcpSocket(int socket);
    ~TcpSocket();
    int connectToHost(string ip, unsigned short port);
    int sendMsg(string msg);
    string recvMsg();
    
protected:
    int readn(char* buf, int size);
    int writen(const char* msg, int size);

    int socket_fd;	// 通信的套接字
};

#endif