#include "../include/UIHipo.h"

Interface::Interface(const char *filePath)
{
    window = new sf::RenderWindow();
    fontMedium = new sf::Font();
    fontBold = new sf::Font();
    mainScreen = new sf::Texture();
    background = new sf::Sprite();

    myHipo.setFilePath(filePath);
    myHipo.initHIPO(100);
    myHipo.readFile();
    lastExecution = 0;

    defineValues();
    drawTexts();
}

Interface::~Interface()
{
    delete window;
    delete fontMedium;
    delete fontBold;
    delete mainScreen;
    delete background;
}

void Interface::defineValues()
{
    window->create(sf::VideoMode(1280,800), "Interface HIPO", sf::Style::Titlebar | sf::Style::Close);
    window->setVerticalSyncEnabled(true);

    fontMedium->loadFromFile("../resources/Montserrat-Medium.ttf");
    fontBold->loadFromFile("../resources/Montserrat-Bold.ttf");
    mainScreen->loadFromFile("../resources/mainScreen.png");
    background->setTexture(*mainScreen);

    /* Zerando posição e coordenada inicial do mouse */
    selectedChoice = 0;
    pressedChoice = enteredChoice = false;

    /* Definindo o menu superior */
    choiceOperations = {"Executar (F5)", "Encerrar (F10)"};
    choiceCoordinates = {{71,42},{331,42}};
    choiceTexts.resize(2);

    for (size_t i{}; i<choiceTexts.size(); ++i)
    {
        choiceTexts[i].setFont(*fontMedium);
        choiceTexts[i].setString(choiceOperations[i]);
        choiceTexts[i].setCharacterSize(20);
        choiceTexts[i].setOutlineColor(sf::Color::Black);
        choiceTexts[i].setPosition(choiceCoordinates[i]);
    }

    choiceTexts[0].setOutlineThickness(1);
}

void Interface::eventLoop()
{
    sf::Event event{};

    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window->close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressedChoice)
        {
            if (selectedChoice < 1)
            {
                ++selectedChoice;
                pressedChoice = true;
                choiceTexts[selectedChoice].setOutlineThickness(1);
                choiceTexts[selectedChoice-1].setOutlineThickness(0);
                pressedChoice = false;
                enteredChoice = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressedChoice)
        {
            if (selectedChoice > 0)
            {
                --selectedChoice;
                pressedChoice = true;
                choiceTexts[selectedChoice].setOutlineThickness(1);
                choiceTexts[selectedChoice+1].setOutlineThickness(0);
                pressedChoice = false;
                enteredChoice = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !enteredChoice)
        {
            if (selectedChoice == 0)
            {
                if (lastExecution <= myHipo.getNumInstructions())
                {
                    myHipo.Run();
                    drawTexts();
                    lastExecution++;
                }
            }
            else
            {
                window->close();
            }

            enteredChoice = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
        {
            if (lastExecution <= myHipo.getNumInstructions())
            {
                myHipo.Run();
                drawTexts();
                lastExecution++;
            }

            if (lastExecution > myHipo.getNumInstructions())
            {
                /* Desenhando texto de instrução - encerramento */
                textInstruction[1].setFont(*fontMedium);
                textInstruction[1].setString("Programa finalizado. Para fechar o HIPO pressione\nF10 ou ESC.");
                textInstruction[1].setCharacterSize(16);
                textInstruction[1].setPosition({33, 670});
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F10))
            window->close();
    }
}

void Interface::drawTexts()
{
    float y = 93, x = 530, lastX = 0, lastY = 0;

    memoryAddress.resize(myHipo.memorySize());
    memoryValues.resize(myHipo.memorySize());
    CPURegisters.resize(2);
    textInstruction.resize(2);

    /* String para os textos */
    ostringstream address;
    string values;

    /* Desenhando valores de cada posição da memória*/
    for (size_t i{}; i<myHipo.memorySize(); ++i)
    {
        if (i % 25 == 0)
        {
            y = 93;
            lastY = 0;

            if (i != 0)
                x += 184;
        }
        else
        {
            y += 27;
        }

        address << &myHipo.getElementMemory(i);
        memoryAddress[i].setFont(*fontMedium);
        memoryAddress[i].setString(address.str());
        memoryAddress[i].setCharacterSize(13);
        memoryAddress[i].setPosition({x, y});

        values += to_string(myHipo.getElementMemory(i));
        memoryValues[i].setFont(*fontBold);
        memoryValues[i].setString(values);
        memoryValues[i].setCharacterSize(14);
        memoryValues[i].setPosition({x+123, y});

        values.clear();
        address.str("");
    }

    /* Desenhando textos dos registradores da CPU */
    for (size_t i{}; i<2; ++i)
    {
        values.clear();
        address.str("");

        /* Desenha acumulador */
        if (i == 0)
        {
            values += to_string(myHipo.getAC());
            CPURegisters[i].setFont(*fontBold);
            CPURegisters[i].setString(values);
            CPURegisters[i].setFillColor(sf::Color{80,255,123,255});
            CPURegisters[i].setCharacterSize(36);
            CPURegisters[i].setPosition({230, 255});
        }
        else
        {
            /* Desenha PC - Program counter(Apontador de instruções) */
            address << myHipo.getPCInterface();
            CPURegisters[i].setFont(*fontBold);
            CPURegisters[i].setString(address.str());
            CPURegisters[i].setFillColor(sf::Color{80,255,123,255});
            CPURegisters[i].setCharacterSize(36);
            CPURegisters[i].setPosition({100, 397});
        }
    }

    /* Desenhando textos de instrução */
    textInstruction[0].setFont(*fontMedium);
    textInstruction[0].setString("Entradas(INPUT >>) e Saidas(OUTPUT <<) sao feitas \nno terminal.");
    textInstruction[0].setCharacterSize(16);
    textInstruction[0].setPosition({33, 595});
}

void Interface::drawInterface()
{
    window->clear();
    window->draw(*background);

    /* Desenhando menu superior */
    for (const auto& choiceT : choiceTexts)
    {
        window->draw(choiceT);
    }

    /* Desenhando posições da memória e valores dos registradores */
    for (size_t i{}; i<myHipo.memorySize(); ++i)
    {
        if (i < 2)
        {
            window->draw(CPURegisters[i]);
            window->draw(textInstruction[i]);
        }

        window->draw(memoryAddress[i]);
        window->draw(memoryValues[i]);
    }

    window->display();
}

void Interface::runHipo()
{
    while (window->isOpen())
    {
        eventLoop();
        drawInterface();
    }
}