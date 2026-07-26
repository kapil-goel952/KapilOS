# KapilOS Roadmap

## 1. Current Priority
The current priority is to finish KapilOS as quickly as possible using mature prebuilt tools wherever they make sense. The project should become usable first. Custom implementations can be added later only when they provide real value.

## 2. Immediate Goal
The immediate goal is to complete the desktop shell so KapilOS feels like a real operating system environment instead of a demo application.

## 3. Current Focus
Current active work is on:
- responsive layout
- SVG icon support
- sidebar polish
- dock polish
- top bar polish
- asset pipeline cleanup
- reusable UI components
- better desktop identity

## 4. Short-Term Milestones
### 4.1 SVG Icon System
KapilOS should stop relying on emoji placeholders and switch to a real SVG-based icon pipeline.
Current direction:
SVG file -> NanoSVG -> rasterize -> SDL texture -> AssetManager -> UI

### 4.2 Sidebar Polish
The sidebar should work as a system-navigation panel.
It should support:
- home / desktop access
- search
- files
- workspace overview
- notifications
- quick settings
- settings
- profile

### 4.3 Dock Polish
The dock should become a proper bottom application strip for:
- pinned apps
- running apps
- frequently used apps

### 4.4 TopBar Polish
The top bar should become a proper system status bar with:
- time
- system indicators
- quick actions
- future notifications and search access

### 4.5 Desktop Polish
Desktop should remain clean, responsive, and wallpaper-driven.

## 5. Medium-Term Milestones
### 5.1 App Launcher / Kapil Menu
A KapilOS launcher/menu should exist as the main entry point for apps and common actions.

### 5.2 Notification Center
A notification system should be added for system and app alerts.

### 5.3 Quick Settings
Add quick controls such as:
- network
- volume
- brightness
- user session controls

### 5.4 File Explorer Improvements
File Explorer should become a more complete desktop file manager.

### 5.5 Settings Expansion
Settings should become a real system control panel with multiple sections.

## 6. Architecture Milestones
### 6.1 Texture Cache
Asset loading should support caching so repeated loads do not waste memory or time.

### 6.2 SVG Loader
KapilOS should support a real SVG loading path inside the asset system.

### 6.3 Icon Manager
A higher-level icon system should exist so UI code never deals with low-level icon loading directly.

### 6.4 Animation System
Hover, transitions, dock effects, and panel animations should be added in a controlled way.

### 6.5 Reusable UI Components
KapilOS should continue expanding its reusable UI components:
- buttons
- cards
- panels
- windows
- sidebar items
- dock items
- menu items
- search boxes
- toasts
- popups

## 7. Stability Milestones
### 7.1 Responsive Testing
KapilOS should be tested on multiple screen sizes:
- 1366x768
- 1600x900
- 1920x1080
- 2560x1440
- 4K

### 7.2 Layout Consistency
No hardcoded UI sizes should remain in places where LayoutManager can provide a value.

### 7.3 Build Stability
The project should keep building cleanly after each major refactor.

## 8. Packaging Milestones
### 8.1 Session Start Flow
KapilOS should eventually start automatically after boot and login.

### 8.2 Bootable ISO
The project should be packaged into a bootable ISO for testing on other systems.

### 8.3 External Testing
KapilOS should be runnable on another machine or VM without manual setup.

## 9. Long-Term Milestones
### 9.1 Linux Session Integration
KapilOS should become the visible desktop shell/session on top of a Linux base.

### 9.2 Custom Internals Where Needed
After the product is usable, internal systems can be replaced or improved one by one if that creates real value.

### 9.3 Full Desktop Identity
KapilOS should have its own identity in UI, behaviour, naming, layout, and user flow.

## 10. Release Philosophy
KapilOS should be released in layers:
- first: usable desktop shell
- then: polished desktop shell
- then: ISO
- then: advanced features
- then: deeper custom systems

## 11. Order of Work
The best order is:
1. finish the desktop shell
2. finish the icon pipeline
3. polish sidebar, dock, and topbar
4. finish core apps
5. add launcher and system panels
6. package ISO
7. improve internal systems later

## 12. What Not To Do
Do not pause the project to rewrite stable systems unnecessarily.
Do not build custom low-level libraries before the desktop is usable.
Do not add architecture that slows down visible progress without strong reason.
Do not use hardcoded sizes when responsive helpers already exist.
