// file manager file .cpp usinf imgui file dialog for the file manager

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

    char pathBuffer[1024];

    snprintf(
        pathBuffer,
        sizeof(pathBuffer),
        "%s",
        currentDirectory.string().c_str()
    );

    ImGui::SetNextItemWidth(
        ImGui::GetContentRegionAvail().x - 220
    );



    ImGui::InputText(
        "##Path",
        pathBuffer,
        sizeof(pathBuffer),
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
        "ExplorerArea",
        ImVec2(0, 0),
        true
    );

    float cellSize =
        iconSize + itemPadding;

    float width =
        ImGui::GetContentRegionAvail().x;

    int columns =
        std::max(
            1,
            (int)(width / cellSize)
        );

    ImGui::Columns(columns, nullptr, false);

    std::filesystem::path folderToOpen;
    bool shouldOpenFolder = false;

    for(size_t i = 0; i < entries.size(); i++)
    {
        const auto& entry = entries[i];

        if(!showHiddenFiles)
        {
            std::string name =
                entry.path().filename().string();

            if(!name.empty() && name[0] == '.')
            {
                continue;
            }
        }

        std::string filename =
            entry.path().filename().string();

        if(searchBuffer[0] != '\0')
        {
            std::string lowerName = filename;
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

            if(lowerName.find(lowerSearch) ==
               std::string::npos)
            {
                continue;
            }
        }

        bool isFolder =
            entry.is_directory();

        const char* icon =
            isFolder ? "📁" : "📄";

        ImGui::PushID((int)i);

bool selected =
    (selectedIndex == (int)i);

    if(selected)
    {
        ImGui::PushStyleColor(
            ImGuiCol_Button,
            ImVec4(0.20f,0.45f,0.90f,0.80f)
        );
    }

    if(ImGui::Button(
        icon,
        ImVec2(iconSize, iconSize)
    ))
    {
        selectedIndex = (int)i;
    }

    if(selected)
    {
        ImGui::PopStyleColor();
    }

        if(ImGui::IsItemHovered() &&
           ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
        {
            if(isFolder)
            {
                folderToOpen = entry.path();
                shouldOpenFolder = true;
            }
        }

        ImGui::TextWrapped(
            "%s",
            filename.c_str()
        );

        ImGui::NextColumn();

        ImGui::PopID();
    }

    ImGui::Columns(1);

    ImGui::EndChild();

    // IMPORTANT:
    // Open the folder AFTER the loop finishes.
    if(shouldOpenFolder)
    {
        OpenDirectory(folderToOpen);
    }
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
