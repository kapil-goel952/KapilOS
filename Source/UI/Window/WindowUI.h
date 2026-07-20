#ifndef WINDOW_UI_H
#define WINDOW_UI_H

#include <string>

class WindowUI
{
public:

    WindowUI(
        const std::string& title,
        float x,
        float y,
        float width,
        float height
    );

    void Draw();

private:

    std::string m_title;

    float m_x;
    float m_y;

    float m_width;
    float m_height;
};

#endif
