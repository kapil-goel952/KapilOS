#include "FileExplorer.h"
#include <iostream>

void FileExplorer::Open()
{
    std::cout << "\n";
    std::cout << "=============================\n";
    std::cout << "      File Explorer\n";
    std::cout << "=============================\n";

    std::cout << "[Desktop]\n";
    std::cout << "[Documents]\n";
    std::cout << "[Downloads]\n";
    std::cout << "[Pictures]\n";
    std::cout << "[Music]\n";
    std::cout << "[Videos]\n";
}
