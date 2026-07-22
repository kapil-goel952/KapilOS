#include "ThemeManager.h"

// =======================================================
// KapilOS Theme Values
// =======================================================

// Colors

ImVec4 ThemeManager::Background = ImVec4(0.08f, 0.09f, 0.12f, 1.00f);

ImVec4 ThemeManager::Surface = ImVec4(0.12f, 0.13f, 0.18f, 0.95f);

ImVec4 ThemeManager::Primary = ImVec4(0.18f, 0.45f, 0.95f, 1.00f);

ImVec4 ThemeManager::Secondary = ImVec4(0.22f, 0.24f, 0.30f, 1.00f);

ImVec4 ThemeManager::Accent = ImVec4(0.00f, 0.75f, 1.00f, 1.00f);

ImVec4 ThemeManager::Text = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);

ImVec4 ThemeManager::Border = ImVec4(0.28f, 0.30f, 0.38f, 1.00f);

// Radius

float ThemeManager::WindowRadius = 18.0f;

float ThemeManager::FrameRadius = 12.0f;

float ThemeManager::ButtonRadius = 12.0f;

// Spacing

float ThemeManager::Padding = 12.0f;

float ThemeManager::ItemSpacing = 10.0f;

// =======================================================
// Apply Theme
// =======================================================

void ThemeManager::Apply()
{
    ImGuiStyle& style = ImGui::GetStyle();

    // ---------- Radius ----------

    style.WindowRounding = WindowRadius;

    style.FrameRounding = FrameRadius;

    style.ChildRounding = FrameRadius;

    style.PopupRounding = FrameRadius;

    style.GrabRounding = FrameRadius;

    style.ScrollbarRounding = FrameRadius;

    style.TabRounding = FrameRadius;

    // ---------- Borders ----------

    style.WindowBorderSize = 0.0f;

    style.ChildBorderSize = 0.0f;

    style.PopupBorderSize = 0.0f;

    // ---------- Padding ----------

    style.WindowPadding = ImVec2(Padding, Padding);

    style.FramePadding = ImVec2(12, 8);

    style.ItemSpacing = ImVec2(ItemSpacing, ItemSpacing);

    style.ItemInnerSpacing = ImVec2(8, 6);

    // ---------- Colors ----------

    ImVec4* colors = style.Colors;

    colors[ImGuiCol_WindowBg] = Background;

    colors[ImGuiCol_ChildBg] = Background;

    colors[ImGuiCol_PopupBg] = Surface;

    colors[ImGuiCol_TitleBg] = Surface;

    colors[ImGuiCol_TitleBgActive] = Surface;

    colors[ImGuiCol_Button] = Primary;

    colors[ImGuiCol_ButtonHovered] = Accent;

    colors[ImGuiCol_ButtonActive] = Primary;

    colors[ImGuiCol_FrameBg] = Secondary;

    colors[ImGuiCol_FrameBgHovered] = Primary;

    colors[ImGuiCol_FrameBgActive] = Accent;

    colors[ImGuiCol_Border] = Border;

    colors[ImGuiCol_Text] = Text;

    colors[ImGuiCol_Header] = Primary;

    colors[ImGuiCol_HeaderHovered] = Accent;

    colors[ImGuiCol_HeaderActive] = Primary;
}
