#include <SDL2/SDL.h>
#ifndef UI_MANAGER_H
#define UI_MANAGER_H
#include "../Widgets/Weather/WeatherWidget.h"
#include "../Widgets/Calendar/CalendarWidget.h"
#include "../Widgets/Status/StatusWidget.h"
#include "../Desktop/DesktopUI.h"
#include "../TopBar/TopBarUI.h"
#include "../Sidebar/SidebarUI.h"
#include "../Dock/DockUI.h"

#include "../../ApplicationManager/ApplicationManager.h"

class UIManager
{

public:

    void Initialize(SDL_Renderer* renderer);

    void Draw(
        int screenWidth,
        int screenHeight
    );

    UIManager();

private:
    WeatherWidget weather;

    CalendarWidget calendar;

    StatusWidget status;

    DesktopUI desktop;

    TopBarUI topBar;

    SidebarUI sidebar;

    DockUI dock;

    ApplicationManager applicationManager;
};

#endif
