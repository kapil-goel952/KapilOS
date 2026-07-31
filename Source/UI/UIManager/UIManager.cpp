#include "../Layout/LayoutManager.h"
#include "UIManager.h"
#include "../../../ThirdParty/imgui/imgui.h"
UIManager::UIManager()
{
}

void UIManager::Initialize(SDL_Renderer* renderer)
{
    dock.Initialize(renderer);

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

            else if(app == "home")
            {
                // TODO
            }

            else if(app == "search")
            {
                // TODO
            }

            else if(app == "user")
            {
                // TODO
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

	    else if(app == "music")
            {
                applicationManager.OpenMusic();
	    }

	    else if(app == "code")
		{
                    applicationManager.OpenCodeEditor();
            }
        }

    );
}

void UIManager::Draw(
    int screenWidth,
    int screenHeight
)
{
    LayoutManager::Update(
        screenWidth,
        screenHeight
    );

    ImGuiWindowFlags dockspaceFlags =
    ImGuiWindowFlags_NoDocking |
    ImGuiWindowFlags_NoTitleBar |
    ImGuiWindowFlags_NoCollapse |
    ImGuiWindowFlags_NoResize |
    ImGuiWindowFlags_NoMove |
    ImGuiWindowFlags_NoBringToFrontOnFocus |
    ImGuiWindowFlags_NoNavFocus |
    ImGuiWindowFlags_NoBackground;

    ImGuiViewport* viewport = ImGui::GetMainViewport();

    ImGui::SetNextWindowPos(viewport->Pos);
    ImGui::SetNextWindowSize(viewport->Size);
    ImGui::SetNextWindowViewport(viewport->ID);

    ImGui::PushStyleVar(
        ImGuiStyleVar_WindowRounding,
        0.0f
    );

    ImGui::PushStyleVar(
        ImGuiStyleVar_WindowBorderSize,
        0.0f
    );

    ImGui::SetNextWindowBgAlpha(0.0f);

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

    desktop.Draw(
        screenWidth,
        screenHeight
    );

    topBar.Draw(
        screenWidth
    );

    sidebar.Draw(
        screenHeight
    );

    dock.Draw(
        screenWidth,
        screenHeight
    );

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


    applicationManager.Draw();

    ImGui::End();
}
