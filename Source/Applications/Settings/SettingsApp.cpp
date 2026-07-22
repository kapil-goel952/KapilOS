#include "SettingsApp.h"

#include "../../../ThirdParty/imgui/imgui.h"

SettingsApp::SettingsApp()

    :

    Application("Settings"),

    window(
        "Settings",
        820,
        180,
        350,
        260
    )

{
}

void SettingsApp::Draw()
{
    window.Draw();

    ImGui::Text("KapilOS Settings");

    ImGui::Separator();

    ImGui::Checkbox("Dark Theme", nullptr);

    ImGui::Checkbox("Animations", nullptr);

    ImGui::Checkbox("Notifications", nullptr);
}
