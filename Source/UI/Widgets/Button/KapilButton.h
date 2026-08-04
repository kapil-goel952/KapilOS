
#ifndef KAPIL_BUTTON_H
#define KAPIL_BUTTON_H

#include <string>
#include <SDL2/SDL.h>

class KapilButton
{
public:

    //--------------------------------------------------
    // Icon Button
    //--------------------------------------------------

    static bool Draw(
        const std::string& id,
        SDL_Texture* icon,
        const std::string& tooltip,
        float width,
        float height,
        bool selected = false
    );

private:

    static void DrawBackground(
        bool hovered,
        bool selected
    );

    static void DrawImage(
        SDL_Texture* texture,
        float size
    );
};

#endif
