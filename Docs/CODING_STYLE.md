# KapilOS Coding Style

## 1. Goal
This document defines the coding conventions for KapilOS so the codebase stays readable, modular, maintainable, and easy to extend.

## 2. General Rules
- Use C++17.
- Keep code clean and production-ready.
- Prefer clarity over cleverness.
- Prefer modular design over large monolithic files.
- Avoid duplication.
- Avoid unnecessary abstraction.
- Avoid unnecessary refactoring of working code.

## 3. Naming Conventions
Use meaningful names for all:
- classes
- functions
- variables
- constants
- files
- folders

Recommended style:
- Classes: `PascalCase`
- Functions: `PascalCase`
- Variables: `m_memberName` for members
- Constants: clear descriptive names
- Files: match the class or module name

Examples:
- `Graphics`
- `UIManager`
- `LayoutManager`
- `AssetManager`
- `ThemeManager`
- `ApplicationManager`

## 4. File Structure
Each module should stay organised:
- `.h` file for declarations
- `.cpp` file for implementation

Header files should remain focused.
Implementation files should contain logic, not declarations unless necessary.

## 5. Responsibility Rules
Each class should have a single responsibility.

Examples:
- `Graphics` handles SDL and rendering lifecycle.
- `UIManager` handles the permanent desktop UI.
- `AssetManager` handles asset paths and loading.
- `LayoutManager` handles responsive layout values.
- `ThemeManager` handles styling and colours.
- `ApplicationManager` handles applications.

Do not mix responsibilities across modules.

## 6. UI Rules
Never hardcode UI sizes when a responsive helper can be used.

Avoid writing values like:
- 40
- 50
- 70
- 150
- 420

If a UI value matters, move it into:
- `UIConstants`
- `LayoutManager`
- a reusable widget helper

All UI should adapt to screen size.

## 7. Asset Rules
Do not build random asset paths inside UI code.

Use `AssetManager` for asset path generation and future loading.

Future direction:
- wallpaper loading
- icon loading
- font loading
- sound loading
- texture caching
- SVG loading

## 8. Error Handling
Handle failure states clearly.

Examples:
- if a texture fails to load, log the reason
- if SDL initialization fails, stop cleanly
- if a resource is missing, do not crash silently

Always fail visibly and cleanly.

## 9. Formatting Rules
Keep formatting consistent:
- clean indentation
- readable line breaks
- no extremely long lines when avoidable
- no random spacing
- no messy alignment

Prefer readable formatting even if it takes more lines.

## 10. Comments
Use comments only when they add real value.

Good comments explain:
- intent
- architecture
- non-obvious logic
- important design decisions

Avoid comments that simply repeat the code.

## 11. Refactoring Rules
Only refactor when:
- it improves architecture
- it removes duplication
- it improves maintainability
- it fixes a real problem

Do not refactor stable code just for appearance.

## 12. Third-Party Libraries
KapilOS intentionally uses mature third-party libraries where appropriate.

Examples:
- SDL2
- SDL2_image
- ImGui
- NanoSVG

Do not rewrite stable third-party solutions unless there is a strong reason.

## 13. Dependency Rules
Keep dependencies layered cleanly.

High-level UI code should not directly depend on low-level details when a module can own that dependency.

Examples:
- UI should not directly manage SDL resources
- applications should not directly manage renderer lifecycle
- theme should not be scattered across random files

## 14. Readability Rules
Code should be understandable when reopened later.

If a file becomes hard to understand, split it into smaller modules.

If a function becomes too large, split it into smaller functions.

If logic is repeated, extract a helper.

## 15. Practical Rule
KapilOS is being built to become a usable desktop operating system.

That means code should always favour:
- maintainability
- responsiveness
- modularity
- stability
- clarity

over temporary shortcuts that create future problems.
