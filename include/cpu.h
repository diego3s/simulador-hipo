#ifndef TRABALHOPP_CPU_H
#define TRABALHOPP_CPU_H

#include <iostream>
#include <limits>
#include <cstdint>
#include "../include/memory.h"
#include "../include/instructions.h"

class CPU
{
    uint16_t AC;
    uint16_t *PC;

public:
    CPU();
    void setPC(uint16_t *newValue);
    uint16_t*& getPC();
    uint16_t getAC() const;
    void executeInstruction(Memory& tempMemory);
};

#endif //TRABALHOPP_CPU_H
