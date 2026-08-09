#include "UIStyle.h"

#include <algorithm>

// ==================================================
// Static Members
// ==================================================

int UIStyle::s_screenWidth  = 1280;
int UIStyle::s_screenHeight = 720;


// ==================================================
// Screen
// ==================================================

void UIStyle::Update(
    int screenWidth,
    int screenHeight
)
{
    s_screenWidth  = screenWidth;
    s_screenHeight = screenHeight;
}


float UIStyle::ScreenWidth()
{
    return static_cast<float>(
        s_screenWidth
    );
}


float UIStyle::ScreenHeight()
{
    return static_cast<float>(
        s_screenHeight
    );
}


// ==================================================
// Sidebar
// ==================================================

float UIStyle::SidebarWidth()
{
    return std::max(
        80.0f,
        ScreenWidth() * 0.065f
    );
}


float UIStyle::SidebarPadding()
{
    return SidebarWidth() * 0.15f;
}


float UIStyle::SidebarSpacing()
{
    return SidebarWidth() * 0.10f;
}


float UIStyle::SidebarRadius()
{
    return SidebarWidth() * 0.23f;
}
float UIStyle::SidebarIconSize()
{
    return SidebarWidth() * 0.40f;
}


// ==================================================
// Dock
// ==================================================

float UIStyle::DockHeight()
{
    return std::max(
        72.0f,
        ScreenHeight() * 0.085f
    );
}


float UIStyle::DockPadding()
{
    return DockHeight() * 0.12f;
}


float UIStyle::DockSpacing()
{
    return DockHeight() * 0.10f;
}


float UIStyle::DockRadius()
{
    return DockHeight() * 0.30f;
}


float UIStyle::DockIconSize()
{
    return DockHeight()
        - DockPadding() * 2.0f;
}


// ==================================================
// Top Bar
// ==================================================

float UIStyle::TopBarHeight()
{
    return std::max(
        42.0f,
        ScreenHeight() * 0.055f
    );
}


float UIStyle::TopBarPadding()
{
    return TopBarHeight() * 0.25f;
}


float UIStyle::TopBarRadius()
{
    return TopBarHeight() * 0.30f;
}


// ==================================================
// Desktop
// ==================================================

float UIStyle::DesktopIconSize()
{
    return std::max(
        54.0f,
        ScreenWidth() * 0.040f
    );
}


float UIStyle::DesktopSpacing()
{
    return DesktopIconSize() * 0.40f;
}


// ==================================================
// Windows
// ==================================================

float UIStyle::WindowPadding()
{
    return 14.0f;
}


float UIStyle::WindowRadius()
{
    return 14.0f;
}


// ==================================================
// Widgets
// ==================================================

float UIStyle::WidgetPadding()
{
    return 12.0f;
}


float UIStyle::WidgetSpacing()
{
    return 10.0f;
}


float UIStyle::WidgetRadius()
{
    return 12.0f;
}
