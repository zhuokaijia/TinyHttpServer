#ifndef _THS_UTILITY_H_
#define _THS_UTILITY_H_

#include  <sys/socket.h>
#include <sys/epoll.h>
#include  <sys/types.h>
#include  <string>
#include  <iostream>
#include  <sys/stat.h>
#include  <fcntl.h>
#include  <cstdio>
#include  <time.h>
#include  <cstdlib>
#include  <unistd.h>
#include  <cstring>
#include  <map>
#include  <errno.h>
#include  <netinet/tcp.h>

// utility fuctions

//get system tine
std::string getSystemTime();

//return -1 iff the file is not exist
inline int isVaildFile(const char* path){
    int res = open(path, O_RDONLY | O_EXCL);
    close(res);
    return res;
}

//get the file's size
int getFileSize(const char* path);

//get the last modified time
std::string getLastModefiedTime(const char* path);

//init the MIME
void init_MIME(std::map<std::string, std::string>& m);

std::string get_MIME_value(std::string& , std::map<std::string, std::string>& );

// set off TCP_NODELAY
void setOffNagle(int sockfd);

// set on TCP_NODELAY
void setOnNagle(int sockfd);

void setNoBlocking(int sockfd);

void ths_listen(int sockfd, int backlog);
void ths_bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int ths_accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

int ths_epoll_create(int size);
int ths_epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
int ths_epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);


#endif
