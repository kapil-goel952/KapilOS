#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <string>

class AssetManager
{
public:

    static std::string GetWallpaper(
        const std::string& fileName
    );

    static std::string GetIcon(
        const std::string& fileName
    );

    static std::string GetFont(
        const std::string& fileName
    );

    static std::string GetSound(
        const std::string& fileName
    );
};

#endif

