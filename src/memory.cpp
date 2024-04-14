#include "../include/memory.h"

void Memory::initMemory(uint16_t size)
{
    /* Iniciar todas as posições da memória com o valor 0 */
    for (uint16_t i=0; i<size; ++i)
        vector<uint16_t>::push_back(0);
}

void Memory::loadInstruction(uint16_t instructionCode)
{
    unsigned memorySize = vector<uint16_t>::size();

    for (unsigned i=0; i<memorySize; ++i)
    {
        if (vector<uint16_t>::at(i) == 0)
        {
            vector<uint16_t>::at(i) = instructionCode;
            return;
        }
    }
}

uint16_t& Memory::at(unsigned int i)
{
    return vector<uint16_t>::at(i);
}

unsigned Memory::size()
{
    return vector<uint16_t>::size();
}

Memory::operator string()
{
    string str;
    unsigned i = 0;

    typename vector<uint16_t>::iterator it;
    for (it = vector<uint16_t>::begin(); it != vector<uint16_t>::end(); ++it)
    {
        str += "[";
        str += to_string(i);
        str += "] = ";
        str += to_string(*it);
        str += "\n";

        ++i;
    }

    return string{str};
}