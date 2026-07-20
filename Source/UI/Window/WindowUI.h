#ifndef WINDOW_UI_H
#define WINDOW_UI_H

#include <string>

class WindowUI
{
public:

    WindowUI(
        const std::string& title,
        float width,
        float height
    );

    void Draw();

private:

    std::string m_title;

    float m_width;
    float m_height;
};

#endif
