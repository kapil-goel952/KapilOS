#include "SidebarUI.h"

#include "../Widgets/Button/KapilButton.h"
#include "../Layout/LayoutManager.h"
#include "../Icon/IconManager.h"

#include "../../../ThirdParty/imgui/imgui.h"

#include <utility>

void SidebarUI::Initialize(
    SDL_Renderer* renderer
)
{
    this->renderer = renderer;

    homeIcon      = IconManager::LoadIcon(renderer, "house");
    searchIcon    = IconManager::LoadIcon(renderer, "search");
    folderIcon    = IconManager::LoadIcon(renderer, "folder");
    browserIcon   = IconManager::LoadIcon(renderer, "globe");
    terminalIcon  = IconManager::LoadIcon(renderer, "terminal");
    codeIcon      = IconManager::LoadIcon(renderer, "code");
    settingsIcon  = IconManager::LoadIcon(renderer, "settings");
    userIcon      = IconManager::LoadIcon(renderer, "user");
}

void SidebarUI::SetLaunchCallback(
    std::function<void(const std::string&)> callback
)
{
    launchCallback = std::move(callback);
}

void SidebarUI::Draw(
    int screenHeight
)
{
    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoDecoration |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoScrollbar |
        ImGuiWindowFlags_NoScrollWithMouse;

    ImGui::SetNextWindowPos(
        ImVec2(12, 60)
    );

    ImGui::SetNextWindowSize(
        ImVec2(
            82,
            (float)(screenHeight - 140)
        )
    );

    ImGui::PushStyleVar(
        ImGuiStyleVar_WindowRounding,
        18.0f
    );

    ImGui::PushStyleVar(
        ImGuiStyleVar_WindowPadding,
        ImVec2(8, 12)
    );

    ImGui::PushStyleColor(
        ImGuiCol_WindowBg,
        ImVec4(
            0.10f,
            0.10f,
            0.12f,
            0.92f
        )
    );

    ImGui::Begin(
        "Sidebar",
        nullptr,
        flags
    );

    //--------------------------------------------------
    // HOME
    //--------------------------------------------------

    if(KapilButton::Draw(
        "home",
        homeIcon,
        "Home",
        60,
        60,
        selectedItem == 0
    ))
    {
        selectedItem = 0;

        if(launchCallback)
            launchCallback("home");
    }

    ImGui::Dummy(ImVec2(0, 8));

    //--------------------------------------------------
    // SEARCH
    //--------------------------------------------------

    if(KapilButton::Draw(
        "search",
        searchIcon,
        "Search",
        60,
        60,
        selectedItem == 1
    ))
    {
        selectedItem = 1;

        if(launchCallback)
            launchCallback("search");
    }

    ImGui::Dummy(ImVec2(0, 8));

    //--------------------------------------------------
    // FILES
    //--------------------------------------------------

    if(KapilButton::Draw(
        "files",
        folderIcon,
        "File Explorer",
        60,
        60,
        selectedItem == 2
    ))
    {
        selectedItem = 2;

        if(launchCallback)
            launchCallback("file");
    }

    ImGui::Dummy(ImVec2(0, 8));

    //--------------------------------------------------
    // BROWSER
    //--------------------------------------------------

    if(KapilButton::Draw(
        "browser",
        browserIcon,
        "Browser",
        60,
        60,
        selectedItem == 3
    ))
    {
        selectedItem = 3;

        if(launchCallback)
            launchCallback("browser");
    }

    ImGui::Dummy(ImVec2(0, 8));

    //--------------------------------------------------
    // TERMINAL
    //--------------------------------------------------

    if(KapilButton::Draw(
        "terminal",
        terminalIcon,
        "Terminal",
        60,
        60,
        selectedItem == 4
    ))
    {
        selectedItem = 4;

        if(launchCallback)
            launchCallback("terminal");
    }

    ImGui::Dummy(ImVec2(0, 8));

    //--------------------------------------------------
    // CODE
    //--------------------------------------------------

    if(KapilButton::Draw(
        "code",
        codeIcon,
        "Code Editor",
        60,
        60,
        selectedItem == 5
    ))
    {
        selectedItem = 5;

        if(launchCallback)
            launchCallback("code");
    }

    ImGui::Dummy(ImVec2(0, 8));

    //--------------------------------------------------
    // SETTINGS
    //--------------------------------------------------

    if(KapilButton::Draw(
        "settings",
        settingsIcon,
        "Settings",
        60,
        60,
        selectedItem == 6
    ))
    {
        selectedItem = 6;

        if(launchCallback)
            launchCallback("settings");
    }

    //--------------------------------------------------
    // PUSH PROFILE TO BOTTOM
    //--------------------------------------------------

    float remain =
        ImGui::GetContentRegionAvail().y;

    if(remain > 80)
    {
        ImGui::Dummy(
            ImVec2(0, remain - 70)
        );
    }

    //--------------------------------------------------
    // PROFILE
    //--------------------------------------------------

    if(KapilButton::Draw(
        "profile",
        userIcon,
        "Profile",
        60,
        60,
        selectedItem == 7
    ))
    {
        selectedItem = 7;

        if(launchCallback)
            launchCallback("profile");
    }

    ImGui::End();

    ImGui::PopStyleColor();
    ImGui::PopStyleVar(2);
}
