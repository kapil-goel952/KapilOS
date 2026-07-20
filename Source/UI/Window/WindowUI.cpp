#include "WindowUI.h"

#include "../../ThirdParty/imgui/imgui.h"

WindowUI::WindowUI(
    const std::string& title,
    float x,
    float y,
    float width,
    float height
)
{
    m_title = title;

    m_x = x;
    m_y = y;

    m_width = width;
    m_height = height;
}

void WindowUI::Draw()
{
    ImGui::SetNextWindowPos(
        ImVec2(m_x, m_y),
        ImGuiCond_FirstUseEver
    );

    ImGui::SetNextWindowSize(
        ImVec2(m_width, m_height),
        ImGuiCond_FirstUseEver
    );

    ImGui::Begin(m_title.c_str());

    ImGui::Text("KapilOS Window");

    ImGui::End();
}
