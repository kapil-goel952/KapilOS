#ifndef DOCK_UI_H
#define DOCK_UI_H

#include <SDL2/SDL.h>

class DockUI
{
public:

    void Initialize(SDL_Renderer* renderer);

    void Draw(
        int screenWidth,
        int screenHeight
    );

private:

    SDL_Texture* house=nullptr;
    SDL_Texture* folder=nullptr;
    SDL_Texture* gear=nullptr;
};

#endif
