#ifndef _THS_SERVER_H_
#define _THS_SERVER_H_

#include  <iostream>
#include  <string>
#include  <sys/socket.h>
#include  <sys/types.h>
#include  <errno.h>
#include  <pthread.h>
#include  <cassert>
#include  <netdb.h>
#include  <ctime>
#include  <map>
#include  <sys/stat.h>
#include  <sstream>
#include  <cstddef>
#include  <netinet/in.h>
#include  <sys/sendfile.h>
#include  "ths_utility.h"
#include  "ths_request_parse.h"

struct ths_thread_args{
    int epollfd;
    int connfd;
};

extern std::map<std::string, std::string> MIME;

int buildResponseHeader(ths_header&, std::string &content);

// for switch
int toValue(std::string &method);

std::string toString(int statusCode);

void *ths_thread_proc(void* param);

#endif
