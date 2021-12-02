/**
 * @file tcpserver.h
 * @author wuyifff (wuyifff@qq.com)
 * @brief 
 * @date 2021-10-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "tcpsocket.h"


class TcpServer : public TcpSocket
{
public:
    int setListen(unsigned short port);
    TcpSocket* acceptConnect(sockaddr_in* addr);
};

#endif