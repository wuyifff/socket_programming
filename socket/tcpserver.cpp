/**
 * @file tcpserver.cpp
 * @author wuyifff (wuyifff@qq.com)
 * @brief 
 * @date 2021-10-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "tcpserver.h"

int TcpServer::setListen(unsigned short port)
{
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);
    saddr.sin_addr.s_addr = INADDR_ANY;  // 0 = 0.0.0.0
    int ret = bind(socket_fd, (struct sockaddr*)&saddr, sizeof(saddr));
    if (ret == -1)
    {
        perror("server bind error");
        return -1;
    }
    cout << "套接字绑定成功, ip: "
        << inet_ntoa(saddr.sin_addr)
        << ", port: " << port << endl;

    ret = listen(socket_fd, 128);
    if (ret == -1)
    {
        perror("server listen error");
        return -1;
    }
    cout << "设置监听成功..." << endl;

    return ret;
}

TcpSocket* TcpServer::acceptConnect(sockaddr_in* addr)
{
    if (addr == NULL)
    {
        return nullptr;
    }

    socklen_t addrlen = sizeof(struct sockaddr_in);
    int cfd = accept(socket_fd, (struct sockaddr*)addr, &addrlen);
    if (cfd == -1)
    {
        perror("accept");
        return nullptr;
    }
    printf("成功和客户端建立连接...\n");
    return new TcpSocket(cfd);
}