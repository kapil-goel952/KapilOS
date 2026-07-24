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
            screenWidth,
            screenHeight
        )
    );

    ImGui::Begin(
        "Desktop",
        nullptr,
        flags
    );

    ImGui::Dummy(
        ImVec2(
            20,
            20
        )
    );

    ImGui::Button(
        "🖥 My Computer",
        ImVec2(
            150,
            45
        )
    );

    ImGui::Spacing();

    ImGui::Button(
        "⚙ Settings",
        ImVec2(
            150,
            45
        )
    );

    ImGui::End();
}
