# KapilOS Changelog

## [Unreleased]
### Added
- Initial KapilOS project structure
- SDL2-based graphics bootstrap
- ImGui integration
- Docking branch support
- Wallpaper rendering
- Responsive layout foundation
- AssetManager foundation
- LayoutManager foundation
- UIConstants foundation
- Desktop, TopBar, Sidebar, Dock, widgets, and applications structure
- NanoSVG repository cloned and tested successfully
- Documentation set started in `Docs/`

### Changed
- Moved toward a responsive UI architecture
- Moved asset path handling into AssetManager
- Moved screen sizing and responsive calculations into LayoutManager
- Began replacing hardcoded UI values with layout-driven values
- Clarified the role of Sidebar as system navigation
- Clarified the role of Dock as pinned/running applications
- Clarified the role of TopBar as system status
- Clarified the role of Desktop as wallpaper/workspace
- Shifted icon direction toward real SVG-based icons instead of emoji placeholders

### Notes
- The project is still under active development.
- The current priority is to finish KapilOS quickly using mature prebuilt tools wherever they make sense.
- The long-term goal is a bootable ISO that boots into KapilOS directly.

## [0.1.0] - Initial Working Desktop Shell
### Added
- First runnable KapilOS desktop shell
- SDL window and renderer
- ImGui UI pipeline
- Basic desktop UI modules
- Basic settings and file explorer applications
