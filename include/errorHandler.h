#ifndef TRABALHOPP_ERRORHANDLER_H
#define TRABALHOPP_ERRORHANDLER_H

#include <cstring>
#include <exception>

class errorHandler : public std::exception
{
    int errorNum;
public:
    explicit errorHandler(int errorNum);
    char* what();
};


#endif //TRABALHOPP_ERRORHANDLER_H
