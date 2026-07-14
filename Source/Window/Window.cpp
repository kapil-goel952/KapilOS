#include "Window.h"
#include <iostream>

Window::Window(std::string title)
{
    m_title = title;
}

void Window::Show()
{
    std::cout << "\n";
    std::cout << "+--------------------------------------+\n";
    std::cout << "| " << m_title << "\n";
    std::cout << "+--------------------------------------+\n";
    std::cout << "|                                      |\n";
    std::cout << "|                                      |\n";
    std::cout << "|                                      |\n";
    std::cout << "|                                      |\n";
    std::cout << "+--------------------------------------+\n";
}
