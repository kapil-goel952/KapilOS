#ifndef KAPIL_BUTTON_H
#define KAPIL_BUTTON_H

#include <string>

class KapilButton
{
public:

    static bool Draw(
        const std::string& id,
        const std::string& icon,
        const std::string& text,
        float width,
        float height
    );

};

#endif
