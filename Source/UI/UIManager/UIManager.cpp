#include "UIManager.h"

#include "../Desktop/DesktopUI.h"
#include "../TopBar/TopBarUI.h"

void UIManager::Draw()
{
    DesktopUI desktop;
    desktop.Draw();

    TopBarUI topbar;
    topbar.Draw();
}
