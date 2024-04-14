#include "../include/instructions.h"

uint16_t Instructions::encode(char *instruction, uint16_t address)
{
    if (strcmp(instruction, "CEA") == 0)
        return 1100 + address;

    if (strcmp(instruction, "CAE") == 0)
        return 1200 + address;

    if (strcmp(instruction, "SOM") == 0)
        return 2100 + address;

    if (strcmp(instruction, "SUB") == 0)
        return 2200 + address;

    if (strcmp(instruction, "MUL") == 0)
        return 2300 + address;

    if (strcmp(instruction, "DIV") == 0)
        return 2400 + address;

    if (strcmp(instruction, "MOD") == 0)
        return 2500 + address;

    if (strcmp(instruction, "LER") == 0)
        return 3100 + address;

    if (strcmp(instruction, "IMP") == 0)
        return 4100 + address;

    if (strcmp(instruction, "NOP") == 0)
        return 5000 + address;

    if (strcmp(instruction, "DES") == 0)
        return 5100 + address;

    if (strcmp(instruction, "DPO") == 0)
        return 5200 + address;

    if (strcmp(instruction, "DPZ") == 0)
        return 5300 + address;

    if (strcmp(instruction, "DNE") == 0)
        return 5400 + address;

    if (strcmp(instruction, "DNZ") == 0)
        return 5500 + address;

    if (strcmp(instruction, "DDZ") == 0)
        return 5600 + address;

    if (strcmp(instruction, "DZZ") == 0)
        return 5700 + address;

    if (strcmp(instruction, "DDF") == 0)
        return 5800 + address;

    if (strcmp(instruction, "DFF") == 0)
        return 5900 + address;

    if (strcmp(instruction, "ADE") == 0)
        return 6100 + address;

    if (strcmp(instruction, "ADD") == 0)
        return 6200 + address;

    if (strcmp(instruction, "PAR") == 0)
        return 7000 + address;

    return 1;
}

uint16_t Instructions::CEA(uint16_t address, Memory& updateMemory)
{
    return updateMemory.at(address);
}

void Instructions::CAE(uint16_t address, Memory& updateMemory, const uint16_t& acValue)
{
    updateMemory.at(address) = acValue;
}

uint16_t Instructions::SOM(uint16_t address, Memory& updateMemory, const uint16_t& acValue)
{
    return acValue + updateMemory.at(address);
}

uint16_t Instructions::SUB(uint16_t address, Memory& updateMemory, const uint16_t& acValue)
{
    return acValue - updateMemory.at(address);
}

uint16_t Instructions::MUL(uint16_t address, Memory& updateMemory, const uint16_t& acValue)
{
    return acValue * updateMemory.at(address);
}

uint16_t Instructions::DIV(uint16_t address, Memory& updateMemory, const uint16_t& acValue)
{
    return acValue / updateMemory.at(address);
}

uint16_t Instructions::MOD(uint16_t address, Memory& updateMemory, const uint16_t& acValue)
{
    return acValue % updateMemory.at(address);
}

void Instructions::LER(uint16_t address, Memory& updateMemory)
{
    cout << "INPUT >> ";
    cin >> updateMemory.at(address);
}

void Instructions::IMP(uint16_t address, Memory& updateMemory)
{
    cout << "OUTPUT << ";
    cout << updateMemory.at(address) << endl;
}

uint16_t& Instructions::DES(uint16_t address, Memory& updateMemory)
{
    return updateMemory.at(address);
}

uint16_t& Instructions::DPO(uint16_t address, Memory& updateMemory)
{
    return updateMemory.at(address);
}

uint16_t& Instructions::DPZ(uint16_t address, Memory& updateMemory)
{
    return updateMemory.at(address);
}

uint16_t& Instructions::DNE(uint16_t address, Memory& updateMemory)
{
    return updateMemory.at(address);
}

uint16_t& Instructions::DNZ(uint16_t address, Memory& updateMemory)
{
    return updateMemory.at(address);
}

uint16_t& Instructions::DDZ(uint16_t address, Memory& updateMemory)
{
    return updateMemory.at(address);
}

uint16_t& Instructions::DZZ(uint16_t address, Memory& updateMemory)
{
    return updateMemory.at(address);
}

uint16_t& Instructions::DDF(uint16_t address, Memory& updateMemory)
{
    return updateMemory.at(address);
}

uint16_t& Instructions::DFF(uint16_t address, Memory& updateMemory)
{
    return updateMemory.at(address);
}

uint16_t Instructions::ADE(const uint16_t& acValue)
{
    return acValue << 1;
}

uint16_t Instructions::ADD(const uint16_t& acValue)
{
    return acValue >> 1;
}