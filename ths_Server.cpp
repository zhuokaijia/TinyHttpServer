#include "ths_Server.h"

const int MAX_EVENTS = 2 << 14;
const int MAX_BACKLOG = 2 << 10;
const int TIME_OUT = 4 * 60;

static int ths_thread_num = 0;
pthread_mutex_t ths_thread_num_mutex = PTHREAD_MUTEX_INITIALIZER;

void add_ths_thread_num(){
    pthread_mutex_lock(&ths_thread_num_mutex);
    ths_thread_num++;
    pthread_mutex_unlock(&ths_thread_num_mutex);
}

void minus_ths_thread_num(){
    pthread_mutex_lock(&ths_thread_num_mutex);
    ths_thread_num--;
    pthread_mutex_unlock(&ths_thread_num_mutex);
}

int buildResponseHeader(ths_header& requestHeader, std::string &content){

    char firstLine[256];
    std::string crlf("\r\n");
    std::string date = "Date:" + getSystemTime() + crlf;
    std::string server("Server: tinyhttpServer\r\n");
    std::string content_type("content_type: ");
    std::string last_modified("Last-Modified: ");
    std::string content_length("Content-Length: ");
    std::string method = requestHeader.method;
    std::string path = getPath(requestHeader.url);
    std::string version = requestHeader.version;

    switch (toValue(method)){
    case 1:
        if (isVaildFile(path.c_str())){
            snprintf(firstLine, sizeof(firstLine), "HTTP/1.1 %d %s\r\n",
                200, toString(200));
            content += (firstLine + server + date + crlf);
            content += content_type + "application/octet-stream" + "\r\n";
            int len = getFileSize(path.c_str());
            snprintf(firstLine, sizeof(firstLine), "%d\r\n", len);

            content += content_length + firstLine + "\r\n";
            return 200;
        }
        else{
            snprintf(firstLine, sizeof(firstLine), "HTTP/1.1 %d %s\r\n",
                404, toString(404));
            content += (firstLine + server + date + crlf);
            content += content_length + "0\r\n";
            return 404;
        }
        break;
    case 2:
        if (isVaildFile(path.c_str())){
            snprintf(firstLine, sizeof(firstLine), "HTTP/1.1 %d %s\r\n",
                200, toString(200));
            content += (firstLine + server + date + crlf);
            content += content_type + "application/octet-stream" + "\r\n";
            int len = getFileSize(path.c_str());
            snprintf(firstLine, sizeof(firstLine), "%d\r\n", len);

            content += content_length + firstLine + "\r\n";
            return 200;
        }
        else{
            snprintf(firstLine, sizeof(firstLine), "HTTP/1.1 %d %s\r\n",
                404, toString(404));
            content += (firstLine + server + date + crlf);
            content += content_length + "0\r\n";
            return 404;
        }
        break;
    case 3:
        if (isVaildFile(path.c_str())){
            snprintf(firstLine, sizeof(firstLine), "HTTP/1.1 %d %s\r\n",
                204, toString(204));
            content += (firstLine + server + date + crlf);
            content += content_type + "application/octet-stream" + "\r\n";
            int len = getFileSize(path.c_str());
            snprintf(firstLine, sizeof(firstLine), "%d\r\n", len);

            content += content_length + firstLine + "\r\n";
            return 204;
        }
        else{
            snprintf(firstLine, sizeof(firstLine), "HTTP/1.1 %d %s\r\n",
                201, toString(201));
            content += (firstLine + server + date + crlf);
            content += content_type + "application/octet-stream" + "\r\n";
            content += content_length + "0\r\n";
            return 201;
        }
        break;
    case 4:
        if (isVaildFile(path.c_str())){
            snprintf(firstLine, sizeof(firstLine), "HTTP/1.1 %d %s\r\n",
                204, toString(204));
            content += (firstLine + server + date + crlf);
            content += content_type + "application/octet-stream" + "\r\n";
            int len = getFileSize(path.c_str());
            snprintf(firstLine, sizeof(firstLine), "%d\r\n", len);

            content += content_length + firstLine + "\r\n";
            return 204;
        }
        else{
            snprintf(firstLine, sizeof(firstLine), "HTTP/1.1 %d %s\r\n",
                201, toString(201));
            content += (firstLine + server + date + crlf);
            content += content_type + "application/octet-stream" + "\r\n";
            content += content_length + "0\r\n";
            return 201;
        }
        break;
    case 5:
        if (isVaildFile(path.c_str())){
            snprintf(firstLine, sizeof(firstLine), "HTTP/1.1 %d %s\r\n",
                200, toString(200));
            content += (firstLine + server + date + crlf);
            content += content_type + "application/octet-stream" + "\r\n";
            int len = getFileSize(path.c_str());
            snprintf(firstLine, sizeof(firstLine), "%d\r\n", len);

            content += content_length + firstLine + "\r\n";
            return 200;
        }
        else{
            snprintf(firstLine, sizeof(firstLine), "HTTP/1.1 %d %s\r\n",
                204, toString(204));
            content += (firstLine + server + date + crlf);
            content += content_type + "application/octet-stream" + "\r\n";
            content += content_length + "0\r\n";
            return 204;
        }
        break;
    default:
        snprintf(firstLine, sizeof(firstLine), "HTTP/1.1 %d %s\r\n",
            501, toString(501));
        content += (firstLine + server + date + crlf);

        int len = getFileSize(path.c_str());
        snprintf(firstLine, sizeof(firstLine), "%d\r\n", len);

        content += content_length + firstLine + "\r\n";
        return 501;
    }
}

    std::string toString(int statusCode){
        std::string temp;
        switch (statusCode){
        case 100:
            temp = "Continue";
            break;
        case 101:
            temp = "Switching Protocols";
            break;
        case 102:
            temp = "Processing";
            break;
        case 200:
            temp = "OK";
            break;
        case 201:
            temp = "Created";
            break;
        case 202:
            temp = "Accepted";
            break;
        case 203:
            temp = "Non-Authoritative Information";
            break; 
        case 204:
            temp = "No Content";
            break; 
        case 205:
            temp = "Reset Content";
            break;
        case 206:
            temp = "Partial Content";
            break;
        case 300:
            temp = "Multiple Choices";
            break;
        case 301:
            temp = "Moved Permanently";
            break;
        case 302:
            temp = "Move temporarily";
            break;
        case 303:
            temp = "See Other";
            break;
        case 304:
            temp = "Not Modified";
            break;
        case 305:
            temp = "Use Proxy";
            break;
        case 307:
            temp = "Temporary Redirect";
            break;
        case 400:
            temp = "Bad Request";
            break;
        case 401:
            temp = "Unauthorized";
            break;
        case 402:
            temp = "Payment Required";
            break;
        case 403:
            temp = "Forbidden";
            break;
        case 404:
            temp = "Not Found";
            break;
        case 405:
            temp = "Method Not Allowed";
            break;
        case 406:
            temp = "Not Acceptable";
            break;
        case 501:
            temp = "Not Implemented";
            break;
        case 502:
            temp = "Bad Gateway";
            break;
        default:
            temp = "HTTP Version Not Supported";

        }
        return temp;
    }


int toValue(std::string &method){
    if (method == "GET"){
        return 1;
    }
    else if (method == "HEAD"){
        return 2;
    }
    else if (method == "PUT"){
        return 3;
    }
    else if (method == "DELETE"){
        return 4;
    }
    else if (method == "POST"){
        return 5;
    }
    else{
        return 6;
    }

    return 0;
}

void *ths_thread_proc(void* param){
    ths_header* pheader = new ths_header;
    assert(pheader != nullptr);
    add_ths_thread_num();

    ths_thread_args* pargs = static_cast<ths_thread_args*>(param);
    int connfd = pargs->connfd;
    struct epoll_event ths_ev;
    ths_ev.events = EPOLLIN;
    ths_ev.data.fd = connfd;

    int epollfd = ths_epoll_create(2);
    ths_epoll_ctl(epollfd, EPOLL_CTL_ADD, connfd, &ths_ev);
    pthread_t ptid = pthread_self();

    char* buff = new char[(2 << 20)];
    memset(buff, 0, sizeof(0));

    setOnNagle(ths_ev.data.fd);

    timeval recv_time;
    recv_time.tv_sec = 60;
    recv_time.tv_usec = 0;
    int ret = setsockopt(connfd, SOL_SOCKET, SO_SNDTIMEO, &recv_time, sizeof(recv_time));
    if (ret == -1)
    {
        perror("errSource: setsockopt");
        exit(-1);
    }
    begin:
    int alread = 0,n=0;
    for (;;){
        if ((n = read(connfd, buff + alread, 2 << 20 - 1)) > 0||(n==-1&&errno==EINTR)){
            alread += n;
        }
        else{
            exit(-1);
        }
    }

    if (alread != 0){
        std::string s(buff, buff + alread);
        if (request_parse(s, *pheader)){
            std::string content;
            int typeCode = buildResponseHeader(*pheader, content);
            char* out = (char*)malloc(sizeof(s.length()));
            for (int i = 0; i < s.length(); i++){
                out[i] = s[i];
            }
            int alwrite = 0, m = 0;
            if (pheader->method == "GET"&&typeCode==200){
                while ((m = write(connfd, out + alwrite, s.length()))){
                    alwrite += m;
                }
                std::string ths_url = getPath(pheader->url);
                int fd = open(ths_url.c_str(), O_RDONLY);
                int size = getFileSize(ths_url.c_str());
                int nwrite = 0;
                while (nwrite < size){
                    sendfile(connfd, fd, (off_t*)&nwrite, size);
                }
            }
            else{
                while ((m = write(connfd, out + alwrite, s.length()))){
                    alwrite += m;
                }
            }
            free(out);
            out = nullptr;
        }
        
        epoll_event event[2];

        int nfd = ths_epoll_wait(epollfd, event, 2, TIME_OUT);
        if (nfd != 0){
            for (int i = 0; i < nfd; i++){
                if (event[i].data.fd == connfd){
                    goto begin;
                }
                else{
                    break;
                }
            }
        }


    }
    delete pheader;
    close(connfd);
    minus_ths_thread_num();
}

int main(int argc, char const *argv[])
{
    int 			listen_fd;
    int 			conn_sock;
    int 			nfds;
    int 			epollfd;
    uint16_t 			listen_port;
    struct servent 		*pservent;
    struct epoll_event 	ev;
    struct epoll_event	events[MAX_EVENTS];
    struct sockaddr_in 	server_addr;
    struct sockaddr_in	client_addr;
    socklen_t 			addrlen;
    pthread_attr_t		pthread_attr_detach;
    ths_thread_args 	epollfd_connfd;
    pthread_t 			tid;

 


    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    setNoBlocking(listen_fd);


    pservent = getservbyname("http", "tcp");
   
    if (pservent == nullptr){
        perror("errSource: getservbyname");
        exit(-1);
    }
    listen_port = pservent->s_port;

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = (listen_port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);


    ths_bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
 
    ths_listen(listen_fd, MAX_BACKLOG);

    
    epollfd = ths_epoll_create(MAX_EVENTS);

    ev.events = EPOLLIN;
    ev.data.fd = listen_fd;
   
    ths_epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_fd, &ev);

    
    pthread_attr_init(&pthread_attr_detach);
    pthread_attr_setdetachstate(&pthread_attr_detach, PTHREAD_CREATE_DETACHED);

    for (;;)
    {
        
        nfds = ths_epoll_wait(epollfd, events, MAX_EVENTS, -1);
        
        if (nfds == -1 && errno == EINTR)
            continue;

        for (int n = 0; n != nfds; ++n)
        {
            
            if (events[n].data.fd == listen_fd)
            {
                conn_sock = ths_accept(listen_fd, (struct sockaddr*)&client_addr, &addrlen);
              
                setNoBlocking(conn_sock);
                
                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = conn_sock;
               
                ths_epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &ev);
            }
            else
            {
                epollfd_connfd.epollfd = epollfd;
                epollfd_connfd.connfd = events[n].data.fd;
                ev.data.fd = conn_sock;
                
                ths_epoll_ctl(epollfd, EPOLL_CTL_DEL, conn_sock, &ev);
                
                pthread_create(&tid, &pthread_attr_detach, ths_thread_proc, static_cast<void*>(&epollfd_connfd));
                
            }
        }
    }
    pthread_attr_destroy(&pthread_attr_detach);

    close(listen_fd);
    return 0;
}
