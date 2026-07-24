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

    ImGui::Checkbox(
        "Dark Theme",
        &darkTheme
    );

    ImGui::Checkbox(
        "Animations",
         &animations
    );

    ImGui::Checkbox(
        "Notifications",
        &notifications
    );
}
