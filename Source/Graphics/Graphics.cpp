// =======================================================
// KapilOS Graphics Engine
// =======================================================

#include "Graphics.h"

#include "../UI/Theme/ThemeManager.h"
#include "../UI/UIManager/UIManager.h"

#include <SDL2/SDL.h>

#include "../../ThirdParty/imgui/imgui.h"
#include "../../ThirdParty/imgui/backends/imgui_impl_sdl2.h"
#include "../../ThirdParty/imgui/backends/imgui_impl_sdlrenderer2.h"

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
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );

    if (!window)
    {
        std::cout << "Window Creation Failed\n";
        return false;
    }

    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (!renderer)
    {
        std::cout << "Renderer Creation Failed\n";
        return false;
    }

    // Dear ImGui

    IMGUI_CHECKVERSION();

    ImGui::CreateContext();

    ImGui::GetIO();

    ImGui::StyleColorsDark();

    ThemeManager::Apply();

    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);

    ImGui_ImplSDLRenderer2_Init(renderer);

    return true;
}

void Graphics::Run()
{
    bool running = true;

    SDL_Event event;

    UIManager ui;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);

            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        ui.Draw();

        ImGui::Render();

        SDL_SetRenderDrawColor(renderer, 18, 22, 32, 255);

        SDL_RenderClear(renderer);

        ImGui_ImplSDLRenderer2_RenderDrawData(
            ImGui::GetDrawData(),
            renderer
        );

        SDL_RenderPresent(renderer);
    }
}

void Graphics::Shutdown()
{
    ImGui_ImplSDLRenderer2_Shutdown();

    ImGui_ImplSDL2_Shutdown();

    ImGui::DestroyContext();

    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);

    SDL_Quit();
}
