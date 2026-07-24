#include "KapilButton.h"

#include "../../../ThirdParty/imgui/imgui.h"

bool KapilButton::Draw(
    const std::string& id,
    const std::string& icon,
    const std::string& text,
    float width,
    float height
)
{
    std::string label = icon + "##" + id;

    bool clicked =
        ImGui::Button(
            label.c_str(),
            ImVec2(width, height)
        );

    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip("%s", text.c_str());
    }

    return clicked;
}
