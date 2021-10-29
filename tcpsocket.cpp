#include "tcpsocket.h"

TcpSocket::TcpSocket()
{
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        perror("socket create error");
    else
        printf("tcp socket init with file discriptor %d\n", socket_fd);
}

TcpSocket::TcpSocket(int socket)
{
    if ((socket_fd = socket) == -1)
        perror("socket assignment error");
    else
        printf("tcp socket init with file discriptor %d\n", socket_fd);
}

TcpSocket::~TcpSocket()
{
    if( (close(socket_fd) == -1) )
        perror("socket close error");
}

int TcpSocket::connectToHost(string ip, unsigned short port)
{
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(PORT);
    //inet_pton中p和n分别代表表达（presentation)和数值（numeric)
    inet_pton(AF_INET, ip.data(), &saddr.sin_addr.s_addr);
    int ret = connect(socket_fd, (struct sockaddr *)&saddr, sizeof(saddr));
    if(ret == -1)
    {
        perror("connect");
        return -1;
    }
    printf("成功与服务器(ip:%s)建立连接！\n", ip.data());
    return ret;
}

int TcpSocket::sendMsg(string msg)
{
    char *data = new char[msg.size() + 4];
    int msglen = htonl(msg.size());
    memcpy(data, &msglen, 4);
    memcpy(data + 4, msg.data(), msg.size());
    int ret = writen(data, msg.size() + 4);
    delete[] data;
    return ret;
}

string TcpSocket::recvMsg()
{
    int len = 0;
    readn( (char*)&len, 4);
    len = ntohl(len);
    printf("收到数据，数据大小%d", len);
    char *buf = new char [len + 1];
    int ret = readn(buf, len);
    if(ret != len)
    {
        printf("can't read all\n");
        return string();
    }
    buf[len] = '\0';
    string retbuf(buf);
    delete[] buf;
    return retbuf;
}

int TcpSocket::readn(char *buf, int size)
{
    int readnow;
    int left = size;
    char *p = buf;
    while(left)
    {
        if( (readnow = read(socket_fd, p, left)) > 0 )
        {
            p = p + readnow;
            left -= readnow;
        }
        else if( readnow == -1 )
        {
            perror("read error");
            return -1;
        }
    }
    return size;
}

int TcpSocket::writen(const char* msg, int size)
{
    int left = size;
    int writenow;
    const char *p = msg;
    while(left)
    {
        if( (writenow = write(socket_fd, p, left)) > 0 )
        {
            p = p - writenow;
            left -= writenow;
        }
        else if( writenow == -1 )
        {
            perror("write error");
            return -1;
        }
    }
    return size;
}