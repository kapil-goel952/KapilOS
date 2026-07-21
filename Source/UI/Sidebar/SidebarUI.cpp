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

    ImGui::Button(
        "🏠",
        ImVec2(50, 50)
    );

    ImGui::Spacing();

    ImGui::Button(
        "🔍",
        ImVec2(50, 50)
    );

    ImGui::Spacing();

    ImGui::Button(
        "📁",
        ImVec2(50, 50)
    );

    ImGui::Spacing();

    ImGui::Button(
        "⚙",
        ImVec2(50, 50)
    );

    ImGui::Spacing();

    ImGui::Button(
        "😊",
        ImVec2(50, 50)
    );

    ImGui::End();
}
