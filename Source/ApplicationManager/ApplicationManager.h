#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include <memory>
#include <vector>

#include "../Applications/Application/Application.h"

class ApplicationManager
{
public:
     ApplicationManager();

    void Add(std::unique_ptr<Application> app);

    void OpenFileExplorer();

    void OpenSettings();

    void Draw();
private:

    std::vector<std::unique_ptr<Application>> applications;
};

#endif
