//
// Created by sm4ll_3gg on 12.11.16.
//

#ifndef GRAPHTHEORY_TEXCEPTIONS_H
#define GRAPHTHEORY_TEXCEPTIONS_H

#include <string>

class TException : public std::exception
{
    std::string name;
public:
    TException();
    TException(const std::string&);
    TException(const std::string&, std::exception&);

    std::string     get_error_name();
};


#endif //GRAPHTHEORY_TEXCEPTIONS_H
