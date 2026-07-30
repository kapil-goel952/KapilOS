#include <iostream>
#ifndef ICON_MANAGER_H
#define ICON_MANAGER_H

#include <string>
#include <SDL2/SDL.h>


class IconManager
{

public:

    static SDL_Texture* LoadIcon(
        SDL_Renderer* renderer,
        const std::string& name
    );
private:


};


#endif
