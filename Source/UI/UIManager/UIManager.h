#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include "../Desktop/DesktopUI.h"
#include "../TopBar/TopBarUI.h"
#include "../Sidebar/SidebarUI.h"
#include "../Dock/DockUI.h"
#include "../Window/WindowUI.h"

class UIManager
{
public:

    UIManager();

    void Draw();

private:

    DesktopUI desktop;

    TopBarUI topBar;

    SidebarUI sidebar;

    DockUI dock;

    WindowUI explorer;

    WindowUI settings;
};

#endif
