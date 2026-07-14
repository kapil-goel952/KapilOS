cmake_minimum_required(VERSION 3.10)

project(KapilOS)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)

add_executable(KapilOS
    main.cpp
    Version.cpp
    SystemInfo.cpp
    Logger.cpp
    Config.cpp

    ../Desktop/Desktop.cpp
    ../WindowManager/WindowManager.cpp
    ../Window/Window.cpp
    ../ApplicationManager/ApplicationManager.cpp
    ../FileExplorer/FileExplorer.cpp
    ../Settings/Settings.cpp
    ../Shell/Shell.cpp
    ../GUI/GUI.cpp
    ../Graphics/Graphics.cpp
    ../DesktopIcons/DesktopIcon.cpp
)

target_link_libraries(KapilOS ${SDL2_LIBRARIES})
