#include <cstdlib>
#include "ApplicationManager.h"
#include "../Applications/Calculator/CalculatorApp.h"
#include "../Applications/FileExplorer/FileExplorerApp.h"
#include "../Applications/Settings/SettingsApp.h"
#include "../Applications/CodeEditor/CodeEditorApp.h"

ApplicationManager::ApplicationManager()
{
    fileExplorer = std::make_unique<FileExplorerApp>();

    settings = std::make_unique<SettingsApp>();

    codeEditor = std::make_unique<CodeEditorApp>();

    terminal = std::make_unique<TerminalApp>();

    calculator = std::make_unique<CalculatorApp>();
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
    terminal->Open();
}

void ApplicationManager::OpenCodeEditor()
{
    codeEditor->Open();
}

void ApplicationManager::OpenCalculator()
{
    calculator->Open();
}

void ApplicationManager::OpenMusic()
{
    std::system("rhythmbox &");
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

    if(terminal->IsOpen())
    {
        terminal->Draw();
    }

    if(calculator->IsOpen())
    {
        calculator->Draw();
    }
}
