# **socket_programming**

## 简介

socket programming with C++

计算机网络课程设计

基于linux平台编写

通过面向对象的方法对socket的各个api进行了封装

## 实现细节

网络通信时服务器和客户端的功能如图

![img](https://i.loli.net/2021/10/29/wPln9iKv4msQjFc.jpg)

TcpSocket类封装了`socket()`、`connect()`、`send()`、`recv()`函数，用于客户端的socket创建

由于服务端的socket需要调用更多函数，于是设计了子类

TcpServer类继承自TcpSocket类，同时增加了`bind()`、`listen()`、`accept()`函数的封装

