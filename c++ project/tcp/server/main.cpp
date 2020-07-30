#include <bits/stdc++.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <arpa/inet.h>

using namespace std;

#define SERV_PORT 9527
#define buffersize 1024
typedef int SOCKET;

void sys_err(const char *err_str){
	perror(err_str);
	exit(1);
}

int main(){
	int send_len = 0;
	int recv_len = 0;
	const int len = sizeof(sockaddr);

	char send_buf[buffersize];
	char recv_buf[buffersize];

	SOCKET s_server;
	SOCKET s_accept;

	sockaddr_in server_addr;
	sockaddr_in accept_addr;

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr.s_addr);

	s_server = socket(AF_INET, SOCK_STREAM, 0);
	if (s_server == -1){
		sys_err("socket error");
	}
	
	if (bind(s_server, (sockaddr*)&server_addr, len) == -1){
		sys_err("bind error");
	}

	if (listen(s_server, 128) < 0){
		sys_err("listen error");
	}

	s_accept = accept(s_server, (sockaddr*)&accept_addr, (socklen_t*)&len);
	if (s_accept == -1){
		sys_err("accept error");
	}

	while (1){
		recv_len = recv(s_accept, recv_buf, buffersize, 0);
		if (recv_len < 0){
			cout << "receive failed!" << endl;
			break;
		} else {
			cout << "clien message:" << recv_buf << endl; 
		}
		cout << "Input response message:";
		cin >> send_buf;
		send_len = send(s_accept, send_buf, sizeof(send_buf), 0);
		if (send < 0){
			cout << "send failed!" << endl;
			break;
		}
	}
	
	close(s_server);
	close(s_accept);
	return 0;
}