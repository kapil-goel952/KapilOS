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

void UIManager::Draw(
    int screenWidth,
    int screenHeight
)
{
    desktop.Draw(
        screenWidth,
        screenHeight
    );

    topBar.Draw(
        screenWidth
    );

    sidebar.Draw(
        screenHeight
    );

    dock.Draw(
        screenWidth,
        screenHeight
    );

    explorer.Draw();

    settings.Draw();
}
