#include "tcpsocket.h"

int main()
{
    TcpSocket server;
    string ip = "127.0.0.0";
    server.connectToHost(ip, 8888);
}