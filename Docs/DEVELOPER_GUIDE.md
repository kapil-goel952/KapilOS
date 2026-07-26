# KapilOS Developer Guide

## 1. Purpose
This document explains how to understand, extend, and maintain KapilOS without breaking its architecture.

KapilOS is a modular desktop operating system project built on top of the Linux kernel. The codebase is intentionally split into clear responsibility layers so that the project can grow without turning into a mess.

## 2. How to Think About the Project
When working on KapilOS, always think in layers:

- low-level runtime and rendering
- asset handling
- layout and responsiveness
- theme and styling
- desktop shell UI
- applications

Do not mix responsibilities across these layers unless there is a strong technical reason.

## 3. Main Development Rule
The current priority is to finish KapilOS quickly using mature prebuilt tools wherever they make sense.

Use prebuilt libraries first.
Build custom systems later only when they add real value.

Do not waste time rewriting stable things just for the sake of ownership.

## 4. Current Codebase Flow
The program starts in `main.cpp`.

Flow:
- `main.cpp`
- `Graphics`
- `ImGui`
- `UIManager`
- desktop UI components
- `ApplicationManager`
- applications
- render to screen

This flow is the backbone of the project and should not be casually changed.

## 5. Important Modules

### 5.1 Graphics
Graphics owns:
- SDL window
- SDL renderer
- main loop
- ImGui startup and shutdown
- wallpaper texture
- frame rendering

Graphics should stay low-level.
It should not contain application rules.

### 5.2 UIManager
UIManager owns the permanent desktop UI.
It coordinates:
- Desktop
- TopBar
- Sidebar
- Dock
- widgets
- ApplicationManager

If the screen has to be drawn every frame, UIManager is usually the place that coordinates it.

### 5.3 AssetManager
AssetManager is the central entry point for assets.

Current purpose:
- build asset paths
- load textures through SDL_image

Future purpose:
- cache textures
- load SVGs
- load fonts
- load sounds
- manage asset lifetime

Do not manually hardcode asset paths in random files once AssetManager supports the needed asset type.

### 5.4 LayoutManager
LayoutManager is the responsive UI brain.

It stores current resolution and provides calculated values such as:
- top bar height
- sidebar width
- dock dimensions
- icon size
- spacing
- padding
- corner radius

When a UI element needs a size, ask whether LayoutManager should own that logic.

### 5.5 ThemeManager
ThemeManager owns styling.
Use it for:
- colours
- dark theme decisions
- borders
- rounding
- visual consistency

### 5.6 ApplicationManager
ApplicationManager owns desktop applications.
Examples:
- File Explorer
- Settings
- future apps

The application manager should not know low-level SDL internals.

## 6. Responsive Design Rules
Never use fixed UI sizes unless they are absolutely necessary.

Avoid hardcoded values like:
- 40
- 50
- 70
- 150
- 420

If a size is repeated or important, move it into:
- `UIConstants`
- `LayoutManager`
- a reusable widget helper

The UI must work across:
- small laptop screens
- standard desktop screens
- high-resolution displays
- future ISO installs on different machines

## 7. Asset Handling Rules
KapilOS is moving toward a central asset workflow.

Current direction:
- wallpapers are loaded through AssetManager
- icons will later follow the same pattern
- fonts and sounds will also follow the same pattern

Future asset flow should look like this:

asset name
-> AssetManager
-> loader
-> texture or runtime resource
-> UI

Avoid direct asset path construction in UI components once AssetManager owns the relevant asset type.

## 8. SVG Icon Direction
KapilOS should use real SVG icons instead of emoji placeholders.

Reason:
- emoji glyph coverage is inconsistent
- SVG icons scale cleanly
- icons should remain crisp on all resolutions
- the icon pipeline should be future-proof

NanoSVG has already been cloned and tested.
The next development step is to integrate SVG rendering into the KapilOS asset pipeline.

Target pipeline:
SVG file
-> NanoSVG parse
-> rasterize
-> SDL texture
-> AssetManager
-> UI

## 9. Sidebar Purpose
Sidebar is not the dock.
Sidebar is not the top bar.
Sidebar is not a taskbar.

Sidebar is a vertical system-navigation panel.

Planned role:
- desktop/home
- search
- files
- workspace overview
- notifications
- quick settings
- settings
- profile

Treat Sidebar as a system hub, not as a duplicate launcher.

## 10. Dock Purpose
Dock is the bottom application strip.

Planned role:
- pinned apps
- running apps
- frequently used apps

Dock should feel closer to a macOS-style dock than a traditional taskbar.

## 11. TopBar Purpose
TopBar is the top system bar.

Planned role:
- title
- time
- indicators
- quick actions
- access point for future system controls

## 12. Desktop Purpose
Desktop is the wallpaper-driven work area.

Planned role:
- wallpaper
- desktop items
- clean visual space
- future desktop interactions

Desktop should remain transparent enough for wallpaper visibility.

## 13. Project Behaviour Rules
When helping with KapilOS, always:

- continue from the existing project state
- preserve stable architecture
- avoid unnecessary rewrites
- prefer ready-to-paste code
- tell exactly which file to edit
- tell exactly what to replace
- keep explanations practical
- think long-term

Do not restart the project.
Do not ignore already completed work.
Do not suggest abandoning working code without a clear reason.

## 14. Working With Code
When giving code:
- keep the format clean
- keep the file boundaries clear
- avoid mixing unrelated changes
- prefer one file at a time for larger changes
- ensure the code fits the current architecture

If a change affects multiple files, explain the order clearly.

## 15. Debugging Workflow
Use this workflow:
1. make the change
2. build the project
3. run the executable
4. inspect errors
5. fix the exact broken layer

Do not guess randomly when a build or runtime issue occurs.
Track the layer where the problem belongs.

## 16. What KapilOS Is Becoming
KapilOS is evolving into a real desktop shell with:
- its own look
- its own layout rules
- its own apps
- its own navigation style
- its own asset pipeline
- its own responsive UI system

The goal is not to create a demo.
The goal is to build a usable desktop operating system experience.

## 17. Current Priority
The current priority is:
- finish the desktop shell quickly
- keep the codebase clean
- keep the UI responsive
- integrate real icons
- polish the sidebar, dock, and top bar
- prepare for a bootable ISO later

## 18. Future Direction
After KapilOS becomes usable, the project can grow into:
- a bootable ISO
- a full session experience
- more applications
- a more advanced icon system
- animation systems
- later internal custom replacements where useful

But the immediate goal is still speed plus stability.
