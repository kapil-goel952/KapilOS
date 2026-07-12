#include "../GUI/GUI.h"
#include "../Graphics/Graphics.h"
#include "../ApplicationManager/ApplicationManager.h"
#include "Desktop.h"
#include "../WindowManager/WindowManager.h"
#include <iostream>

void Desktop::Start()
{
    std::cout << "\n";
    std::cout << "=========================================\n";
    std::cout << "          Welcome to KapilOS\n";
    std::cout << "=========================================\n\n";

    std::cout << "[Desktop] Loading Window Manager...\n";
    std::cout << "[Desktop] Loading Taskbar...\n";
    std::cout << "[Desktop] Loading File Explorer...\n";
    std::cout << "[Desktop] Loading Settings...\n";
    std::cout << "[Desktop] Loading Applications...\n";
    //Windows manager
    WindowManager wm;
    wm.Start();

    //GUI
    Graphics graphics;
    graphics.Initialize();

    GUI gui;
    gui.Start();

    //Application Manager
    ApplicationManager app;
    app.LoadApplications();

    std::cout << "\n";

    std::cout << "-----------------------------------------\n";
    std::cout << "|  My Computer   Settings   Terminal    |\n";
    std::cout << "|                                       |\n";
    std::cout << "|                                       |\n";
    std::cout << "|                                       |\n";
    std::cout << "|                                       |\n";
    std::cout << "-----------------------------------------\n";

    std::cout << "[ Start ]------------------------[12:00]\n";
}
