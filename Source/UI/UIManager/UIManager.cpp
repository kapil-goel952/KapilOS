#include "UIManager.h"

UIManager::UIManager()
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

    applicationManager.Draw();
}
