#ifndef UI_STYLE_H
#define UI_STYLE_H

class UIStyle
{
public:

    // ==================================================
    // Screen
    // ==================================================

    static void Update(
        int screenWidth,
        int screenHeight
    );

    static float ScreenWidth();
    static float ScreenHeight();


    // ==================================================
    // Sidebar
    // ==================================================

    static float SidebarWidth();
    static float SidebarPadding();
    static float SidebarSpacing();
    static float SidebarRadius();
    static float SidebarIconSize();


    // ==================================================
    // Dock
    // ==================================================

    static float DockHeight();
    static float DockPadding();
    static float DockSpacing();
    static float DockRadius();
    static float DockIconSize();


    // ==================================================
    // Top Bar
    // ==================================================

    static float TopBarHeight();
    static float TopBarPadding();
    static float TopBarRadius();


    // ==================================================
    // Desktop
    // ==================================================

    static float DesktopIconSize();
    static float DesktopSpacing();


    // ==================================================
    // Windows
    // ==================================================

    static float WindowPadding();
    static float WindowRadius();


    // ==================================================
    // Widgets
    // ==================================================

    static float WidgetPadding();
    static float WidgetSpacing();
    static float WidgetRadius();


private:

    static int s_screenWidth;
    static int s_screenHeight;
};

#endif
