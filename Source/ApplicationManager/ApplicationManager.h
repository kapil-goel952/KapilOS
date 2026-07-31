#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include <memory>
#include <vector>
#include "../Applications/Application/Application.h"

class FileExplorerApp;
class SettingsApp;
class CodeEditorApp;

class ApplicationManager
{
public:

    ApplicationManager();

    ~ApplicationManager();


    void Draw();

    void OpenFileExplorer();

    void OpenSettings();

    void OpenBrowser();

    void OpenTerminal();

    void OpenCodeEditor();

    void OpenCalculator();

    void OpenMusic();



private:

    std::unique_ptr<FileExplorerApp> fileExplorer;

    std::unique_ptr<SettingsApp> settings;
    std::unique_ptr<CodeEditorApp> codeEditor;
};

#endif
