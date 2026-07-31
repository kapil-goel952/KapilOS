#include "CodeEditorApp.h"

#include "../../../ThirdParty/imgui/imgui.h"

CodeEditorApp::CodeEditorApp()

    :

    Application("Code Editor"),

    window(
        "Code Editor",
        120,
        70,
        1000,
        700
    )
{
    editor.SetLanguageDefinition(
        TextEditor::LanguageDefinition::CPlusPlus()
    );

    editor.SetPalette(
        TextEditor::GetDarkPalette()
    );

    editor.SetText(
R"(#include <iostream>

int main()
{
    std::cout << "Hello KapilOS!" << std::endl;
    return 0;
}
)");
}

void CodeEditorApp::Draw()
{
    if(window.Begin())
    {
        editor.Render(
            "Editor",
            ImVec2(-1,-1)
        );

        window.End();
    }
}
