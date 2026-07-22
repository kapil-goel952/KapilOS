#ifndef SETTINGS_APP_H
#define SETTINGS_APP_H

#include "../Application/Application.h"
#include "../../UI/Window/WindowUI.h"

class SettingsApp : public Application
{
public:

    SettingsApp();

    void Draw() override;

private:

    WindowUI window;
};

#endif
