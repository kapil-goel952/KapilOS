# KapilOS

KapilOS is a custom desktop operating system project built on top of the Linux kernel.

It is not meant to be a Linux distro clone.
It is meant to become a fully branded, modular, responsive desktop OS experience with its own UI, window flow, layout system, asset system, and applications.

## What KapilOS Is
KapilOS is a desktop shell / operating system experience being built with a strong focus on:
- clean architecture
- responsive UI
- reusable components
- fast development using stable prebuilt tools
- long-term maintainability

## What KapilOS Is Not
KapilOS is not:
- a copied Ubuntu desktop
- a random ImGui demo
- a throwaway UI prototype
- a kernel project from scratch

The Linux kernel is used underneath as the stable low-level base.
KapilOS provides the visible experience above it.

## Main Tech Stack
- C++17
- SDL2
- SDL2_image
- Dear ImGui Docking Branch
- NanoSVG
- CMake
- Ubuntu WSL for development

## Main Goals
### Short-Term
- finish the desktop shell quickly
- keep the UI responsive
- remove hardcoded layout values
- integrate real SVG icons
- polish sidebar, dock, and top bar
- keep the project stable and buildable

### Long-Term
- generate a bootable ISO
- boot directly into KapilOS
- make KapilOS the visible desktop session
- gradually improve internals where needed
- make the project maintainable as it grows

## Current UI Philosophy
KapilOS UI is structured into clear roles:

- **TopBar**: system status and global controls
- **Sidebar**: system navigation and favourite areas
- **Dock**: pinned and running applications
- **Desktop**: wallpaper-facing workspace
- **Widgets**: reusable small UI modules
- **Applications**: real desktop apps

## Current Architecture Summary
The project follows this general flow:

main.cpp
-> Graphics
-> ImGui
-> UIManager
-> Desktop / TopBar / Sidebar / Dock / Widgets
-> ApplicationManager
-> Applications
-> SDL present

## Current Responsive Layout System
KapilOS uses a LayoutManager + UIConstants approach so the UI can scale across different resolutions.

The goal is to avoid hardcoded values and make the interface adapt naturally to:
- laptops
- desktops
- high-resolution displays
- future ISO installs on different hardware

## Current Asset Direction
KapilOS uses an AssetManager to centralise assets.

Current and future asset categories include:
- wallpapers
- icons
- fonts
- sounds
- images
- future SVG assets

SVG icon support is planned through NanoSVG.

## Current Progress
Working pieces currently include:
- SDL window creation
- SDL renderer creation
- ImGui integration
- Docking support
- wallpaper rendering
- responsive layout system
- AssetManager foundation
- LayoutManager foundation
- modular UI structure

## Project Structure
The codebase is divided into modules such as:
- Graphics
- UI
- Applications
- ApplicationManager
- AssetManager
- Core
- Assets
- ThirdParty
- Docs

## Development Philosophy
KapilOS is being built with these rules:
- use stable third-party tools when they save time
- build custom systems only where KapilOS actually needs them
- keep code modular
- avoid duplicate logic
- avoid unnecessary rewrites
- keep the project moving toward a usable OS as early as possible

## Current Focus
The current focus is:
1. finish KapilOS as quickly as possible
2. use prebuilt tools wherever sensible
3. keep the architecture clean
4. make the UI responsive
5. integrate real icons
6. prepare the project for future ISO packaging

## Documentation
This repository contains detailed docs in the `Docs/` folder, including:
- PROJECT_MANIFEST.md
- ARCHITECTURE.md
- ROADMAP.md
- DEVELOPER_GUIDE.md
- CODING_STYLE.md
- FILE_STRUCTURE.md
- CHANGELOG.md

## Vision
KapilOS should eventually feel like a real desktop operating system with its own identity, not just a UI layer on top of something else.
