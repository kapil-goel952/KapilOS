#include "Shell.h"
#include "../FileExplorer/FileExplorer.h"
#include "../Settings/Settings.h"

#include <iostream>
#include <string>

void Shell::Start()
{
    std::string command;

    FileExplorer explorer;
    Settings settings;

    std::cout << "\n";
    std::cout << "KapilOS Shell Started\n";
    std::cout << "Type 'help' for commands.\n\n";

    while (true)
    {
        std::cout << "KapilOS> ";
        std::getline(std::cin, command);

        if (command == "help")
        {
            std::cout << "\nCommands\n";
            std::cout << "help\n";
            std::cout << "apps\n";
            std::cout << "explorer\n";
            std::cout << "settings\n";
            std::cout << "exit\n\n";
        }

        else if (command == "apps")
        {
            std::cout << "\nInstalled Applications\n";
            std::cout << "- File Explorer\n";
            std::cout << "- Settings\n";
            std::cout << "- Terminal\n";
            std::cout << "- About KapilOS\n\n";
        }

        else if (command == "explorer")
        {
            explorer.Open();
        }

        else if (command == "settings")
        {
            settings.Open();
        }

        else if (command == "exit")
        {
            std::cout << "\nShutting Down KapilOS...\n";
            break;
        }

        else
        {
            std::cout << "Unknown Command\n";
        }
    }
}
