#ifndef TRABALHOPP_INSTRUCTIONS_H
#define TRABALHOPP_INSTRUCTIONS_H

#include <cstdint>
#include <cstring>
#include "../include/memory.h"

class Instructions
{
public:
    uint16_t encode(char *instruction, uint16_t address);
    static uint16_t CEA(uint16_t address, Memory& updateMemory);
    static void CAE(uint16_t address, Memory& updateMemory, const uint16_t& acValue);
    static uint16_t SOM(uint16_t address, Memory& updateMemory, const uint16_t& acValue);
    static uint16_t SUB(uint16_t address, Memory& updateMemory, const uint16_t& acValue);
    static uint16_t MUL(uint16_t address, Memory& updateMemory, const uint16_t& acValue);
    static uint16_t DIV(uint16_t address, Memory& updateMemory, const uint16_t& acValue);
    static uint16_t MOD(uint16_t address, Memory& updateMemory, const uint16_t& acValue);
    static void LER(uint16_t address, Memory& updateMemory);
    static void IMP(uint16_t address, Memory& updateMemory);
    void NOP(){}
    static uint16_t& DES(uint16_t address, Memory& updateMemory);
    static uint16_t& DPO(uint16_t address, Memory& updateMemory);
    static uint16_t& DPZ(uint16_t address, Memory& updateMemory);
    static uint16_t& DNE(uint16_t address, Memory& updateMemory);
    static uint16_t& DNZ(uint16_t address, Memory& updateMemory);
    static uint16_t& DDZ(uint16_t address, Memory& updateMemory);
    static uint16_t& DZZ(uint16_t address, Memory& updateMemory);
    static uint16_t& DDF(uint16_t address, Memory& updateMemory);
    static uint16_t& DFF(uint16_t address, Memory& updateMemory);
    static uint16_t ADE(const uint16_t& acValue);
    static uint16_t ADD(const uint16_t& acValue);
    void PAR(){}
};

#endif //TRABALHOPP_INSTRUCTIONS_H
