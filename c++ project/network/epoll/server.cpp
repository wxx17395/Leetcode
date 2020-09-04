#include <bits/stdc++.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

using namespace std;

#define SERV_PORT 9527
#define OPEN_MAX 100
void sys_err(const char *err_str){
	perror(err_str);
	exit(1);
}

int main(){
	int i, j, listenfd, connfd, sockfd;
    int n, num = 0;
    ssize_t nready, efd, res;
    char buf[BUFSIZ], str[INET_ADDRSTRLEN];
    socklen_t clilen;

    sockaddr_in clt_addr, serv_addr;

    epoll_event tep, ep[OPEN_MAX];

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(SERV_PORT);
    bind(listenfd, (sockaddr*) &serv_addr, sizeof(serv_addr));
    listen(listenfd, 128);

    efd = epoll_create(OPEN_MAX);
    tep.events = EPOLLIN;
    tep.data.fd = listenfd;

    res = epoll_ctl(efd, EPOLL_CTL_ADD, listenfd, &tep);

    cout << "start listening" << endl;
    while(1){
        nready = epoll_wait(efd, ep, OPEN_MAX, -1);
        if (nready < 0){
            sys_err("select error");
        }
        for (i = 0; i < nready; ++i){
            if (!(ep[i].events & EPOLLIN)){
                continue;
            }
            if (ep[i].data.fd = listenfd){
                clilen = sizeof(clt_addr);
                connfd = accept(listenfd, (sockaddr*)&clt_addr, &clilen);

                printf("reveived from %s at port %d\n", inet_ntop(AF_INET, &clt_addr.sin_addr, str, sizeof(str)), ntohs(clt_addr.sin_port));
                printf("cfd %d--client %d\n", connfd, ++num);
                tep.events = EPOLLIN;
                tep.data.fd = connfd;
                res = epoll_ctl(efd, EPOLL_CTL_ADD, connfd, &tep);
                
            } else {
                sockfd = ep[i].data.fd;
                n = read(sockfd, buf, BUFSIZ);
                if (n == 0){
                    res = epoll_ctl(efd, EPOLL_CTL_DEL, sockfd, NULL);
                    close(sockfd);
                    printf("client[%d] closed", sockfd);
                } else {
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