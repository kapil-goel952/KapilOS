#ifndef SIDEBAR_UI_H
#define SIDEBAR_UI_H

#include <SDL2/SDL.h>

#include <functional>
#include <string>

class SidebarUI
{
public:

    SidebarUI() = default;

    //----------------------------------------
    // Initialization
    //----------------------------------------

    void Initialize(
        SDL_Renderer* renderer
    );

    //----------------------------------------
    // Drawing
    //----------------------------------------

    void Draw(    );

    //----------------------------------------
    // Launch callback
    //----------------------------------------

    void SetLaunchCallback(
        std::function<void(const std::string&)> callback
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
    // Launch callback
    //----------------------------------------

    std::function<void(const std::string&)> launchCallback;

    //----------------------------------------
    // Selected button
    //----------------------------------------

    int selectedItem = 0;
};

#endif
