#include "../Graphics/Graphics.h"

int main()
{
    Graphics graphics;

    if (!graphics.Initialize())
    {
        return -1;
    }

    graphics.Run();
    graphics.Shutdown();

    return 0;
}
