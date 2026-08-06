#include "KapilButton.h"

#include "../../../ThirdParty/imgui/imgui.h"
#include "../../../ThirdParty/imgui/backends/imgui_impl_sdlrenderer2.h"

bool KapilButton::Draw(
    const std::string& id,
    SDL_Texture* icon,
    const std::string& tooltip,
    float width,
    float height,
    bool selected
)
{
    ImGui::PushID(id.c_str());

    if(selected)
    {
        ImGui::PushStyleColor(
            ImGuiCol_Button,
            ImVec4(0.20f, 0.45f, 0.90f, 1.0f)
        );

        ImGui::PushStyleColor(
            ImGuiCol_ButtonHovered,
            ImVec4(0.25f, 0.50f, 0.95f, 1.0f)
        );

        ImGui::PushStyleColor(
            ImGuiCol_ButtonActive,
            ImVec4(0.18f, 0.40f, 0.85f, 1.0f)
        );
    }

    bool clicked =
        ImGui::ImageButton(
            (ImTextureID)icon,
            ImVec2(width, height)
        );

    if(selected)
    {
        ImGui::PopStyleColor(3);
    }

    if(ImGui::IsItemHovered())
    {
        ImGui::SetTooltip(
            "%s",
            tooltip.c_str()
        );
    }

    ImGui::PopID();

    return clicked;
}
