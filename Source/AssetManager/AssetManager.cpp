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
