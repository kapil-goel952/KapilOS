#ifndef DESKTOPICON_H
#define DESKTOPICON_H

#include <SDL2/SDL.h>
#include <string>

class DesktopIcon
{
public:

    DesktopIcon(int x, int y, std::string name);

    void Draw(SDL_Renderer* renderer);

private:

    int m_x;
    int m_y;

    std::string m_name;
};

#endif
