#include "TopBarUI.h"

#include "../../../ThirdParty/imgui/imgui.h"

void TopBarUI::Draw(
    int screenWidth
)
{
    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoDecoration |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoResize;

    ImGui::SetNextWindowPos(
        ImVec2(0, 0)
    );

    ImGui::SetNextWindowSize(
        ImVec2(
            (float)screenWidth,
            40
        )
    );

    ImGui::Begin(
        "TopBar",
        nullptr,
        flags
    );

    // Left Side
    ImGui::Text("KapilOS");

    // Center
    ImGui::SameLine(
        screenWidth * 0.45f
    );

    ImGui::Text("09:41 AM");

    // Right Side
    ImGui::SameLine(
        screenWidth - 180
    );

    ImGui::Text("WiFi  Battery  User");

    ImGui::End();
}
