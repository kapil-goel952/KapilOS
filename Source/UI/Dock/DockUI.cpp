#include "../Icon/IconManager.h"
#include "DockUI.h"

#include "../../../ThirdParty/imgui/imgui.h"

void DockUI::Initialize(SDL_Renderer* renderer)
{
    house  = IconManager::LoadIcon(renderer,"house");
    folder = IconManager::LoadIcon(renderer,"folder");
    gear   = IconManager::LoadIcon(renderer,"gear");
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
    ImGui::Image(
        (ImTextureID)house,
        ImVec2(40,40)
    );

    ImGui::SameLine();

    ImGui::Image(
        (ImTextureID)folder,
        ImVec2(40,40)
    );

    ImGui::SameLine();

    ImGui::Image(
        (ImTextureID)gear,
        ImVec2(40,40)
    );

    ImGui::End();
}
