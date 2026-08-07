#include "../Layout/UIStyle.h"
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

void SidebarUI::Draw()
{
    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoDecoration |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoScrollbar |
        ImGuiWindowFlags_NoScrollWithMouse;

    ImGui::SetNextWindowPos(
        ImVec2(
            UIStyle::SidebarPadding(),
            UIStyle::TopBarHeight() + 10.0f
        )
    );

    ImGui::SetNextWindowSize(
        ImVec2(
            UIStyle::SidebarWidth(),
            UIStyle::ScreenHeight()
            - UIStyle::TopBarHeight()
            - 20.0f
        )
    );

    float sidebarWidth =
    UIStyle::SidebarWidth();

    float buttonSize =
        sidebarWidth * 0.62f;

    float spacing =
        sidebarWidth * 0.12f;

    ImGui::PushStyleVar(
        ImGuiStyleVar_WindowRounding,
        UIStyle::SidebarRadius()
    );

    ImGui::PushStyleVar(
        ImGuiStyleVar_WindowPadding,
    	ImVec2(
	    (sidebarWidth - buttonSize) * 0.5f,
	    UIStyle::SidebarPadding()
  	)
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
        UIStyle::SidebarIconSize(),
	UIStyle::SidebarIconSize(),
        selectedItem == 0
    ))
    {
        selectedItem = 0;

        if(launchCallback)
            launchCallback("home");
    }

    ImGui::Dummy(
        ImVec2(
            0,
            UIStyle::SidebarSpacing()
        )
    );

    //--------------------------------------------------
    // SEARCH
    //--------------------------------------------------

    if(KapilButton::Draw(
        "search",
        searchIcon,
        "Search",
    	UIStyle::SidebarIconSize(),
	UIStyle::SidebarIconSize(),
        selectedItem == 1
    ))
    {
        selectedItem = 1;

        if(launchCallback)
            launchCallback("search");
    }

    ImGui::Dummy(
        ImVec2(
            0,
            UIStyle::SidebarSpacing()
        )
    );

    //--------------------------------------------------
    // FILES
    //--------------------------------------------------

    if(KapilButton::Draw(
        "files",
        folderIcon,
        "File Explorer",
        UIStyle::SidebarIconSize(),
	UIStyle::SidebarIconSize(),
        selectedItem == 2
    ))
    {
        selectedItem = 2;

        if(launchCallback)
            launchCallback("file");
    }

    ImGui::Dummy(
        ImVec2(
            0,
            UIStyle::SidebarSpacing()
        )
    );

    //--------------------------------------------------
    // BROWSER
    //--------------------------------------------------

    if(KapilButton::Draw(
        "browser",
        browserIcon,
        "Browser",
        UIStyle::SidebarIconSize(),
	UIStyle::SidebarIconSize(),
        selectedItem == 3
    ))
    {
        selectedItem = 3;

        if(launchCallback)
            launchCallback("browser");
    }

    ImGui::Dummy(
        ImVec2(
            0,
            UIStyle::SidebarSpacing()
        )
    );

    //--------------------------------------------------
    // TERMINAL
    //--------------------------------------------------

    if(KapilButton::Draw(
        "terminal",
        terminalIcon,
        "Terminal",
        UIStyle::SidebarIconSize(),
	UIStyle::SidebarIconSize(),
        selectedItem == 4
    ))
    {
        selectedItem = 4;

        if(launchCallback)
            launchCallback("terminal");
    }

    ImGui::Dummy(
        ImVec2(
            0,
            UIStyle::SidebarSpacing()
        )
    );

    //--------------------------------------------------
    // CODE
    //--------------------------------------------------

    if(KapilButton::Draw(
        "code",
        codeIcon,
        "Code Editor",
        UIStyle::SidebarIconSize(),
	UIStyle::SidebarIconSize(),
        selectedItem == 5
    ))
    {
        selectedItem = 5;

        if(launchCallback)
            launchCallback("code");
    }

    ImGui::Dummy(
        ImVec2(
            0,
            UIStyle::SidebarSpacing()
        )
    );

    //--------------------------------------------------
    // SETTINGS
    //--------------------------------------------------

    if(KapilButton::Draw(
        "settings",
        settingsIcon,
        "Settings",
        UIStyle::SidebarIconSize(),
	UIStyle::SidebarIconSize(),
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

    if(
        remain >
        UIStyle::SidebarIconSize()
        + UIStyle::SidebarSpacing()
    )
    {
        ImGui::Dummy(
            ImVec2(0, remain -  UIStyle::SidebarIconSize()    -   UIStyle::SidebarSpacing())
        );
    }

    //--------------------------------------------------
    // PROFILE
    //--------------------------------------------------

    if(KapilButton::Draw(
        "profile",
        userIcon,
        "Profile",
        UIStyle::SidebarIconSize(),
        UIStyle::SidebarIconSize(),
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
