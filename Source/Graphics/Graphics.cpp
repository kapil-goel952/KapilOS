#include "Graphics.h"
#include <SDL2/SDL.h>
#include <iostream>

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
                running = false;
        }

        SDL_SetRenderDrawColor(renderer, 30, 30, 35, 255);

        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }
}

void Graphics::Shutdown()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}
