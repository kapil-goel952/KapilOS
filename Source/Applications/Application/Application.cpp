#include "Application.h"

Application::Application(const std::string& appName)
    : name(appName)
{
}

const std::string& Application::GetName() const
{
    return name;
}
