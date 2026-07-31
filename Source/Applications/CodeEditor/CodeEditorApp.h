#ifndef CODE_EDITOR_APP_H
#define CODE_EDITOR_APP_H

#include "../Application/Application.h"
#include "../../UI/Window/WindowUI.h"

#include "../../../ThirdParty/ImGuiColorTextEdit/TextEditor.h"

class CodeEditorApp : public Application
{
public:

    CodeEditorApp();

    void Draw() override;

private:

    WindowUI window;

    TextEditor editor;
};

#endif
