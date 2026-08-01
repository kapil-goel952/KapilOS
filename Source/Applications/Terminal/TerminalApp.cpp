#include "TerminalApp.h"

#include "../../../ThirdParty/imgui/imgui.h"

#include <cstring>

TerminalApp::TerminalApp()

    :

    Application("Terminal"),

    window(
        "Terminal",
        220,
        120,
        700,
        450
    )

{
    input[0] = '\0';

    output =
        "KapilOS Terminal\n"
        "Type a Linux command and press ENTER.\n\n";
}

void TerminalApp::Draw()
{
    if(window.Begin())
    {
        ImGui::BeginChild(
            "Output",
            ImVec2(0,-35),
            true
        );

        ImGui::TextUnformatted(
            output.c_str()
        );

        ImGui::EndChild();

        ImGui::SetNextItemWidth(-1);

        if(
            ImGui::InputText(
                "##Command",
                input,
                sizeof(input),
                ImGuiInputTextFlags_EnterReturnsTrue
            )
        )
        {
            output += "> ";
            output += input;
            output += "\n";

            output += shell.Execute(input);

            output += "\n";

            std::memset(
                input,
                0,
                sizeof(input)
            );
        }

        window.End();
    }
}
