#include <cstdlib>
#include "ApplicationManager.h"

#include "../Applications/FileExplorer/FileExplorerApp.h"
#include "../Applications/Settings/SettingsApp.h"
#include "../Applications/CodeEditor/CodeEditorApp.h"

ApplicationManager::ApplicationManager()
{
    fileExplorer = std::make_unique<FileExplorerApp>();

    settings = std::make_unique<SettingsApp>();

    codeEditor = std::make_unique<CodeEditorApp>();
}

ApplicationManager::~ApplicationManager() = default;

void ApplicationManager::OpenFileExplorer()
{
    fileExplorer->Open();
}

void ApplicationManager::OpenSettings()
{
    settings->Open();
}
void ApplicationManager::OpenBrowser()
{
    std::system("/opt/firefox/firefox >/dev/null 2>&1 &");
}

void ApplicationManager::OpenTerminal()
{
    std::system("gnome-terminal &");
}

void ApplicationManager::OpenCodeEditor()
{
    codeEditor->Open();
}

void ApplicationManager::OpenCalculator()
{
    std::system("gnome-calculator &");
}

void ApplicationManager::OpenMusic()
{
    std::system("rhythmbox &");
}

void ApplicationManager::OpenVSCode()
{
    std::system("code &");
}

void ApplicationManager::Draw()
{
    if(fileExplorer->IsOpen())
    {
        fileExplorer->Draw();
    }

    if(settings->IsOpen())
    {
        settings->Draw();
    }

    if(codeEditor->IsOpen())
    {
        codeEditor->Draw();
    }
}
