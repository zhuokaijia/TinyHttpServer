#ifndef _THS_MRHC_PARSE_H_
#define _THS_MRHC_PARSE_H_

#include  <iostream>
#include  <string>
#include  <vector>
#include  <sstream>
#include  <cstdlib>
#include  <cstdio>
#include  <errno.h>

typedef std::pair<std::string, std::string> _header;

struct ths_header{
    std::string           method;
    std::string           url;
    std::string           version;
    std::vector<_header>  vec;
    std::string           body;
};

extern std::string ths_domain;
extern std::string ths_root;

// parsing httpRequest
// return true iff parsed successfully 
bool request_parse(const std::string& httpRequest, ths_header& content);

// get the real path
std::string getPath(const std::string& url);

#endif
