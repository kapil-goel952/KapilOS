#ifndef FILE_EXPLORER_APP_H
#define FILE_EXPLORER_APP_H

#include "../Application/Application.h"
#include "../../UI/Window/WindowUI.h"

#include <filesystem>
#include <vector>
#include <string>

class FileExplorerApp : public Application
{
public:

    FileExplorerApp();

    void Draw() override;

private:

    //==============================
    // Rendering
    //==============================

    void DrawToolbar();

    void DrawSidebar();

    void DrawExplorer();

    void DrawStatusBar();

    //==============================
    // Filesystem
    //==============================

    void OpenDirectory(
        const std::filesystem::path& path
    );

    void Refresh();

    //==============================
    // Helpers
    //==============================

    bool IsImage(
        const std::filesystem::path& path
    ) const;

    bool IsTextFile(
        const std::filesystem::path& path
    ) const;

private:

    //--------------------------------
    // Window
    //--------------------------------

    WindowUI window;

    //--------------------------------
    // Navigation
    //--------------------------------

    std::filesystem::path currentDirectory;

    std::vector<std::filesystem::directory_entry> entries;

    //--------------------------------
    // Selection
    //--------------------------------

    int selectedIndex = -1;

    //--------------------------------
    // Search
    //--------------------------------

    char searchBuffer[256] = "";

    //--------------------------------
    // View Settings
    //--------------------------------

    float iconSize = 72.0f;

    float itemSpacing = 18.0f;

    //--------------------------------
    // Sidebar
    //--------------------------------

    std::vector<std::filesystem::path> sidebarFolders;

    //--------------------------------
    // Status
    //--------------------------------

    std::size_t folderCount = 0;

    std::size_t fileCount = 0;
};

#endif
