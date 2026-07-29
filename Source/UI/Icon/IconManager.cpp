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
        "FontAwesome/" + name + ".png"
    );
    std::cout << "Loading: " << path << std::endl;

    return IMG_LoadTexture(
        renderer,
        path.c_str()
    );
}
