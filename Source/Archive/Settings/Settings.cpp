#include "Settings.h"
#include <iostream>

void Settings::Open()
{
    std::cout << "\n";
    std::cout << "=============================\n";
    std::cout << "         Settings\n";
    std::cout << "=============================\n";

    std::cout << "[1] Personalization\n";
    std::cout << "[2] Display\n";
    std::cout << "[3] Network\n";
    std::cout << "[4] Sound\n";
    std::cout << "[5] Storage\n";
    std::cout << "[6] About KapilOS\n";
}
