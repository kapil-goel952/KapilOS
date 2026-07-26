#include <SDL2/SDL.h>
#ifndef GRAPHICS_H
#define GRAPHICS_H

class Graphics
{
public:

    bool Initialize();

    void Run();

    void Shutdown();
private:

    SDL_Texture* m_wallpaper = nullptr;

    SDL_Texture* m_homeIcon = nullptr;

    SDL_Window* m_window = nullptr;

    SDL_Renderer* m_renderer = nullptr;
};

#endif
