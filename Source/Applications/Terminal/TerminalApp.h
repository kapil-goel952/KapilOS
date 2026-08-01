#ifndef TERMINAL_APP_H
#define TERMINAL_APP_H

#include "../Application/Application.h"
#include "../../UI/Window/WindowUI.h"
#include "../../Core/Shell/Shell.h"

#include <string>

class TerminalApp : public Application
{
public:

    TerminalApp();

    void Draw() override;

private:

    WindowUI window;

    Shell shell;

    std::string output;

    char input[512];
};

#endif

