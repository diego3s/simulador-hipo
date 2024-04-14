#ifndef TRABALHOPP_MEMORY_H
#define TRABALHOPP_MEMORY_H

#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

class Memory : private vector<uint16_t>
{
public:
    void initMemory(uint16_t size);
    void loadInstruction(uint16_t instructionCode);
    uint16_t& at(unsigned i);
    unsigned size();
    explicit operator string();
};

#endif //TRABALHOPP_MEMORY_H
