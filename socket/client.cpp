/**
 * @file client.cpp
 * @author wuyifff (wuyifff@qq.com)
 * @brief 
 * @date 2021-10-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "tcpsocket.h"
#include "tcpserver.h"

int main()
{
    // 1. 创建通信的套接字
    TcpSocket client;

    // 2. 连接服务器IP port
    int ret = client.connectToHost("0.0.0.0", 8888);
    if (ret == -1)
    {
        return -1;
    }

    // 3. 通信
    string buf;
    while(1)
    {
        cin >> buf;
        client.sendMsg(buf);
        // 回传
        string temp;
        temp = client.recvMsg();
        cout << "receive msg from server \n" << temp << endl;
        if( buf == string("exit") )
        {
            printf("exit client in 5s!\n");
            break;
        }
        else
            buf.clear();
    }

    for(int i = 4; i > 0; --i)
    {
        printf("%d\n", i);
        sleep(1);
        i = i-2;
    }

    return 0;
}