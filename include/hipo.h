#ifndef TRABALHOPP_HIPO_H
#define TRABALHOPP_HIPO_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "cpu.h"
#include "memory.h"
#include "instructions.h"

using namespace std;

class HIPO
{
    const char *filePath;
    uint16_t numInstructions;

    CPU cpu;
    Memory memory;
    Instructions instructions;
public:
    HIPO();
    void setFilePath(const char *newFilePath);
    uint16_t getAC() const;
    uint16_t*& getPCInterface();
    uint16_t getNumInstructions() const;
    unsigned memorySize();
    uint16_t& getElementMemory(unsigned i);
    void initHIPO(uint16_t memorySize);
    void readFile();
    void Run();
};

#endif //TRABALHOPP_HIPO_H
