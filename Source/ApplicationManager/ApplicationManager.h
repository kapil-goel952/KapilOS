#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include <memory>
#include <vector>

#include "../Applications/Application/Application.h"

class ApplicationManager
{
public:

    void Add(std::unique_ptr<Application> app);

    void Draw();
    ApplicationManager();
private:

    std::vector<std::unique_ptr<Application>> applications;
};

#endif
