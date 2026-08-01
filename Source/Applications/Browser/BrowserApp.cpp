#include "BrowserApp.h"

#include "../../../ThirdParty/imgui/imgui.h"

BrowserApp::BrowserApp()

    :

    Application("Browser"),

    window(
        "Kapil Browser",
        150,
        60,
        1100,
        700
    )

{

}

void BrowserApp::Draw()
{
    if(!window.Begin())
        return;

    static char url[256] =
        "https://www.google.com";

    ImGui::Button("<");

    ImGui::SameLine();

    ImGui::Button(">");

    ImGui::SameLine();

    ImGui::Button("Refresh");

    ImGui::SameLine();

    ImGui::Button("Home");

    ImGui::SameLine();

    ImGui::SetNextItemWidth(-1);

    ImGui::InputText(
        "##url",
        url,
        sizeof(url)
    );

    ImGui::Separator();

    ImGui::Spacing();

    ImGui::Dummy(ImVec2(0,20));

    ImGui::SetCursorPosX(
        ImGui::GetWindowWidth()*0.35f
    );

    ImGui::Text("Browser Engine Loading...");

    ImGui::Dummy(ImVec2(0,20));

    ImGui::Separator();

    ImGui::Dummy(
        ImVec2(
            ImGui::GetContentRegionAvail().x,
            ImGui::GetContentRegionAvail().y
        )
    );

    window.End();
}
