#include "DockUI.h"

#include "../../../ThirdParty/imgui/imgui.h"

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

    ImGui::Button("🌐", ImVec2(55, 50));

    ImGui::SameLine();

    ImGui::Button("📁", ImVec2(55, 50));

    ImGui::SameLine();

    ImGui::Button("⚙", ImVec2(55, 50));

    ImGui::SameLine();

    ImGui::Button("🖥", ImVec2(55, 50));

    ImGui::SameLine();

    ImGui::Button("🎵", ImVec2(55, 50));

    ImGui::End();
}
