#include <functional>

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

    SDL_Texture* house = nullptr;
    SDL_Texture* folder = nullptr;
    SDL_Texture* gear = nullptr;
    SDL_Texture* search = nullptr;
    SDL_Texture* user = nullptr;
};
