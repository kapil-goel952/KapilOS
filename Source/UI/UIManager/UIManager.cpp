#include "UIManager.h"
#include "../Dock/DockUI.h"
#include "../Desktop/DesktopUI.h"
#include "../TopBar/TopBarUI.h"
void UIManager::Draw()
{
    DesktopUI desktop;
    desktop.Draw();

    TopBarUI topbar;
    topbar.Draw();

    DockUI dock;
    dock.Draw();
}
