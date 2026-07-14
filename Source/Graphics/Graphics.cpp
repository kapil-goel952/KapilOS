#include "Graphics.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "../DesktopIcons/DesktopIcon.h"


SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

bool Graphics::Initialize()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL Initialization Failed\n";
        return false;
    }

    window = SDL_CreateWindow(
        "KapilOS 0.0.1 Alpha",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280,
        720,
        SDL_WINDOW_SHOWN
    );

    if (!window)
    {
        std::cout << "Window Creation Failed\n";
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        std::cout << "Renderer Creation Failed\n";
        return false;
    }

    return true;
}

void Graphics::Run()
{
    bool running = true;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 30, 30, 35, 255);
        SDL_RenderClear(renderer);

        DrawDesktop();

        DesktopIcon myComputer(30,30,"My Computer");
        DesktopIcon settings(30,120,"Settings");
        myComputer.Draw(renderer);
        settings.Draw(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(16);   // ~60 FPS
    }
}

void Graphics::Shutdown()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

void Graphics::DrawDesktop()
{
    // Wallpaper
    SDL_SetRenderDrawColor(renderer, 25, 80, 180, 255);

    SDL_Rect wallpaper =
    {
        0,
        0,
        1280,
        720
    };

    SDL_RenderFillRect(renderer, &wallpaper);

    // Taskbar

    SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);

    SDL_Rect taskbar =
    {
        0,
        680,
        1280,
        40
    };

    SDL_RenderFillRect(renderer, &taskbar);

    // Start Button

    SDL_SetRenderDrawColor(renderer, 0, 120, 215, 255);

    SDL_Rect startButton =
    {
        10,
        685,
        90,
        30
    };

    SDL_RenderFillRect(renderer, &startButton);

    // Desktop Icon

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    
}
