
cmake_minimum_required(VERSION 3.10)

project(KapilOS)

set(CMAKE_CXX_STANDARD 17)

add_executable(KapilOS

    main.cpp
    Version.cpp
    SystemInfo.cpp
    Logger.cpp
    Config.cpp

    ../Desktop/Desktop.cpp
    ../WindowManager/WindowManager.cpp
    ../ApplicationManager/ApplicationManager.cpp
    ../FileExplorer/FileExplorer.cpp
    ../Settings/Settings.cpp
    ../Shell/Shell.cpp
    ../GUI/GUI.cpp
    ../Graphics/Graphics.cpp
    ../Window/Window.cpp
)
