#include "../Constants/UIConstants.h"
#include "LayoutManager.h"

float LayoutManager::m_screenWidth = 1280.0f;
float LayoutManager::m_screenHeight = 720.0f;

void LayoutManager::Update(
    int screenWidth,
    int screenHeight
)
{
    m_screenWidth = (float)screenWidth;
    m_screenHeight = (float)screenHeight;
}

float LayoutManager::ScreenWidth()
{
    return m_screenWidth;
}

float LayoutManager::ScreenHeight()
{
    return m_screenHeight;
}

float LayoutManager::TopBarHeight()
{
    return ScaleY(UI::TopBarHeight);
}

float LayoutManager::SidebarWidth()
{
    return ScaleX(UI::SidebarWidth);
}

float LayoutManager::DockWidth()
{
    return ScaleX(540.0f);
}

float LayoutManager::DockHeight()
{
    return ScaleY(UI::DockHeight);
}

float LayoutManager::Padding()
{
    return ScaleX(UI::Padding);
}

float LayoutManager::CornerRadius()
{
    return ScaleX(UI::Radius);
}

float LayoutManager::ScaleX(float value)
{
    return value * (m_screenWidth / UI::BaseWidth);
}

float LayoutManager::ScaleY(float value)
{
    return value * (m_screenHeight / UI::BaseHeight);
}

float LayoutManager::IconButtonSize()
{
    return ScaleX(UI::IconButton);
}

float LayoutManager::SmallIconButton()
{
    return ScaleX(UI::IconButton * 0.8f);
}

float LayoutManager::Spacing()
{
    return ScaleX(UI::Spacing);
}

float LayoutManager::RightPadding()
{
    return ScaleX(24.0f);
}
