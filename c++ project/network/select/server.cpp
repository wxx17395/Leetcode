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

void sys_err(const char *err_str){
	perror(err_str);
	exit(1);
}

int main(){
	int i, j, n, nready;
    int maxfd = 0;

    int listenfd, connfd;

    char buf[BUFSIZ];
    sockaddr_in clt_addr, serv_addr;
    socklen_t clt_addr_len;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(SERV_PORT);
    bind(listenfd, (sockaddr*) &serv_addr, sizeof(serv_addr));
    listen(listenfd, 128);

    fd_set rset, allset;

    maxfd = listenfd;

    FD_ZERO(&allset);
    FD_SET(listenfd, &allset);
    cout << "start listening" << endl;
    while(1){
        rset = allset;
        nready = select(maxfd + 1, &rset, NULL, NULL, NULL);
        if (nready < 0){
            sys_err("select error");
        }
        if (FD_ISSET(listenfd, &rset)){
            clt_addr_len = sizeof(clt_addr);
            connfd = accept(listenfd, (sockaddr*)&clt_addr, &clt_addr_len);
            cout << "client :" << connfd << endl;
            FD_SET(connfd, &allset);

            maxfd = max(maxfd, connfd);
            if (0 == --nready){
                continue;
            }
        }
        for (i = listenfd + 1; i <= maxfd; ++i){
            if (FD_ISSET(i, &rset)){
                n = read(i, buf, BUFSIZ);
                if (n == 0){
                    close(i);
                    FD_CLR(i, &allset);
                } else if (n > 0) {
                    cout << "received client message:" << buf << endl;
                    for (j = 0; j < strlen(buf); ++j){
                        buf[j] = toupper(buf[j]);                        
                    }
                    write(i, buf, strlen(buf) + 1);
                }
            }
        }
    }
    close(listenfd);
}