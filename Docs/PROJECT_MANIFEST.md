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
