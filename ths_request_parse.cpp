#include "ths_request_parse.h"

std::string ths_domain="";
std::string ths_root="";

bool request_parse(const std::string& httpRequest, ths_header& content){
    if (httpRequest.empty()){
        perror("errSource: request_parse | httpRequest is NULL !");
        return false;
    }

    std::string crlf("\r\n"), dcrlf("\r\n\r\n");
    int pre = 0, next = 0;

    //parse request header
    if ((next = httpRequest.find(crlf, pre)) != std::string::npos){
        std::string firstLine(httpRequest.substr(pre, next));
        std::stringstream ss (firstLine);
        ss >> content.method;
        ss >> content.url;
        ss >> content.version;
        pre = next;
    }
    else{
        perror("errSource: request_parse | httpRequest is invaild !");
        return false;
    }

    //parse message header
    int pos;
    if ((pos = httpRequest.find(dcrlf, pre)) != std::string::npos){
        std::string key, value, buf;
        for ( ; ; ){
            // skip \r\n
            pre += 2;
            next = httpRequest.find(crlf, pre);
            if (next <= pos){
                buf = httpRequest.substr(pre, next - pre);
                int end = 0;
                int begin = 0;
                while (buf[end] != ':'){
                    end++;

                }
                key = httpRequest.substr(begin, end - begin);
                begin = end;
                while (isalpha(buf[end]) && isdigit(buf[end])){
                    end++;
                }
                value = httpRequest.substr(begin, end - begin);
                pre = next;
                content.vec.push_back(make_pair(key, value));
            }
        }
    }
    else{
        perror("errSource: request_parse | httpRequest is invaild !");
        return false;
    }
    
    //parse request body
    pos += 4;
    content.body = httpRequest.substr(pos, sizeof(httpRequest) - pos);

    return true;
}

std::string getPath(const std::string& url){
    std::string realPath, path;
    int pos = 0;
    if ((pos = url.find(ths_domain, 0)) != std::string::npos){
        path = url.substr(ths_domain.length(), url.length() - ths_domain.length());
    }
    else{
        path = url;
    }
    int len = path.length() - 1;
    realPath = ths_root + path.substr(1,len);
    if (ths_root == ""){
        perror("errSource: getPath | invaild root path");
        exit(-1);
    }
    return realPath;
}
