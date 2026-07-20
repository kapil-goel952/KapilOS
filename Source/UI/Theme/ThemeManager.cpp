#include "ThemeManager.h"

void ThemeManager::Apply()
{
    ImGuiStyle& style = ImGui::GetStyle();

    style.WindowRounding = 18.0f;
    style.FrameRounding = 12.0f;
    style.ChildRounding = 12.0f;

    style.WindowBorderSize = 0.0f;

    ImVec4* colors = style.Colors;

    colors[ImGuiCol_WindowBg]       = ImVec4(0.10f,0.12f,0.17f,0.92f);

    colors[ImGuiCol_TitleBg]        = ImVec4(0.12f,0.14f,0.20f,1.0f);

    colors[ImGuiCol_TitleBgActive]  = ImVec4(0.14f,0.16f,0.25f,1.0f);

    colors[ImGuiCol_Button]         = ImVec4(0.25f,0.45f,0.90f,1.0f);

    colors[ImGuiCol_ButtonHovered]  = ImVec4(0.35f,0.55f,1.0f,1.0f);

    colors[ImGuiCol_ButtonActive]   = ImVec4(0.20f,0.40f,0.80f,1.0f);
}
