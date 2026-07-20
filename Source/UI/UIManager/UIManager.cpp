#include "UIManager.h"

UIManager::UIManager()

    :

    explorer(
        "File Explorer",
        250,
        120,
        500,
        350
    ),

    settings(
        "Settings",
        820,
        180,
        350,
        260
    )

{
}

void UIManager::Draw()
{
    desktop.Draw();

    topBar.Draw();

    sidebar.Draw();

    dock.Draw();

    explorer.Draw();

    settings.Draw();
}
