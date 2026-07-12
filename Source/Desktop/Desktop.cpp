#include "../FileExplorer/FileExplorer.h"
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
    WindowManager wm;
    wm.Start();
    ApplicationManager app;
    app.LoadApplications();
    FileExplorer explorer;

    explorer.Open();

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
