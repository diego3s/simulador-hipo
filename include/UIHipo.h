#ifndef TRABALHOPP_UIHIPO_H
#define TRABALHOPP_UIHIPO_H

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "../include/hipo.h"

using namespace std;

class Interface
{
    sf::RenderWindow *window;
    sf::Font *fontMedium;
    sf::Font *fontBold;
    sf::Texture *mainScreen;
    sf::Sprite *background;

    HIPO myHipo;
    uint16_t lastExecution;

    /* Definindo variáveis para o menu superior: Executar (F5) e Encerrar Programa (F10) */
    int selectedChoice;
    bool pressedChoice, enteredChoice;
    vector<const char *> choiceOperations;
    vector<sf::Vector2f> choiceCoordinates;
    vector<sf::Text> choiceTexts;

    /* Variáveis para os textos restantes */
    vector<sf::Text> memoryAddress;
    vector<sf::Text> memoryValues;
    vector<sf::Text> CPURegisters;
    vector<sf::Text> textInstruction;

public:
    explicit Interface(const char *filePath);
    ~Interface();
    void defineValues();
    void eventLoop();
    void drawTexts();
    void drawInterface();
    void runHipo();
};

#endif //TRABALHOPP_UIHIPO_H