#include "../include/hipo.h"
#include "../include/errorHandler.h"

HIPO::HIPO():
    filePath(""),
    numInstructions(0)
{}

void HIPO::setFilePath(const char *newFilePath)
{
    filePath = newFilePath;
}

uint16_t HIPO::getAC() const
{
    return cpu.getAC();
}

uint16_t*& HIPO::getPCInterface()
{
    return cpu.getPC();
}

uint16_t HIPO::getNumInstructions() const
{
    return numInstructions;
}

unsigned HIPO::memorySize()
{
    return memory.size();
}

uint16_t& HIPO::getElementMemory(unsigned i)
{
    return memory.at(i);
}

void HIPO::initHIPO(uint16_t memorySize)
{
    memory.initMemory(memorySize);
}

void HIPO::readFile()
{
    ifstream targetFile(filePath);
    string lineFile;

    /* Variáveis utilizadas para separação da string lida do arquivo */
    char *ptr, *ptc, *tempInstruction;
    int positionFile = 0, tempAddress = 0;
    uint16_t instructionCode;

    try
    {
        if (!targetFile.is_open())
        {
            throw errorHandler(0);
        }

        while (targetFile)
        {
            getline(targetFile, lineFile);

            /* Separando a string em duas partes: instrução e endereço */
            ptc = strdup(lineFile.c_str());
            ptr = strtok(ptc, " ");
            while (ptr)
            {
                if (positionFile == 0)
                    tempInstruction = ptr;
                else
                    tempAddress = stoi(ptr);

                ptr = strtok(nullptr, " ");
                positionFile++;
            }

            /* Verificar se está no final da execução do programa */
            if (strcmp(tempInstruction, "PAR") == 0 || strcmp(tempInstruction, "") == 0)
            {
                if (strcmp(tempInstruction, "PAR") == 0)
                    memory.loadInstruction(7000);

                break;
            }

            instructionCode = instructions.encode(tempInstruction, tempAddress);
            memory.loadInstruction(instructionCode);

            positionFile = 0;
            tempAddress = 0;
            tempInstruction = (char*)"";
            ++numInstructions;
        }

        cpu.setPC(&memory.at(0));
    }
    catch (errorHandler& hipoError)
    {
        cerr << hipoError.what() <<endl;
        exit(-1);
    }
}

void HIPO::Run()
{
    cpu.executeInstruction(memory);
}