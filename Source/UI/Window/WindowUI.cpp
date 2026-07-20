#include "WindowUI.h"

#include "../../ThirdParty/imgui/imgui.h"

WindowUI::WindowUI(
    const std::string& title,
    float width,
    float height
)
{
    m_title = title;
    m_width = width;
    m_height = height;
}

void WindowUI::Draw()
{
    ImGui::SetNextWindowSize(
        ImVec2(m_width, m_height),
        ImGuiCond_FirstUseEver
    );

    ImGui::Begin(m_title.c_str());

    ImGui::Text("Window Content");

    ImGui::End();
}
