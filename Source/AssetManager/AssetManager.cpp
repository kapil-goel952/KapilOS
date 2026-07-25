#include <SDL2/SDL_image.h>
#include <iostream>
#include "AssetManager.h"

std::string AssetManager::GetWallpaper(
    const std::string& fileName
)
{
    return "../../Assets/Wallpapers/" + fileName;
}

std::string AssetManager::GetIcon(
    const std::string& fileName
)
{
    return "../../Assets/Icons/" + fileName;
}

std::string AssetManager::GetFont(
    const std::string& fileName
)
{
    return "../../Assets/Fonts/" + fileName;
}

std::string AssetManager::GetSound(
    const std::string& fileName
)
{
    return "../../Assets/Sounds/" + fileName;
}
SDL_Texture* AssetManager::LoadTexture(
    SDL_Renderer* renderer,
    const std::string& path
)
{
    SDL_Texture* texture =
        IMG_LoadTexture(
            renderer,
            path.c_str()
        );

    if (!texture)
    {
        std::cout
            << "Failed to load: "
            << path
            << "\n";

        std::cout
            << IMG_GetError()
            << "\n";
    }

    return texture;
}
