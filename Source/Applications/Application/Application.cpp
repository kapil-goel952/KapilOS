#include "Application.h"

Application::Application(const std::string& appName)
    : name(appName),
      m_open(false)
{
}

const std::string& Application::GetName() const
{
    return name;
}

bool Application::IsOpen() const
{
    return m_open;
}

void Application::Open()
{
    m_open = true;
}

void Application::Close()
{
    m_open = false;
}
