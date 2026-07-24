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
    m_state = WindowState::Normal;
    m_isOpen = true;
    m_isFocused = false;
}

void WindowUI::Draw()
{
    if (!m_isOpen)
    {
        return;
    }
    ImGui::SetNextWindowPos(
        ImVec2(m_x, m_y),
        ImGuiCond_FirstUseEver
    );

    ImGui::SetNextWindowSize(
        ImVec2(m_width, m_height),
        ImGuiCond_FirstUseEver
    );

    ImGui::Begin(
        m_title.c_str(),
        &m_isOpen
    );

    m_isFocused = ImGui::IsWindowFocused();

    ImGui::Text("KapilOS Window");

    ImGui::End();
}
