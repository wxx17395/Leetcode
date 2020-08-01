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

	sockaddr_in server_addr;

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr.s_addr);

	s_server = socket(AF_INET, SOCK_STREAM, 0);
	if (s_server == -1){
		sys_err("socket error");
	}
	
	if (connect(s_server, (sockaddr*) &server_addr, sizeof(sockaddr)) == -1){
        sys_err("connect error");
    }

    cout << "connect succeed" << endl;
	while (1){
        cout << "Input send message:";
		cin >> send_buf;
		send_len = send(s_server, send_buf, sizeof(send_buf), 0);
		if (send < 0){
			cout << "send failed!" << endl;
			break;
		}
		recv_len = recv(s_server, recv_buf, buffersize, 0);
		if (recv_len < 0){
			cout << "receive failed!" << endl;
			break;
		} else {
			cout << "clien message:" << recv_buf << endl; 
		}
	}
	
	close(s_server);
	return 0;
}