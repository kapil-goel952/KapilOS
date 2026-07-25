#include "../Widgets/Button/KapilButton.h"
#include "../Layout/LayoutManager.h"
#include "SidebarUI.h"

#include "../../../ThirdParty/imgui/imgui.h"

void SidebarUI::Draw(
    int screenHeight
)
{
    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoDecoration |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoResize;

    ImGui::SetNextWindowPos(
        ImVec2(10, 60)
    );

    ImGui::SetNextWindowSize(
        ImVec2(
            70,
            (float)(screenHeight - 130)
        )
    );

    ImGui::Begin(
        "Sidebar",
        nullptr,
        flags
    );

    KapilButton::Draw(
        "home",
        "🏠",
        "Home",
        LayoutManager::SidebarWidth() * 0.75f,
        LayoutManager::SidebarWidth() * 0.75f
    );

    ImGui::Spacing();
    KapilButton::Draw(
        "search",
        "🔍"  ,
        "Search",
        LayoutManager::SidebarWidth() * 0.75f,
        LayoutManager::SidebarWidth() * 0.75f
    );

    ImGui::Spacing();
    KapilButton::Draw(
        "files",
        "📁",
        "Files",
        LayoutManager::SidebarWidth() * 0.75f,
        LayoutManager::SidebarWidth() * 0.75f
    );

    ImGui::Spacing();
    KapilButton::Draw(
        "settings",
        "⚙",
        "Settings",
        LayoutManager::SidebarWidth() * 0.75f,
        LayoutManager::SidebarWidth() * 0.75f
    );


    ImGui::Spacing();

    KapilButton::Draw(
        "profile",
        "👤",
        "Profile",
        LayoutManager::SidebarWidth() * 0.75f,
        LayoutManager::SidebarWidth() * 0.75f
    );

    ImGui::End();
}
