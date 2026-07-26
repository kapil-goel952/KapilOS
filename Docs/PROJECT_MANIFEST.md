# KapilOS Project Manifest

## 1. Project Identity
KapilOS is a custom desktop operating system project being built on top of the Linux kernel. It is not a Linux distribution clone and not a simple ImGui demo. The goal is to create a fully branded, responsive, modular desktop experience with its own UI, window management, applications, theme system, layout system, asset system, and future ISO packaging.

## 2. Primary Goal
The immediate goal is to finish KapilOS as quickly as possible using mature prebuilt tools wherever they make sense. Stability and speed come first. Custom implementations will be added later only where they provide real value.

## 3. Long-Term Goal
KapilOS should eventually boot directly into its own desktop session, with the user seeing only KapilOS branding and experience, while Linux remains underneath as the kernel and low-level base.

## 4. Development Philosophy
Use stable third-party libraries for low-level problems.
Build only the parts that define KapilOS itself.
Keep architecture modular.
Avoid hardcoded UI sizes.
Prefer responsive design.
Never rewrite working code unless there is a strong architectural reason.

## 5. Current Tech Stack
C++17
SDL2
SDL2_image
Dear ImGui Docking Branch
NanoSVG
CMake
Ubuntu WSL for development

## 6. Core Systems
Graphics
UIManager
ThemeManager
LayoutManager
AssetManager
ApplicationManager
Desktop
TopBar
Sidebar
Dock
Applications

## 7. Current UI Design Philosophy
Sidebar is a system-navigation panel.
Dock is for pinned/running apps.
TopBar is for status and global controls.
Desktop shows wallpaper and desktop items.
All sizes should be responsive.

## 8. Current Priority
Complete KapilOS quickly using prebuilt tools.
Finish the desktop UI.
Add usable applications.
Prepare for a bootable ISO later.

## 9. Current SVG Plan
KapilOS will use real SVG icons, not emoji placeholders.
NanoSVG is already cloned and tested.
The rendering pipeline for icons is planned, not yet complete.

## 10. Future Work
SVG icon engine
Texture cache
More applications
Start/Kapil menu
Notifications
Quick settings
Window polish
ISO generation

## 11. File Workflow
main.cpp starts the program.
Graphics owns SDL initialisation, window creation, renderer creation, the wallpaper texture, the main loop, and shutdown.
UIManager owns the permanent desktop UI and calls Desktop, TopBar, Sidebar, Dock, widgets, and ApplicationManager every frame.
ApplicationManager owns applications such as File Explorer and Settings.
AssetManager owns asset path building and future asset loading.
LayoutManager owns responsive UI values and must be used instead of hardcoded sizes.
ThemeManager owns styling, rounding, colours, and the overall visual identity.

## 12. Rendering Workflow
Program start:
main -> Graphics::Initialize -> Graphics::Run

Per frame:
SDL events -> ImGui new frame -> UIManager::Draw -> Desktop/UI components -> ApplicationManager -> ImGui render -> SDL present

The wallpaper is rendered through Graphics and the UI is rendered through ImGui.

## 13. Current Implemented Features
SDL window creation
SDL renderer creation
ImGui integration
Docking branch working
Wallpaper loading working
Responsive LayoutManager started
AssetManager started
ThemeManager working
Desktop, TopBar, Sidebar, Dock, widgets, and applications already exist in basic form

## 14. Current Design Decisions
Sidebar is a system-navigation area.
Dock is for running and pinned apps.
TopBar is for status and global actions.
Desktop is for wallpaper and desktop items.
No component should use fixed dimensions unless absolutely necessary.
No component should access SDL directly unless it is a low-level engine module.

## 15. Current Development Priority
Finish KapilOS quickly using mature prebuilt tools first.
Use custom implementations only when they provide real long-term value.
Complete a usable desktop shell.
Add real app flow.
Prepare for a bootable ISO later.

## 16. SVG Icon Direction
KapilOS should use real SVG icons instead of emoji placeholders.
NanoSVG is already cloned and tested.
The SVG icon rendering pipeline is planned and will be integrated into the existing AssetManager and rendering architecture.
