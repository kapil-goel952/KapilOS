 #ifndef DOCK_UI_H
#define DOCK_UI_H

#include <SDL2/SDL.h>
#include <functional>
#include <string>

class DockUI
{
public:

    void Initialize(SDL_Renderer* renderer);

    void Draw(
        int screenWidth,
        int screenHeight
    );

    void SetLaunchCallback(
        std::function<void(const std::string&)> callback
    );

private:

    std::function<void(const std::string&)> launchApp;

    SDL_Texture* house  = nullptr;
    SDL_Texture* folder = nullptr;
    SDL_Texture* settings   = nullptr;
    SDL_Texture* search = nullptr;
    SDL_Texture* user   = nullptr;
    SDL_Texture* terminal = nullptr;
    SDL_Texture* calculator = nullptr;
    SDL_Texture* browser = nullptr;
    SDL_Texture* code = nullptr;
    SDL_Texture* music = nullptr;
};

#endif
