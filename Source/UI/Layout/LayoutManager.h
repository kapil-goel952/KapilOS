#ifndef LAYOUT_MANAGER_H
#define LAYOUT_MANAGER_H

class LayoutManager
{
public:

    static void Update(
        int screenWidth,
        int screenHeight
    );

    static float ScreenWidth();
    static float ScreenHeight();

    static float TopBarHeight();

    static float SidebarWidth();

    static float DockWidth();

    static float DockHeight();

    static float Padding();

    static float CornerRadius();

private:

    static float m_screenWidth;
    static float m_screenHeight;
};

#endif
