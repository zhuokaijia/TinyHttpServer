#include "ths_utility.h"

std::string getSystemTime(){
    //get localtime
    time_t cur;
    time(&cur);
    tm curTime = *localtime(&cur);

    //constructing time string
    std::string sysTime;
    switch (curTime.tm_wday)
    {
    case 0:
        sysTime += "Sun, ";
        break;
    case 1:
        sysTime += "Mon, ";
        break;
    case 2:
        sysTime += "Tue, ";
        break;
    case 3:
        sysTime += "Wed, ";
        break;
    case 4:
        sysTime += "Thu, ";
        break;
    case 5:
        sysTime += "Fri, ";
        break;
    case 6:
        sysTime += "Sat, ";
        break;
    }
    char buf[16];
    snprintf(buf, sizeof(buf), "%d ", curTime.tm_mday);
    sysTime += std::string(buf);
    switch (curTime.tm_mon)
    {
    case 0:
        sysTime += "Jan ";
        break;
    case 1:
        sysTime += "Feb ";
        break;
    case 2:
        sysTime += "Mar ";
        break;
    case 3:
        sysTime += "Apr ";
        break;
    case 4:
        sysTime += "May ";
        break;
    case 5:
        sysTime += "Jun ";
        break;
    case 6:
        sysTime += "Jul ";
        break;
    case 7:
        sysTime += "Aug ";
        break;
    case 8:
        sysTime += "Sep ";
        break;
    case 9:
        sysTime += "Oct ";
        break;
    case 10:
        sysTime += "Nov ";
        break;
    case 11:
        sysTime += "Dec ";
        break;
    }
    snprintf(buf, sizeof(buf), "%d", curTime.tm_year + 1900);
    sysTime += std::string(buf);
    snprintf(buf, sizeof(buf), " %d:%d:%d ", curTime.tm_hour, curTime.tm_min, curTime.tm_sec);
    sysTime += std::string(buf);
    sysTime += "GMT";
    return sysTime;
}

int getFileSize(const char* path){
    struct stat path_stat;
    int res = stat(path, &path_stat);
    if (res != 0){
        perror("errSource: getFileSize");
        exit(-1);
    }
    else{
        return path_stat.st_size;
    }
}

std::string getLastModefiedTime(const char* path){
    struct stat path_stat;
    int res = stat(path, &path_stat);
    if (res != 0){
        perror("errSource: getLastModefiedTime");
        exit(-1);
    }
    else{
        char s[64];
        snprintf(s, sizeof(s), "%s", ctime(&path_stat.st_mtime));
        return std::string(s, s + strlen(s));
    }
}

void init_MIME(std::map<std::string, std::string>& m){
    m[".*"] = "application/octet-stream";
    m[".323"] = "text/h323";
    m[".acx"] = "application/internet-property-stream";
    m[".ai"] = "application/postscript";
    m[".aif"] = "audio/x-aiff";
    m[".aifc"] = "audio/x-aiff";
    m[".aiff"] = "audio/x-aiff";
    m[".asf"] = "video/x-ms-asf";
    m[".asr"] = "video/x-ms-asf";
    m[".asx"] = "video/x-ms-asf";
    m[".au"] = "audio/basic";
    m[".avi"] = "video/x-msvideo";
    m[".axs"] = "application/olescript";
    m[".bas"] = "text/plain";
    m[".bcpio"] = "application/x-bcpio";
    m[".bin"] = "application/octet-stream";
    m[".bmp"] = "image/bmp";
    m[".c"] = "text/plain";
    m[".cat"] = "application/vnd.ms-pkiseccat";
    m[".cdf"] = "application/x-cdf";
    m[".cer"] = "application/x-x509-ca-cert";
    m[".class"] = "application/octet-stream";
    m[".clp"] = "application/x-msclip";
    m[".cmx"] = "image/x-cmx";
    m[".cod"] = "image/cis-cod";
    m[".cpio"] = "application/x-cpio";
    m[".crd"] = "application/x-mscardfile";
    m[".crl"] = "application/pkix-crl";
    m[".crt"] = "application/x-x509-ca-cert";
    m[".csh"] = "application/x-csh";
    m[".css"] = "text/css";
    m[".dcr"] = "application/x-director";
    m[".der"] = "application/x-x509-ca-cert";
    m[".dir"] = "application/x-director";
    m[".dll"] = "application/x-msdownload";
    m[".dms"] = "application/octet-stream";
    m[".doc"] = "application/msword";
    m[".dot"] = "application/msword";
    m[".dvi"] = "application/x-dvi";
    m[".dxr"] = "application/x-director";
    m[".eps"] = "application/postscript";
    m[".etx"] = "text/x-setext";
    m[".evy"] = "application/envoy";
    m[".exe"] = "application/octet-stream";
    m[".fif"] = "application/fractals";
    m[".flr"] = "x-world/x-vrml";
    m[".gif"] = "image/gif";
    m[".gtar"] = "application/x-gtar";
    m[".gz"] = "application/x-gzip";
    m[".h"] = "text/plain";
    m[".hdf"] = "application/x-hdf";
    m[".hlp"] = "application/winhlp";
    m[".hqx"] = "application/mac-binhex40";
    m[".hta"] = "application/hta";
    m[".htc"] = "text/x-component";
    m[".htm"] = "text/html";
    m[".html"] = "text/html";
    m[".htt"] = "text/webviewhtml";
    m[".ico"] = "image/x-icon";
    m[".ief"] = "image/ief";
    m[".iii"] = "application/x-iphone";
    m[".ins"] = "application/x-internet-signup";
    m[".isp"] = "application/x-internet-signup";
    m[".jfif"] = "image/pipeg";
    m[".jpe"] = "image/jpeg";
    m[".jpeg"] = "image/jpeg";
    m[".jpg"] = "image/jpeg";
    m[".js"] = "application/x-javascript";
    m[".latex"] = "application/x-latex";
    m[".lha"] = "application/octet-stream";
    m[".latex"] = "application/x-latex";
    m[".lha"] = "application/octet-stream";
    m[".lsf"] = "video/x-la-asf";
    m[".lsx"] = "video/x-la-asf";
    m[".lzh"] = "application/octet-stream";
    m[".m13"] = "application/x-msmediaview";
    m[".m14"] = "application/x-msmediaview";
    m[".m3u"] = "audio/x-mpegurl";
    m[".man"] = "application/x-troff-man";
    m[".mdb"] = "application/x-msaccess";
    m[".me"] = "application/x-troff-me";
    m[".mht"] = "message/rfc822";
    m[".mhtml"] = "message/rfc822";
    m[".mid"] = "audio/mid";
    m[".mny"] = "application/x-msmoney";
    m[".mov"] = "video/quicktime";
    m[".movie"] = "video/x-sgi-movie";
    m[".mp2"] = "video/mpeg";
    m[".mp3"] = "audio/mpeg";
    m[".mpa"] = "video/mpeg";
    m[".mpe"] = "video/mpeg";
    m[".mpeg"] = "video/mpeg";
    m[".mpg"] = "video/mpeg";
    m[".mpp"] = "application/vnd.ms-project";
    m[".mpv2"] = "video/mpeg";
    m[".ms"] = "application/x-troff-ms";
    m[".mvb"] = "application/x-msmediaview";
    m[".nws"] = "message/rfc822";
    m[".oda"] = "application/oda";
    m[".p10"] = "application/pkcs10";
    m[".p12"] = "application/x-pkcs12";
    m[".p7b"] = "application/x-pkcs7-certificates";
    m[".p7c"] = "application/x-pkcs7-mime";
    m[".p7m"] = "application/x-pkcs7-mime";
    m[".p7r"] = "application/x-pkcs7-certreqresp";
    m[".p7s"] = "application/x-pkcs7-signature";
    m[".pbm"] = "image/x-portable-bitmap";
    m[".pdf"] = "application/pdf";
    m[".pfx"] = "application/x-pkcs12";
    m[".pgm"] = "image/x-portable-graymap";
    m[".pko"] = "application/ynd.ms-pkipko";
    m[".pma"] = "application/x-perfmon";
    m[".pmc"] = "application/x-perfmon";
    m[".pml"] = "application/x-perfmon";
    m[".pmr"] = "application/x-perfmon";
    m[".pmw"] = "application/x-perfmon";
    m[".pnm"] = "image/x-portable-anymap";
    m[".pot"] = "application/vnd.ms-powerpoint";
    m[".ppm"] = "image/x-portable-pixmap";
    m[".pps"] = "application/vnd.ms-powerpoint";
    m[".ppt"] = "application/vnd.ms-powerpoint";
    m[".prf"] = "application/pics-rules";
    m[".ps"] = "application/postscript";
    m[".pub"] = "application/x-mspublisher";
    m[".qt"] = "video/quicktime";
    m[".ra"] = "audio/x-pn-realaudio";
    m[".ram"] = "audio/x-pn-realaudio";
    m[".ras"] = "image/x-cmu-raster";
    m[".rgb"] = "image/x-rgb";
    m[".rmi"] = "audio/mid";
    m[".roff"] = "application/x-troff";
    m[".rtf"] = "application/rtf";
    m[".rtx"] = "text/richtext";
    m[".scd"] = "application/x-msschedule";
    m[".sct"] = "text/scriptlet";
    m[".setpay"] = "application/set-payment-initiation";
    m[".setreg"] = "application/set-registration-initiation";
    m[".sh"] = "application/x-sh";
    m[".shar"] = "application/x-shar";
    m[".sit"] = "application/x-stuffit";
    m[".snd"] = "audio/basic";
    m[".spc"] = "application/x-pkcs7-certificates";
    m[".spl"] = "application/futuresplash";
    m[".src"] = "application/x-wais-source";
    m[".sst"] = "application/vnd.ms-pkicertstore";
    m[".stl"] = "application/vnd.ms-pkistl";
    m[".stm"] = "text/html";
    m[".svg"] = "image/svg+xml";
    m[".sv4cpio"] = "application/x-sv4cpio";
    m[".sv4crc"] = "application/x-sv4crc";
    m[".swf"] = "application/x-shockwave-flash";
    m[".t"] = "application/x-troff";
    m[".tar"] = "application/x-tar";
    m[".tcl"] = "application/x-tcl";
    m[".tex"] = "application/x-tex";
    m[".texi"] = "application/x-texinfo";
    m[".texinfo"] = "application/x-texinfo";
    m[".tgz"] = "application/x-compressed";
    m[".tif"] = "image/tiff";
    m[".tiff"] = "image/tiff";
    m[".tr"] = "application/x-troff";
    m[".trm"] = "application/x-msterminal";
    m[".tsv"] = "text/tab-separated-values";
    m[".txt"] = "text/plain";
    m[".uls"] = "text/iuls";
    m[".ustar"] = "application/x-ustar";
    m[".vcf"] = "text/x-vcard";
    m[".vrml"] = "x-world/x-vrml";
    m[".wav"] = "audio/x-wav";
    m[".wcm"] = "application/vnd.ms-works";
    m[".wdb"] = "application/vnd.ms-works";
    m[".wks"] = "application/vnd.ms-works";
    m[".wmf"] = "application/x-msmetafile";
    m[".wps"] = "application/vnd.ms-works";
    m[".wri"] = "application/x-mswrite";
    m[".wrl"] = "x-world/x-vrml";
    m[".wrz"] = "x-world/x-vrml";
    m[".xaf"] = "x-world/x-vrml";
    m[".xbm"] = "image/x-xbitmap";
    m[".xla"] = "application/vnd.ms-excel";
    m[".xlc"] = "application/vnd.ms-excel";
    m[".xlm"] = "application/vnd.ms-excel";
    m[".xls"] = "application/vnd.ms-excel";
    m[".xlt"] = "application/vnd.ms-excel";
    m[".xlw"] = "application/vnd.ms-excel";
    m[".xof"] = "x-world/x-vrml";
    m[".xpm"] = "image/x-xpixmap";
    m[".xwd"] = "image/x-xwindowdump";
    m[".z"] = "application/x-compress";
    m[".zip"] = "application/zip"; 
}

std::string get_MIME_value(std::string& mimeType, std::map<std::string, std::string>& m){
    if (m.find(mimeType) != m.end()){
        return m[mimeType];
    }
    else{
        perror("errSource: get_MIME_value");
        exit(-1);
    }
}

void setNoBlocking(int sockfd){
    int flags = fcntl(sockfd, F_GETFL, 0);
    flags |= O_NONBLOCK;
    int res = fcntl(sockfd, F_SETFL, flags);
    if (res < 0){
        perror("errSource: setNoBlocking");
        exit(-1);
    }

}


void setOffNagle(int sockfd){
    int off = 0, res = 0;
    if ((res = setsockopt(sockfd, SOL_TCP, TCP_CORK, &off, sizeof(off))) != 0){
        perror("errSource: setOffNagle");
        exit(-1);
    }
}

void setOnNagle(int sockfd){
    int on = 1, res = 0;
    if ((res = setsockopt(sockfd, SOL_TCP, TCP_CORK, &on, sizeof(on))) != 0){
        perror("errSource: setOffNagle");
        exit(-1);
    }
}

void ths_listen(int sockfd, int backlog){
    if (listen(sockfd, backlog) == -1){
        perror("errSource: listen");
        exit(-1);
    }
}

void ths_bind(int sockfd, const sockaddr *addr, socklen_t addrlen){
    if (bind(sockfd, addr, addrlen) == -1){
        perror("errSource: bind");
        exit(-1);
    }
}

int ths_accept(int sockfd, sockaddr *addr, socklen_t *addrlen){
    int fd = 0;
    for (;;){
        fd = accept(sockfd, addr, addrlen);
        if (fd > 0){
            break;
        }
        if (errno == EINTR){
            continue;
        }
        else{
            perror("errSource: accept");
            exit(-1);
        }
    }
    return fd;
}

int ths_epoll_create(int size){
    int fd = 0;
    if ((fd = epoll_create(size)) == -1){
        perror("errSource: epoll_creat");
        exit(-1);
    }
    return fd;
}

int ths_epoll_ctl(int epfd, int op, int fd,epoll_event *event){
    int ctl_fd = 0;
    if ((ctl_fd = epoll_ctl(epfd,op,fd,event)) == -1){
        perror("errSource: epoll_creat");
        exit(-1);
    }
    return ctl_fd;
}
int ths_epoll_wait(int epfd, epoll_event *events, int maxevents, int timeout){
    int fd = 0;
    for (;;){
        fd = epoll_wait(epfd, events, maxevents, timeout);
        if (fd > 0){
            break;
        }
        if (errno == EINTR){
            continue;
        }
        else{
            perror("errSource: epoll_wait");
            exit(-1);
        }
    }
    return fd;
}
