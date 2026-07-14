#include "DesktopIcon.h"

DesktopIcon::DesktopIcon(int x, int y, std::string name)
{
    m_x = x;
    m_y = y;
    m_name = name;
}

void DesktopIcon::Draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer,255,255,255,255);

    SDL_Rect icon =
    {
        m_x,
        m_y,
        60,
        60
    };

    SDL_RenderFillRect(renderer,&icon);
}
