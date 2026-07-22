#ifndef THEME_MANAGER_H
#define THEME_MANAGER_H

#include "../../../ThirdParty/imgui/imgui.h"

class ThemeManager
{
public:

    static void Apply();

    // Colors

    static ImVec4 Background;

    static ImVec4 Surface;

    static ImVec4 Primary;

    static ImVec4 Secondary;

    static ImVec4 Accent;

    static ImVec4 Text;

    static ImVec4 Border;

    // Radius

    static float WindowRadius;

    static float FrameRadius;

    static float ButtonRadius;

    // Spacing

    static float Padding;

    static float ItemSpacing;
};

#endif
