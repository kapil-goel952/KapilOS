#ifndef SIDEBAR_UI_H
#define SIDEBAR_UI_H

#include <SDL2/SDL.h>

class SidebarUI
{
public:

    void Initialize(
        SDL_Renderer* renderer
    );

    void Draw(
        int screenHeight
    );

private:

    //----------------------------------------
    // Renderer
    //----------------------------------------

    SDL_Renderer* renderer = nullptr;

    //----------------------------------------
    // Cached Icons
    //----------------------------------------

    SDL_Texture* homeIcon      = nullptr;
    SDL_Texture* searchIcon    = nullptr;
    SDL_Texture* folderIcon    = nullptr;
    SDL_Texture* browserIcon   = nullptr;
    SDL_Texture* terminalIcon  = nullptr;
    SDL_Texture* codeIcon      = nullptr;
    SDL_Texture* settingsIcon  = nullptr;
    SDL_Texture* userIcon      = nullptr;

    //----------------------------------------
    // UI State
    //----------------------------------------

    int selectedItem = 0;
};

#endif
