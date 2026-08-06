#ifndef KAPIL_BUTTON_H
#define KAPIL_BUTTON_H

#include <string>
#include <SDL2/SDL.h>

class KapilButton
{
public:

    static bool Draw(
        const std::string& id,
        SDL_Texture* icon,
        const std::string& tooltip,
        float width,
        float height,
        bool selected = false
    );
};

#endif
