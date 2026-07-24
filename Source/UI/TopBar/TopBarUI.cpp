#include "TopBarUI.h"
#include "../Layout/LayoutManager.h"
#include "../../../ThirdParty/imgui/imgui.h"

void TopBarUI::Draw(
    int screenWidth
)
{
    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoDecoration |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoSavedSettings |
        ImGuiWindowFlags_NoBringToFrontOnFocus;

    ImGui::SetNextWindowPos(
        ImVec2(0, 0)
    );
    ImGui::SetNextWindowSize(
        ImVec2(
            LayoutManager::ScreenWidth(),
            LayoutManager::TopBarHeight()
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
        LayoutManager::ScreenWidth() * 0.47f
    );

    ImGui::Text("09:41 AM");

    // Right Side
    ImGui::SameLine(
        LayoutManager::ScreenWidth()
        - LayoutManager::Padding() * 18
    );

    ImGui::Text("WiFi  Battery  User");

    ImGui::End();
}
