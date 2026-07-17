#include "TopBarUI.h"

#include "../../../ThirdParty/imgui/imgui.h"

void TopBarUI::Draw()
{
    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoDecoration |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoResize;

    ImGui::SetNextWindowPos(ImVec2(0,0));
    ImGui::SetNextWindowSize(ImVec2(1280,40));

    ImGui::Begin("TopBar",nullptr,flags);

    ImGui::Text("KapilOS");

    ImGui::SameLine(500);

    ImGui::Text("09:41 AM");

    ImGui::SameLine(1100);

    ImGui::Text("WiFi  Battery  User");

    ImGui::End();
}
