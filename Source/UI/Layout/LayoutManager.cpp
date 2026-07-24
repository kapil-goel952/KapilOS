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
    return m_screenHeight * 0.05f;
}

float LayoutManager::SidebarWidth()
{
    return m_screenWidth * 0.045f;
}

float LayoutManager::DockWidth()
{
    return m_screenWidth * 0.28f;
}

float LayoutManager::DockHeight()
{
    return m_screenHeight * 0.09f;
}

float LayoutManager::Padding()
{
    return m_screenWidth * 0.008f;
}

float LayoutManager::CornerRadius()
{
    return m_screenWidth * 0.008f;
}
