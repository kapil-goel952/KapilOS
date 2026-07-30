#include "../Icon/IconManager.h"
#include "DockUI.h"

#include "../../../ThirdParty/imgui/imgui.h"

void DockUI::Initialize(SDL_Renderer* renderer)
{
    house = IconManager::LoadIcon(renderer,"house");

    if(house)
        std::cout<<"House Loaded\n";
    else
        std::cout<<"House Failed\n";

    folder = IconManager::LoadIcon(renderer,"folder");

    if(folder)
        std::cout<<"Folder Loaded\n";
    else
        std::cout<<"Folder Failed\n";

    gear = IconManager::LoadIcon(renderer,"gear");

    if(gear)
        std::cout<<"Gear Loaded\n";
    else
        std::cout<<"Gear Failed\n";
    search = IconManager::LoadIcon(renderer,"search");

    user   = IconManager::LoadIcon(renderer,"user");

    SDL_SetTextureBlendMode(house, SDL_BLENDMODE_BLEND);
    SDL_SetTextureBlendMode(folder, SDL_BLENDMODE_BLEND);
    SDL_SetTextureBlendMode(gear, SDL_BLENDMODE_BLEND);
}

void DockUI::Draw(
    int screenWidth,
    int screenHeight
)
{
    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoDecoration |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoResize;

    const float dockWidth = 420.0f;
    const float dockHeight = 70.0f;

    ImGui::SetNextWindowPos(
        ImVec2(
            (screenWidth - dockWidth) * 0.5f,
            screenHeight - dockHeight - 20.0f
        )
    );

    ImGui::SetNextWindowSize(
        ImVec2(
            dockWidth,
            dockHeight
        )
    );

    ImGui::Begin(
        "Dock",
        nullptr,
        flags
    );

    if(ImGui::ImageButton("home",(ImTextureID)house,ImVec2(40,40)))
    {
        if(launchApp)
            launchApp("home");
    }

    ImGui::SameLine();

    if(ImGui::ImageButton("folder",(ImTextureID)folder,ImVec2(40,40)))
    {
        if(launchApp)
             launchApp("file");
    }

    ImGui::SameLine();

    if(ImGui::ImageButton("gear",(ImTextureID)gear,ImVec2(40,40)))
    {
        if(launchApp)
            launchApp("settings");
    }

    ImGui::SameLine();

    if(ImGui::ImageButton("search",(ImTextureID)search,ImVec2(40,40)))
    {
        if(launchApp)
            launchApp("search");
    }

    ImGui::SameLine();

    if(ImGui::ImageButton("user",(ImTextureID)user,ImVec2(40,40)))
    {
        if(launchApp)
            launchApp("user");
    }

    ImGui::End();
}

void DockUI::SetLaunchCallback(
    std::function<void(const std::string&)> callback
)
{
    launchApp = callback;
}
