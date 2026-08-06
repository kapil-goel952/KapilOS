#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <SDL2/SDL.h>

#include "../Desktop/DesktopUI.h"
#include "../TopBar/TopBarUI.h"
#include "../Sidebar/SidebarUI.h"
#include "../Dock/DockUI.h"

#include "../Widgets/Weather/WeatherWidget.h"
#include "../Widgets/Calendar/CalendarWidget.h"
#include "../Widgets/Status/StatusWidget.h"

#include "../../ApplicationManager/ApplicationManager.h"

class UIManager
{
public:

    UIManager();

    //----------------------------------------
    // Initialization
    //----------------------------------------

    void Initialize(
        SDL_Renderer* renderer
    );

    //----------------------------------------
    // Draw Everything
    //----------------------------------------

    void Draw(
        int screenWidth,
        int screenHeight
    );

private:

    //----------------------------------------
    // Desktop UI
    //----------------------------------------

    DesktopUI desktop;

    TopBarUI topBar;

    SidebarUI sidebar;

    DockUI dock;

    //----------------------------------------
    // Widgets
    //----------------------------------------

    WeatherWidget weather;

    CalendarWidget calendar;

    StatusWidget status;

    //----------------------------------------
    // Applications
    //----------------------------------------

    ApplicationManager applicationManager;
};

#endif
