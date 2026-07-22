#include "ApplicationManager.h"

#include "../Applications/FileExplorer/FileExplorerApp.h"
#include "../Applications/Settings/SettingsApp.h"

ApplicationManager::ApplicationManager()
{
    Add(std::make_unique<FileExplorerApp>());

    Add(std::make_unique<SettingsApp>());
}

void ApplicationManager::Add(std::unique_ptr<Application> app)
{
    applications.push_back(std::move(app));
}

void ApplicationManager::Draw()
{
    for (auto& app : applications)
    {
        app->Draw();
    }
}
