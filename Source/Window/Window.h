#ifndef WINDOW_H
#define WINDOW_H

#include <string>

class Window
{
public:
    Window(std::string title);

    void Show();

private:
    std::string m_title;
};

#endif
