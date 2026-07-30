#ifndef WINDOW_UI_H
#define WINDOW_UI_H

#include <string>

enum class WindowState
{
    Normal,
    Minimized,
    Maximized,
    FullScreen,
    Zen
};

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

    bool Begin();

    void End();
    bool IsOpen() const;

private:

    std::string m_title;

    float m_x;
    float m_y;

    float m_width;
    float m_height;

    WindowState m_state;

    bool m_isOpen;
    bool m_isFocused;
};

#endif
