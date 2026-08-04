#include "DesktopUI.h"

#include "../../../ThirdParty/imgui/imgui.h"

void DesktopUI::Draw(
    int screenWidth,
    int screenHeight
)
{
    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoDecoration |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoBringToFrontOnFocus |
        ImGuiWindowFlags_NoBackground;

    ImGui::SetNextWindowPos(
        ImVec2(0, 0)
    );

    ImGui::SetNextWindowSize(
        ImVec2(
            (float)screenWidth,
            (float)screenHeight
        )
    );

    ImGui::Begin(
        "Desktop",
        nullptr,
        flags
    );

    // Desktop is intentionally empty.
    // Wallpaper is rendered by the Graphics engine.

    ImGui::End();
}
