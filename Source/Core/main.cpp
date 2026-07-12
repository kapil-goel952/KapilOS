#include "../Desktop/Desktop.h"
#include <iostream>

void ShowVersion();
void ShowSystemInfo();
void LoadConfig();
void Log(const std::string&);

int main()
{
    Desktop desktop;

   desktop.Start();
    ShowVersion();

    LoadConfig();

    ShowSystemInfo();

    Log("KapilOS Started Successfully");

    return 0;
}
