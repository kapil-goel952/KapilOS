#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

class Graphics
{
public:

    Graphics() = default;

    bool Initialize();

    void Run();

    void Shutdown();

private:

    //----------------------------------------
    // Window
    //----------------------------------------

    SDL_Window* m_window = nullptr;

    SDL_Renderer* m_renderer = nullptr;

    //----------------------------------------
    // Assets
    //----------------------------------------

    SDL_Texture* m_wallpaper = nullptr;

    SDL_Texture* m_homeIcon = nullptr;

    //----------------------------------------
    // Internal Rendering
    //----------------------------------------

    void BeginFrame();

    void RenderWallpaper();

    void RenderDesktop();

    void RenderApplications();

    void RenderPanels();

    void RenderOverlay();

    void EndFrame();
};

#endif

