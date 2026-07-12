
#include "../Shell/Shell.h"
#include "../Desktop/Desktop.h"
#include <iostream>

void ShowVersion();
void ShowSystemInfo();
void LoadConfig();
void Log(const std::string&);

int main()
{
    ShowVersion();

    LoadConfig();

    ShowSystemInfo();

    Log("KapilOS Started Successfully");

    Desktop desktop;
    desktop.Start();

    Shell shell;
    shell.Start();


    return 0;
}
