#ifndef ICON_MANAGER_H
#define ICON_MANAGER_H

#include <SDL2/SDL.h>

#include <string>
#include <unordered_map>

class IconManager
{
public:

    // Initialize once at startup
    static void Initialize(
        SDL_Renderer* renderer
    );

    // Free every loaded texture
    static void Shutdown();

    // Get an already loaded icon
    static SDL_Texture* Get(
        const std::string& name
    );

    // Load one icon manually if needed
    static SDL_Texture* LoadIcon(
        SDL_Renderer* renderer,
        const std::string& name
    );

private:

    static SDL_Renderer* renderer;

    static std::unordered_map
    <
        std::string,
        SDL_Texture*
    > icons;
};

#endif
