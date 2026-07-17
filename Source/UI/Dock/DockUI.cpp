#include "DockUI.h"

#include "../../../ThirdParty/imgui/imgui.h"

void DockUI::Draw()
{
    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoDecoration |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoScrollbar;

    ImGui::SetNextWindowPos(ImVec2(380, 650));
    ImGui::SetNextWindowSize(ImVec2(520, 60));

    ImGui::Begin("Dock", nullptr, flags);

    ImGui::Button("Apps");
    ImGui::SameLine();

    ImGui::Button("Browser");
    ImGui::SameLine();

    ImGui::Button("Files");
    ImGui::SameLine();

    ImGui::Button("Terminal");
    ImGui::SameLine();

    ImGui::Button("Settings");

    ImGui::End();
}
