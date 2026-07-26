# KapilOS Architecture

## 1. High-Level Idea
KapilOS is a custom desktop operating system experience built on top of the Linux kernel. The Linux kernel provides the low-level hardware, driver, memory, process, and filesystem base. KapilOS provides the visible desktop experience, UI, window management, applications, branding, and future session/ISO packaging.

The architecture is intentionally modular so the project can grow without turning into a mess.

## 2. Main Layers

### 2.1 Linux Kernel Layer
This layer is not written by KapilOS. It is reused as the foundation.
It handles:
- hardware support
- drivers
- scheduling
- memory management
- process management
- filesystems
- networking
- boot compatibility

### 2.2 KapilOS Core Layer
This is the control layer written for the project.
It contains:
- graphics bootstrap
- UI coordination
- layout logic
- theme logic
- asset handling
- application handling
- desktop UI structure

### 2.3 KapilOS UI Layer
This is the visible desktop experience.
It contains:
- desktop
- top bar
- sidebar
- dock
- widgets
- app windows
- future launcher and control panels

### 2.4 KapilOS Application Layer
This is where desktop apps live.
Examples:
- File Explorer
- Settings
- future terminal
- browser
- notes
- system tools

## 3. Runtime Flow

### Startup Flow
main.cpp
-> Graphics::Initialize()
-> SDL window + SDL renderer
-> ImGui context
-> Theme setup
-> wallpaper loading
-> Graphics::Run()

### Frame Flow
SDL events
-> ImGui new frame
-> UIManager::Draw()
-> Desktop
-> TopBar
-> Sidebar
-> Dock
-> Widgets
-> ApplicationManager
-> ImGui render
-> SDL present

This flow must stay stable.

## 4. Graphics Responsibility
Graphics is the low-level rendering and lifecycle module.

It owns:
- SDL_Window
- SDL_Renderer
- wallpaper texture
- main loop
- initialize / shutdown logic

It must not contain desktop application logic.

It should only know how to create the window, create the renderer, load the wallpaper, run the render loop, and clean up.

## 5. UIManager Responsibility
UIManager is the main desktop controller.

It owns the permanent desktop UI and decides what is drawn every frame.

Current children:
- Desktop
- TopBar
- Sidebar
- Dock
- Widgets
- ApplicationManager

UIManager also owns the ImGui DockSpace setup.

## 6. Desktop Responsibility
Desktop is the wallpaper-facing desktop area.

It shows:
- background wallpaper
- desktop items
- basic desktop interaction space

Desktop should remain transparent so wallpaper stays visible.

## 7. TopBar Responsibility
TopBar is the top system bar.

It is used for:
- KapilOS title
- time
- system indicators
- future quick actions
- future notification access
- future search access

It is not the main app launcher.

## 8. Sidebar Responsibility
Sidebar is a vertical system-navigation panel.

It is NOT a taskbar.
It is NOT the dock.

It should behave more like a system navigation strip / GNOME-style favourite launcher area.

Planned functions:
- desktop/home
- search
- files
- workspace / running apps
- notifications
- quick settings
- settings
- profile

## 9. Dock Responsibility
Dock is the bottom-centered application strip.

It is for:
- pinned apps
- running apps
- frequently used apps

It should feel closer to macOS-style dock behaviour than a taskbar.

## 10. ApplicationManager Responsibility
ApplicationManager owns all desktop applications.

It should manage:
- application lifecycle
- application drawing
- application list
- future launching and routing

It should not know low-level renderer details.

## 11. AssetManager Responsibility
AssetManager is the central asset entry point.

Current state:
- returns paths for wallpapers, icons, fonts, sounds
- can load textures through SDL_image

Future state:
- texture cache
- SVG loading
- font loading
- sound loading
- resource lifetime management

No UI module should manually build asset paths once AssetManager is fully in place.

## 12. LayoutManager Responsibility
LayoutManager is the single responsive layout system.

It stores the current screen size and produces values such as:
- top bar height
- sidebar width
- dock width
- dock height
- padding
- radius
- icon size
- spacing
- scaled X/Y values

No UI module should hardcode sizes when LayoutManager can provide the value.

## 13. ThemeManager Responsibility
ThemeManager owns the visual styling of KapilOS.

It controls:
- colours
- rounding
- frames
- borders
- visual mood
- future theme variants

ThemeManager should remain the single place for appearance-level decisions.

## 14. Current Design Philosophy
KapilOS is being designed as a real desktop shell, not as a demo UI.

That means:
- modular code
- reusable components
- responsive layout
- prebuilt libraries where appropriate
- clean future replacement points
- no unnecessary reinvention

## 15. Current UI Philosophy
The UI must adapt to resolution changes.

No component should depend on a fixed screen size.

Where possible:
- use percentages
- use LayoutManager helpers
- use design constants
- keep relative spacing

This is required for different monitors and future ISO installs.

## 16. Current SVG Direction
KapilOS is moving toward real SVG icons.

Reason:
- emoji placeholders are not professional
- icons should scale cleanly
- the icon system should be future-proof

NanoSVG has already been cloned and tested.

The planned icon flow is:
SVG file -> NanoSVG -> rasterized output -> SDL texture -> AssetManager -> UI

## 17. Separation of Responsibilities
The separation is important and must be preserved.

Graphics:
- bootstraps SDL and rendering

UIManager:
- orchestrates desktop UI

AssetManager:
- manages assets

LayoutManager:
- manages responsive sizes

ThemeManager:
- manages style

ApplicationManager:
- manages apps

UI components:
- render the interface

No class should take over responsibilities that belong to another layer.

## 18. Why This Architecture Exists
The goal is not just to make something that runs.
The goal is to keep KapilOS maintainable as it grows.

If architecture is clean now:
- later apps become easier
- later UI changes become easier
- later ISO packaging becomes easier
- later Linux session integration becomes easier
- later replacement of specific third-party pieces becomes possible without rewriting everything

## 19. Future Direction
The architecture is intentionally preparing for:
- better icon system
- texture caching
- animations
- notifications
- quick settings
- launcher
- system panels
- ISO packaging
- boot-to-KapilOS session flow
