/**
 * @file server.cpp
 * @author wuyifff (wuyifff@qq.com)
 * @brief 
 * @date 2021-10-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "tcpserver.h"
#include "tcpsocket.h"

struct SockInfo
{
    TcpServer* server;
    TcpSocket* tcp;
    struct sockaddr_in addr;
};

void* working(void* arg)
{
    struct SockInfo* pinfo = static_cast<struct SockInfo*>(arg);
    // 连接建立成功, 打印客户端的IP和端口信息
    char ip[32];
    printf("客户端的IP: %server, 端口: %d\n",
        inet_ntop(AF_INET, &pinfo->addr.sin_addr.s_addr, ip, sizeof(ip)),
        ntohs(pinfo->addr.sin_port));

    // 5. 通信
    while (1)
    {
        // printf("接收数据: .....\n");
        string msg = pinfo->tcp->recvMsg();
        if (!msg.empty())
        {
            cout << msg << endl;
            pinfo->tcp->sendMsg(msg);    //回传
        }
        else
        {
            break;
        }
    }
    delete pinfo->tcp;
    delete pinfo;
    return nullptr;
}

int main()
{
    // 1. 创建监听的套接字
    TcpServer server;
    // 2. 绑定本地的IP port并设置监听
    server.setListen(8888);
    // 3. 阻塞并等待客户端的连接
    while (1)
    {
        SockInfo* info = new SockInfo;
        TcpSocket* tcp = server.acceptConnect(&info->addr);
        if (tcp == nullptr)
        {
            cout << "重试...." << endl;
            sleep(1);
            continue;
        }
        // 创建子线程
        pthread_t tid;
        info->server = &server;
        info->tcp = tcp;

        pthread_create(&tid, NULL, working, info);
        pthread_detach(tid);
    }

    return 0;
}