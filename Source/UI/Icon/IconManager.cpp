#include "IconManager.h"

#include "../../AssetManager/AssetManager.h"

#include "../../../ThirdParty/nanosvg/src/nanosvg.h"
#include "../../../ThirdParty/nanosvg/src/nanosvgrast.h"

#include <iostream>


SDL_Texture* IconManager::LoadIcon(
    SDL_Renderer* renderer,
    const std::string& name
)
{

    if(!renderer)
    {
        std::cout
        << "Renderer is NULL\n";

        return nullptr;
    }


    std::string path =
        AssetManager::GetIcon(
            "FontAwesome/" + name + ".svg"
        );


    std::cout
    << "Loading SVG: "
    << path
    << "\n";



    NSVGimage* image =
        nsvgParseFromFile(
            path.c_str(),
            "px",
            96
        );


    if(!image)
    {
        std::cout
        << "SVG load failed\n";

        return nullptr;
    }



    int width = 128;
    int height = 128;



    unsigned char* data =
        new unsigned char[
            width *
            height *
            4
        ];



    NSVGrasterizer* rast =
        nsvgCreateRasterizer();



    if(!rast)
    {
        std::cout
        << "Rasterizer creation failed\n";

        nsvgDelete(image);

        delete[] data;

        return nullptr;
    }



    nsvgRasterize(
        rast,
        image,
        0,
        0,
        1,
        data,
        width,
        height,
        width * 4
    );



    SDL_Surface* surface =
        SDL_CreateRGBSurfaceFrom(
            data,
            width,
            height,
            32,
            width * 4,

            // RGBA FIX
            0x00FF0000,
            0x0000FF00,
            0x000000FF,
            0xFF000000
        );



    if(!surface)
    {
        std::cout
        << "Surface creation failed: "
        << SDL_GetError()
        << "\n";


        nsvgDeleteRasterizer(rast);

        nsvgDelete(image);

        delete[] data;


        return nullptr;
    }



    SDL_SetSurfaceBlendMode(
        surface,
        SDL_BLENDMODE_BLEND
    );



    SDL_Texture* texture =
        SDL_CreateTextureFromSurface(
            renderer,
            surface
        );



    if(!texture)
    {
        std::cout
        << "Texture creation failed: "
        << SDL_GetError()
        << "\n";
    }
    else
    {
        std::cout
        << "Texture created successfully\n";
    }



    SDL_FreeSurface(surface);


    nsvgDeleteRasterizer(rast);


    nsvgDelete(image);


    delete[] data;



    return texture;

}
