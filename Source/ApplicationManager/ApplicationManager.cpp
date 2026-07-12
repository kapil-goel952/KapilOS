#include "ApplicationManager.h"
#include <iostream>

void ApplicationManager::LoadApplications()
{
    std::cout << "\n";
    std::cout << "[Application Manager] Loading Installed Applications...\n";

    std::cout << "   ✓ File Explorer\n";
    std::cout << "   ✓ Terminal\n";
    std::cout << "   ✓ Settings\n";
    std::cout << "   ✓ About KapilOS\n";

    std::cout << "[Application Manager] Done.\n\n";
}
