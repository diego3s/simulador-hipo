#include <iostream>
#include "../include/hipo.h"
#include "../include/UIHipo.h"

using namespace std;

int main()
{
    char newFilePath[120];
    cout << "Digite o caminho do arquivo desejado. Por Exemplo:\n"
            "../exemplos/soma.hipo\nArquivo: ";
    cin >> newFilePath;

    auto *myInterface = new Interface(newFilePath);
    myInterface->runHipo();
    delete myInterface;
    myInterface = nullptr;

    return 0;
}