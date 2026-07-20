#include "../Sidebar/SidebarUI.h"
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

    SidebarUI sidebar;
    sidebar.Draw();

    DockUI dock;
    dock.Draw();
}
