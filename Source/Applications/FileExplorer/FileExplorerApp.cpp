#include "FileExplorerApp.h"

#include "../../../ThirdParty/imgui/imgui.h"

#include <algorithm>
#include <cstdlib>

namespace fs = std::filesystem;

FileExplorerApp::FileExplorerApp()

    :

    Application("File Explorer"),

    window(
        "File Explorer",
        220,
        80,
        900,
        600
    )

{
    const char* home = std::getenv("HOME");

    if(home)
        currentDirectory = home;
    else
        currentDirectory = fs::current_path();

    sidebarFolders.push_back(currentDirectory);

    Refresh();
}

void FileExplorerApp::Refresh()
{
    OpenDirectory(currentDirectory);
}

void FileExplorerApp::OpenDirectory(
    const fs::path& path
)
{
    entries.clear();

    folderCount = 0;
    fileCount = 0;

    if(!fs::exists(path))
        return;

    currentDirectory = path;

    for(const auto& entry : fs::directory_iterator(currentDirectory))
    {
        entries.push_back(entry);

        if(entry.is_directory())
            folderCount++;
        else
            fileCount++;
    }

    std::sort(
        entries.begin(),
        entries.end(),
        [](const auto& a, const auto& b)
        {
            if(a.is_directory() != b.is_directory())
                return a.is_directory();

            return a.path().filename().string()
                <
                b.path().filename().string();
        }
    );
}

bool FileExplorerApp::IsImage(
    const fs::path& path
) const
{
    std::string ext = path.extension().string();

    std::transform(
        ext.begin(),
        ext.end(),
        ext.begin(),
        ::tolower
    );

    return
        ext == ".png" ||
        ext == ".jpg" ||
        ext == ".jpeg" ||
        ext == ".bmp" ||
        ext == ".gif";
}

bool FileExplorerApp::IsTextFile(
    const fs::path& path
) const
{
    std::string ext = path.extension().string();

    std::transform(
        ext.begin(),
        ext.end(),
        ext.begin(),
        ::tolower
    );

    return
        ext == ".txt" ||
        ext == ".cpp" ||
        ext == ".hpp" ||
        ext == ".h" ||
        ext == ".c" ||
        ext == ".md" ||
        ext == ".json" ||
        ext == ".xml" ||
        ext == ".ini";
}

void FileExplorerApp::DrawToolbar()
{
    if(ImGui::Button("<"))
    {

    }

    ImGui::SameLine();

    if(ImGui::Button("^"))
    {
        if(currentDirectory.has_parent_path())
        {
            OpenDirectory(
                currentDirectory.parent_path()
            );
        }
    }

    ImGui::SameLine();

    if(ImGui::Button("R"))
    {
        Refresh();
    }

    ImGui::SameLine();

    std::string path =
        currentDirectory.string();

    ImGui::SetNextItemWidth(
        ImGui::GetContentRegionAvail().x - 220
    );

    ImGui::InputText(
        "##Path",
        path.data(),
        path.capacity() + 1,
        ImGuiInputTextFlags_ReadOnly
    );

    ImGui::SameLine();

    ImGui::SetNextItemWidth(180);

    ImGui::InputTextWithHint(
        "##Search",
        "Search...",
        searchBuffer,
        sizeof(searchBuffer)
    );

    ImGui::Separator();
}

void FileExplorerApp::DrawSidebar()
{
    // Sidebar will be implemented next.
}

void FileExplorerApp::DrawExplorer()
{
    ImGui::BeginChild(
        "Explorer",
        ImVec2(0,0),
        false
    );

    for(size_t i = 0; i < entries.size(); i++)
    {
        const auto& entry = entries[i];

        std::string name =
            entry.path().filename().string();

        if(searchBuffer[0] != '\0')
        {
            std::string lowerName = name;
            std::string lowerSearch = searchBuffer;

            std::transform(
                lowerName.begin(),
                lowerName.end(),
                lowerName.begin(),
                ::tolower
            );

            std::transform(
                lowerSearch.begin(),
                lowerSearch.end(),
                lowerSearch.begin(),
                ::tolower
            );

            if(lowerName.find(lowerSearch)
                ==
                std::string::npos)
            {
                continue;
            }
        }

        std::string label;

        if(entry.is_directory())
            label = "[DIR] ";
        else
            label = "[FILE] ";

        label += name;

        if(ImGui::Selectable(
            label.c_str(),
            selectedIndex == (int)i
        ))
        {
            selectedIndex = i;

            if(entry.is_directory())
            {
                OpenDirectory(entry.path());
            }
        }
    }

    ImGui::EndChild();
}

void FileExplorerApp::DrawStatusBar()
{
    ImGui::Separator();

    ImGui::Text(
        "%zu Folders | %zu Files",
        folderCount,
        fileCount
    );
}

void FileExplorerApp::Draw()
{
    if(!IsOpen())
        return;

    if(window.Begin())
    {
        DrawToolbar();

        DrawSidebar();

        DrawExplorer();

        DrawStatusBar();

        window.End();
    }

    if(!window.IsOpen())
    {
        Close();
    }
}
