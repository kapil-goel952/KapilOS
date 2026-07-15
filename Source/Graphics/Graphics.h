#ifndef GRAPHICS_H
#define GRAPHICS_H

class Graphics
{
public:
    bool Initialize();
    void Run();
    void Shutdown();
        void DrawDesktop();
        void DrawWindow(
        int x,
        int y,
        int width,
        int height
    );
};

#endif
