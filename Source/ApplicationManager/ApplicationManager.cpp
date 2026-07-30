#include "ApplicationManager.h"

#include "../Applications/FileExplorer/FileExplorerApp.h"
#include "../Applications/Settings/SettingsApp.h"

ApplicationManager::ApplicationManager()
{

}

void ApplicationManager::Add(std::unique_ptr<Application> app)
{
    applications.push_back(std::move(app));
}

void ApplicationManager::OpenFileExplorer()
{
    Add(
        std::make_unique<FileExplorerApp>()
    );
}

void ApplicationManager::OpenSettings()
{
    Add(
        std::make_unique<SettingsApp>()
    );
}

void ApplicationManager::Draw()
{
    for (auto& app : applications)
    {
        app->Draw();
    }
}
