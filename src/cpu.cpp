#include "../include/cpu.h"

CPU::CPU()
{
    AC = 0;
    PC = nullptr;
}

void CPU::setPC(uint16_t *newValue)
{
    PC = newValue;
}

uint16_t*& CPU::getPC()
{
    return PC;
}

uint16_t CPU::getAC() const
{
    return AC;
}

void CPU::executeInstruction(Memory& tempMemory)
{
    /* Ler a instrução na posição apontada pelo PC */
    uint16_t instructionCode = (*PC)/100;
    uint16_t address = (*PC) - instructionCode*100;

    /* Mudar o PC para a instrução seguinte */
    ++PC;

    /* Executar a instrução correspondente */
    switch(instructionCode)
    {
        case 0:
            Instructions().PAR();
            PC = nullptr;
            break;

        case 11:
            AC = Instructions::CEA(address, tempMemory);
            break;

        case 12:
            Instructions::CAE(address, tempMemory, AC);
            break;

        case 21:
            AC = Instructions::SOM(address, tempMemory, AC);
            break;

        case 22:
            AC = Instructions::SUB(address, tempMemory, AC);
            break;

        case 23:
            AC = Instructions::MUL(address, tempMemory, AC);
            break;

        case 24:
            AC = Instructions::DIV(address, tempMemory, AC);
            break;

        case 25:
            AC = Instructions::MOD(address, tempMemory, AC);
            break;

        case 31:
            Instructions::LER(address, tempMemory);
            break;

        case 41:
            Instructions::IMP(address, tempMemory);
            break;

        case 50:
            Instructions().NOP();
            break;

        case 51:
            PC = &Instructions::DES(address, tempMemory);
            break;

        case 52:
            if (AC > 0)
                PC = &Instructions::DPO(address, tempMemory);
            break;

        case 53:
            if (AC >= 0)
                PC = &Instructions::DPZ(address, tempMemory);
            break;

        case 54:
            if (AC < 0)
                PC = &Instructions::DNE(address, tempMemory);
            break;

        case 55:
            if (AC <= 0)
                PC = &Instructions::DNZ(address, tempMemory);
            break;

        case 56:
            if (AC != 0)
                PC = &Instructions::DDZ(address, tempMemory);
            break;

        case 57:
            if (AC == 0)
                PC = &Instructions::DZZ(address, tempMemory);
            break;

        case 58:
            /* Considerando infinito como o máximo do tipo uint16_t */
            if (AC != std::numeric_limits<uint16_t>::max())
                PC = &Instructions::DDF(address, tempMemory);
            break;

        case 59:
            /* Considerando infinito como o máximo do tipo uint16_t */
            if (AC >= std::numeric_limits<uint16_t>::max())
                PC = &Instructions::DFF(address, tempMemory);
            break;

        case 61:
            AC = Instructions::ADE(AC);
            break;

        case 62:
            AC = Instructions::ADD(AC);
            break;

        case 70:
            Instructions().PAR();
            PC = nullptr;
            break;

        default:
            break;
    }
}