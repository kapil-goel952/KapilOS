#ifndef CALCULATOR_APP_H
#define CALCULATOR_APP_H

#include "../Application/Application.h"
#include "../../UI/Window/WindowUI.h"
#include "../../Core/CalculatorEngine/CalculatorEngine.h"

#include <string>

class CalculatorApp : public Application
{
public:

    CalculatorApp();

    void Draw() override;

private:

    WindowUI window;

    CalculatorEngine engine;

    char expression[256] = "";

    double first = 0;

    char operation = 0;

    bool waitingSecond = false;

    void AddButton(
        const char* text,
        float width,
        float height
    );
};

#endif
