#include "FileExplorerApp.h"

#include "../../../ThirdParty/imgui/imgui.h"

FileExplorerApp::FileExplorerApp()

    :

    Application("File Explorer"),

    window(
        "File Explorer",
        250,
        120,
        500,
        350
    )

{
}

void FileExplorerApp::Draw()
{
    window.Draw();

    ImGui::Text("This is File Explorer.");

    ImGui::Separator();

    ImGui::BulletText("Desktop");
    ImGui::BulletText("Documents");
    ImGui::BulletText("Downloads");
    ImGui::BulletText("Pictures");
}
