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
        ImGuiWindowFlags_NoBringToFrontOnFocus;

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

    ImGui::Text("KapilOS Desktop");

    ImGui::Button(
        "My Computer",
        ImVec2(120, 40)
    );

    ImGui::Button(
        "Settings",
        ImVec2(120, 40)
    );

    ImGui::End();
}
