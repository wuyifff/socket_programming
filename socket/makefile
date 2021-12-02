src = tcpserver.cpp tcpsocket.cpp  
obj = client.exe server.exe

all: $(obj)

client.exe : $(src) client.cpp
	g++ $+ -o $@ -Wall -std=c++11 -lpthread

server.exe :  $(src) server.cpp
	g++ $+ -o $@ -Wall -std=c++11 -lpthread

.PHONY:clean
clean:
	-rm  -f $(wildcard *.exe)


