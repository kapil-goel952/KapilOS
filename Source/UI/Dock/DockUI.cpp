#include <iostream>
#include "../Icon/IconManager.h"
#include "DockUI.h"
//afhkjdsfhlkjashfkjasdgfjg
#include "../../../ThirdParty/imgui/imgui.h"

void DockUI::Initialize(SDL_Renderer* renderer)
{

    

    house = IconManager::LoadIcon(renderer,"house");
    folder = IconManager::LoadIcon(renderer,"folder");
    settings = IconManager::LoadIcon(renderer,"settings");
    search = IconManager::LoadIcon(renderer,"search");
    user   = IconManager::LoadIcon(renderer,"user");
    terminal    = IconManager::LoadIcon(renderer,"terminal");
    calculator = IconManager::LoadIcon(renderer,"calculator");
    browser = IconManager::LoadIcon(renderer,"globe");
    code = IconManager::LoadIcon(renderer,"code");
    music = IconManager::LoadIcon(renderer,"music");

    std::cout << "Dock Icons Loaded\n";

    SDL_SetTextureColorMod(house,255,255,255);
    SDL_SetTextureAlphaMod(house,255);

    SDL_SetTextureBlendMode(house,SDL_BLENDMODE_BLEND);
    SDL_SetTextureBlendMode(folder,SDL_BLENDMODE_BLEND);
    SDL_SetTextureBlendMode(search,SDL_BLENDMODE_BLEND);
    SDL_SetTextureBlendMode(settings,SDL_BLENDMODE_BLEND);
    SDL_SetTextureBlendMode(user,SDL_BLENDMODE_BLEND);

    SDL_SetTextureBlendMode(terminal,SDL_BLENDMODE_BLEND);
    SDL_SetTextureBlendMode(calculator,SDL_BLENDMODE_BLEND);
    SDL_SetTextureBlendMode(browser,SDL_BLENDMODE_BLEND);
    SDL_SetTextureBlendMode(code,SDL_BLENDMODE_BLEND);
    SDL_SetTextureBlendMode(music,SDL_BLENDMODE_BLEND);
}

void DockUI::Draw(
    int screenWidth,
    int screenHeight
)
{


    ImGuiWindowFlags flags =
		ImGuiWindowFlags_NoDecoration |
		ImGuiWindowFlags_NoMove |
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoSavedSettings;
    const int iconCount = 10;
    const float iconSize = 40.0f;
    const float spacing = ImGui::GetStyle().ItemSpacing.x;
    const float dockWidth = 800.0f;
    const float dockHeight = 80.0f;

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

    if(ImGui::ImageButton("settings",(ImTextureID)settings,ImVec2(40,40)))
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

    ImGui::SameLine();

    if(ImGui::ImageButton("browser",(ImTextureID)browser,ImVec2(40,40)))
    {
        if(launchApp)
            launchApp("browser");
    }

    ImGui::SameLine();

    if(ImGui::ImageButton("terminal",(ImTextureID)terminal,ImVec2(40,40)))
    {
        if(launchApp)
            launchApp("terminal");
    }

    ImGui::SameLine();

    if(ImGui::ImageButton("calculator",(ImTextureID)calculator,ImVec2(40,40)))
    {
        if(launchApp)
            launchApp("calculator");
    }

    ImGui::SameLine();

    if(ImGui::ImageButton("code",(ImTextureID)code,ImVec2(40,40)))
    {
        if(launchApp)
            launchApp("code");
    }

    ImGui::SameLine();

    if(ImGui::ImageButton("music",(ImTextureID)music,ImVec2(40,40)))
    {
       if(launchApp)
           launchApp("music");
    }

    ImGui::End();
}

void DockUI::SetLaunchCallback(
    std::function<void(const std::string&)> callback
)
{
    launchApp = callback;
}
