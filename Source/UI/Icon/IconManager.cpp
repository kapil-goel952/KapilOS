#include "IconManager.h"

#include "../../AssetManager/AssetManager.h"

#include <SDL2/SDL_image.h>

#include <iostream>

//=====================================================
// Static Members
//=====================================================

SDL_Renderer* IconManager::renderer = nullptr;

std::unordered_map
<
    std::string,
    SDL_Texture*
> IconManager::icons;

//=====================================================
// Initialize
//=====================================================

void IconManager::Initialize(
    SDL_Renderer* rendererPtr
)
{
    renderer = rendererPtr;

    // Preload all commonly used icons

    LoadIcon(renderer, "house");
    LoadIcon(renderer, "folder");
    LoadIcon(renderer, "settings");
    LoadIcon(renderer, "search");
    LoadIcon(renderer, "terminal");
    LoadIcon(renderer, "calculator");
    LoadIcon(renderer, "globe");
    LoadIcon(renderer, "code");
    LoadIcon(renderer, "music");
    LoadIcon(renderer, "user");
}

//=====================================================
// Shutdown
//=====================================================

void IconManager::Shutdown()
{
    for(auto& icon : icons)
    {
        if(icon.second)
        {
            SDL_DestroyTexture(icon.second);
        }
    }

    icons.clear();
}

//=====================================================
// Load Icon
//=====================================================

SDL_Texture* IconManager::LoadIcon(
    SDL_Renderer* renderer,
    const std::string& name
)
{
    // Already loaded?

    auto it = icons.find(name);

    if(it != icons.end())
    {
        return it->second;
    }

    std::string path =
        AssetManager::GetIcon(
            name + ".png"
        );

    std::cout
        << "Loading: "
        << path
        << std::endl;

    SDL_Texture* texture =
        IMG_LoadTexture(
            renderer,
            path.c_str()
        );

    if(texture)
    {
        std::cout
            << "Texture OK"
            << std::endl;

        icons[name] = texture;
    }
    else
    {
        std::cout
            << "Texture FAILED"
            << std::endl;

        std::cout
            << IMG_GetError()
            << std::endl;
    }

    return texture;
}

//=====================================================
// Get Icon
//=====================================================

SDL_Texture* IconManager::Get(
    const std::string& name
)
{
    auto it = icons.find(name);

    if(it == icons.end())
    {
        return nullptr;
    }

    return it->second;
}
