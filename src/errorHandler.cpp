#include "../include/errorHandler.h"

errorHandler::errorHandler(int errorNum):
    errorNum(errorNum)
{}

char* errorHandler::what()
{
    char *message = nullptr;

    /* Faltou implementar restante de casos de erros e exceçõees */
    switch(errorNum)
    {
        case 0:
            message = (char*)"ERR_OPENFILE";
    }

    return message;
}