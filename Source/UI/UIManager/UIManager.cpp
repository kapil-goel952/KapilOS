#include "UIManager.h"

#include "../Layout/LayoutManager.h"

#include "../../../ThirdParty/imgui/imgui.h"

UIManager::UIManager()
{
}

void UIManager::Initialize(SDL_Renderer* renderer)
{
    //--------------------------------------------------
    // Initialize UI Components
    //--------------------------------------------------

    dock.Initialize(renderer);

    sidebar.Initialize(renderer);

    //--------------------------------------------------
    // Dock Launch Callback
    //--------------------------------------------------

    dock.SetLaunchCallback(

        [this](const std::string& app)
        {
            if(app == "file")
            {
                applicationManager.OpenFileExplorer();
            }
            else if(app == "settings")
            {
                applicationManager.OpenSettings();
            }
            else if(app == "browser")
            {
                applicationManager.OpenBrowser();
            }
            else if(app == "terminal")
            {
                applicationManager.OpenTerminal();
            }
            else if(app == "calculator")
            {
                applicationManager.OpenCalculator();
            }
            else if(app == "code")
            {
                applicationManager.OpenCodeEditor();
            }
            else if(app == "music")
            {
                applicationManager.OpenMusic();
            }
        }

    );

    //--------------------------------------------------
    // Sidebar Launch Callback
    //--------------------------------------------------

    sidebar.SetLaunchCallback(

        [this](const std::string& app)
        {
            if(app == "file")
            {
                applicationManager.OpenFileExplorer();
            }
            else if(app == "settings")
            {
                applicationManager.OpenSettings();
            }
            else if(app == "browser")
            {
                applicationManager.OpenBrowser();
            }
            else if(app == "terminal")
            {
                applicationManager.OpenTerminal();
            }
            else if(app == "code")
            {
                applicationManager.OpenCodeEditor();
            }

            //--------------------------------------------------
            // Reserved for future implementation
            //--------------------------------------------------

            else if(app == "home")
            {
            }

            else if(app == "search")
            {
            }

            else if(app == "profile")
            {
            }
        }

    );
}

void UIManager::Draw(
    int screenWidth,
    int screenHeight
)
{
    //--------------------------------------------------
    // Update Layout
    //--------------------------------------------------

    LayoutManager::Update(
        screenWidth,
        screenHeight
    );

    //--------------------------------------------------
    // Main DockSpace
    //--------------------------------------------------

    ImGuiWindowFlags dockspaceFlags =
        ImGuiWindowFlags_NoDocking |
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoBringToFrontOnFocus |
        ImGuiWindowFlags_NoNavFocus |
        ImGuiWindowFlags_NoBackground;

    ImGuiViewport* viewport =
        ImGui::GetMainViewport();

    ImGui::SetNextWindowPos(
        viewport->Pos
    );

    ImGui::SetNextWindowSize(
        viewport->Size
    );

    ImGui::SetNextWindowViewport(
        viewport->ID
    );

    ImGui::PushStyleVar(
        ImGuiStyleVar_WindowRounding,
        0.0f
    );

    ImGui::PushStyleVar(
        ImGuiStyleVar_WindowBorderSize,
        0.0f
    );

    ImGui::SetNextWindowBgAlpha(
        0.0f
    );

    ImGui::Begin(
        "MainDockSpace",
        nullptr,
        dockspaceFlags
    );

    ImGui::PopStyleVar(2);

    ImGui::DockSpace(
        ImGui::GetID("KapilOSDockSpace"),
        ImVec2(0.0f, 0.0f),
        ImGuiDockNodeFlags_PassthruCentralNode
    );

    //--------------------------------------------------
    // Desktop
    //--------------------------------------------------

    desktop.Draw(
        screenWidth,
        screenHeight
    );

    //--------------------------------------------------
    // Top Bar
    //--------------------------------------------------

    topBar.Draw(
        screenWidth
    );

    //--------------------------------------------------
    // Sidebar
    //--------------------------------------------------

    sidebar.Draw(
        screenHeight
    );

    //--------------------------------------------------
    // Dock
    //--------------------------------------------------

    dock.Draw(
        screenWidth,
        screenHeight
    );

    //--------------------------------------------------
    // Widgets
    //--------------------------------------------------

    weather.Draw(
        screenWidth,
        screenHeight
    );

    calendar.Draw(
        screenWidth,
        screenHeight
    );

    status.Draw(
        screenWidth,
        screenHeight
    );

    //--------------------------------------------------
    // Applications
    //--------------------------------------------------

    applicationManager.Draw();

    ImGui::End();
}
