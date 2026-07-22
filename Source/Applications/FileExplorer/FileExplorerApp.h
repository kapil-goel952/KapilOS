#ifndef FILE_EXPLORER_APP_H
#define FILE_EXPLORER_APP_H

#include "../Application/Application.h"
#include "../../UI/Window/WindowUI.h"

class FileExplorerApp : public Application
{
public:

    FileExplorerApp();

    void Draw() override;

private:

    WindowUI window;
};

#endif
