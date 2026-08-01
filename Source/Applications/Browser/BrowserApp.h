#ifndef BROWSER_APP_H
#define BROWSER_APP_H

#include "../Application/Application.h"
#include "../../UI/Window/WindowUI.h"

class BrowserApp : public Application
{
public:

    BrowserApp();

    void Draw() override;

private:

    WindowUI window;
};

#endif
