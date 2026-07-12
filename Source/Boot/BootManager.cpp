#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void loading(const string& message)
{
    cout << message << endl;
    this_thread::sleep_for(chrono::milliseconds(700));
}

int main()
{
    cout << endl;
    cout << "======================================" << endl;
    cout << "            KapilOS v0.0.1" << endl;
    cout << "======================================" << endl;
    cout << endl;

    loading("[BOOT] Initializing Boot Manager...");
    loading("[KERNEL] Loading Kernel...");
    loading("[CORE] Loading Core...");
    loading("[SYSTEM] Loading System Services...");
    loading("[SHELL] Loading Shell...");
    loading("[DESKTOP] Loading Desktop...");
    loading("[APPS] Loading Applications...");

    cout << endl;
    cout << "======================================" << endl;
    cout << "KapilOS Boot Completed Successfully!" << endl;
    cout << "======================================" << endl;

    return 0;
}
