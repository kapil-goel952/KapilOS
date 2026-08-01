cmake_minimum_required(VERSION 3.10)

project(KapilOS)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)


include_directories(
    ${SDL2_INCLUDE_DIRS}

    ../../ThirdParty/imgui
    ../../ThirdParty/imgui/backends
    ../../ThirdParty/ImGuiColorTextEdit
)

set(CMAKE_CXX_STANDARD 17)

add_executable(KapilOS

    main.cpp
    Version.cpp
    SystemInfo.cpp
    Logger.cpp
    Config.cpp

    ../Core/Shell/Shell.cpp

    ../Graphics/Graphics.cpp

    ../UI/Desktop/DesktopUI.cpp
    ../UI/TopBar/TopBarUI.cpp
    ../UI/Dock/DockUI.cpp
    ../UI/Sidebar/SidebarUI.cpp
    ../UI/UIManager/UIManager.cpp
    ../UI/Theme/ThemeManager.cpp
    ../UI/Layout/LayoutManager.cpp
    ../UI/Window/WindowUI.cpp

    ../../ThirdParty/imgui/imgui.cpp
    ../../ThirdParty/imgui/imgui_draw.cpp
    ../../ThirdParty/imgui/imgui_tables.cpp
    ../../ThirdParty/imgui/imgui_widgets.cpp

    ../UI/Widgets/Weather/WeatherWidget.cpp
    ../UI/Widgets/Button/KapilButton.cpp
    ../UI/Widgets/Calendar/CalendarWidget.cpp
    ../UI/Widgets/Status/StatusWidget.cpp


    ../../ThirdParty/imgui/backends/imgui_impl_sdl2.cpp
    ../../ThirdParty/imgui/backends/imgui_impl_sdlrenderer2.cpp
    ../ApplicationManager/ApplicationManager.cpp
    ../Applications/Application/Application.cpp
    ../Applications/FileExplorer/FileExplorerApp.cpp
    ../Applications/Settings/SettingsApp.cpp
    ../Applications/CodeEditor/CodeEditorApp.cpp
    ../Applications/Terminal/TerminalApp.cpp
    ../Applications/Calculator/CalculatorApp.cpp
    ../Core/CalculatorEngine/CalculatorEngine.cpp


    ../AssetManager/AssetManager.cpp

    ../UI/Constants/UIConstants.cpp

    ../UI/Icon/IconManager.cpp

    ../UI/Icon/NanoSVG.cpp

    ../../ThirdParty/ImGuiColorTextEdit/TextEditor.cpp
)

target_link_libraries(
    KapilOS
    ${SDL2_LIBRARIES}
    SDL2_image
)
