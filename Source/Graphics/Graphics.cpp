// =======================================================
// KapilOS Graphics Engine v1
// =======================================================

#include "Graphics.h"

#include "../AssetManager/AssetManager.h"
#include "../UI/Theme/ThemeManager.h"
#include "../UI/UIManager/UIManager.h"
#include "../UI/Icon/IconManager.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../../ThirdParty/imgui/imgui.h"
#include "../../ThirdParty/imgui/backends/imgui_impl_sdl2.h"
#include "../../ThirdParty/imgui/backends/imgui_impl_sdlrenderer2.h"

#include <iostream>

// -------------------------------------------------------
// Initialize Graphics Engine
// -------------------------------------------------------

bool Graphics::Initialize()
{
    //----------------------------------------------------
    // SDL
    //----------------------------------------------------

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout
            << "SDL Initialization Failed\n";

        return false;
    }

    //----------------------------------------------------
    // SDL IMAGE
    //----------------------------------------------------

    if (!(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG)))
    {
        std::cout
            << "SDL_image Initialization Failed\n";

        return false;
    }

    //----------------------------------------------------
    // Window
    //----------------------------------------------------

    m_window =
        SDL_CreateWindow(
            "KapilOS 0.0.1 Alpha",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            1280,
            720,
            SDL_WINDOW_SHOWN |
            SDL_WINDOW_RESIZABLE
        );

    if (!m_window)
    {
        std::cout
            << "Window Creation Failed\n";

        return false;
    }

    //----------------------------------------------------
    // Renderer
    //----------------------------------------------------

    m_renderer =
        SDL_CreateRenderer(
            m_window,
            -1,
            SDL_RENDERER_ACCELERATED |
            SDL_RENDERER_PRESENTVSYNC
        );

    if (!m_renderer)
    {
        std::cout
            << "Renderer Creation Failed\n";

        return false;
    }

    std::cout
        << "Renderer Initialized\n";

    //----------------------------------------------------
    // Wallpaper
    //----------------------------------------------------

    m_wallpaper =
        IMG_LoadTexture(
            m_renderer,
            AssetManager::GetWallpaper(
                "wallpaper.jpg"
            ).c_str()
        );

	    if (!m_wallpaper)
    {
        std::cout
            << "Wallpaper Load Failed\n";
    }
    else
    {
        std::cout
            << "Wallpaper Loaded\n";
    }

    //----------------------------------------------------
    // Icons
    //----------------------------------------------------

    m_homeIcon =
        IconManager::LoadIcon(
            m_renderer,
            "house"
        );

    if (!m_homeIcon)
    {
        std::cout
            << "Home Icon Failed\n";
    }
    else
    {
        std::cout
            << "Home Icon Loaded\n";
    }

    //----------------------------------------------------
    // ImGui
    //----------------------------------------------------

    IMGUI_CHECKVERSION();

    ImGui::CreateContext();

    ImGuiIO& io =
        ImGui::GetIO();

    io.ConfigFlags |=
        ImGuiConfigFlags_DockingEnable;

    ImGui::StyleColorsDark();

    ThemeManager::Apply();

    ImGui_ImplSDL2_InitForSDLRenderer(
        m_window,
        m_renderer
    );

    ImGui_ImplSDLRenderer2_Init(
        m_renderer
    );

    uiManager.Initialize(m_renderer);

    std::cout
        << "Graphics Engine Ready\n";

    return true;
}

void Graphics::Run()
{
    bool running = true;

    SDL_Event event;

    UIManager uiManager;

    while (running)
    {
        // --------------------------------
        // Events
        // --------------------------------

        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);

            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        // --------------------------------
        // Window Size
        // --------------------------------

        int screenWidth;
        int screenHeight;

        SDL_GetWindowSize(
            m_window,
            &screenWidth,
            &screenHeight
        );

        // --------------------------------
        // Start ImGui Frame
        // --------------------------------

        ImGui_ImplSDLRenderer2_NewFrame();

        ImGui_ImplSDL2_NewFrame();

        ImGui::NewFrame();

        uiManager.Draw(
            screenWidth,
            screenHeight
        );

        ImGui::Render();

        // --------------------------------
        // Clear Screen
        // --------------------------------

        SDL_SetRenderDrawColor(
            m_renderer,
            30,
            30,
            35,
            255
        );

        SDL_RenderClear(
            m_renderer
        );

        // --------------------------------
        // Draw Wallpaper
        // --------------------------------

        if (m_wallpaper)
        {
            SDL_RenderCopy(
                m_renderer,
                m_wallpaper,
                nullptr,
                nullptr
            );
        }

        // --------------------------------
        // Draw Test Icon
        // --------------------------------

        if (m_homeIcon)
        {
            SDL_Rect iconRect;

            iconRect.x = 100;
            iconRect.y = 100;
            iconRect.w = 128;
            iconRect.h = 128;

            SDL_RenderCopy(
                m_renderer,
                m_homeIcon,
                nullptr,
                &iconRect
            );
        }

        // --------------------------------
        // Draw ImGui
        // --------------------------------

        ImGui_ImplSDLRenderer2_RenderDrawData(
            ImGui::GetDrawData(),
            m_renderer
        );

        // --------------------------------
        // Present
        // --------------------------------

        SDL_RenderPresent(
            m_renderer
        );
    }
}

void Graphics::Shutdown()
{
    if (m_wallpaper)
    {
        SDL_DestroyTexture(
            m_wallpaper
        );
    }
    if(m_homeIcon)
    {
        SDL_DestroyTexture(
            m_homeIcon
        );
    }

    ImGui_ImplSDLRenderer2_Shutdown();

    ImGui_ImplSDL2_Shutdown();

    ImGui::DestroyContext();

    SDL_DestroyRenderer(
        m_renderer
    );

    SDL_DestroyWindow(
        m_window
    );

    IMG_Quit();

    SDL_Quit();
}
