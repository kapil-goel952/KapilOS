#include "IconManager.h"

#include "../../AssetManager/AssetManager.h"

#include <SDL2/SDL_image.h>

SDL_Texture* IconManager::LoadIcon(
    SDL_Renderer* renderer,
    const std::string& name
)
{
    std::string path =
    AssetManager::GetIcon(
         name + ".png"
    );
    std::cout << "Loading: " << path << std::endl;

    SDL_Texture* texture =
    IMG_LoadTexture(
        renderer,
        path.c_str()
    );

    if(texture)
    {
        std::cout
        << "Texture OK\n";
    }
    else
    {
        std::cout
            << "Texture FAILED\n";

        std::cout
            << IMG_GetError()
            << "\n";
    }

    return texture;
}
