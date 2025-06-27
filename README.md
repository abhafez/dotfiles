# Dotfiles

This repository contains my personal dotfiles and configurations, including a patched version of the Dynamic Window Manager (DWM) 6.5.

## Contents

- [DWM 6.5 (Patched)](#dwm-65-patched)
  - [Applied Patches](#applied-patches)
  - [Installation](#installation)
  - [Configuration](#configuration)
  - [Usage](#usage)

## DWM 6.5 (Patched)

DWM is an extremely fast, small, and dynamic window manager for X. This repository includes a customized version of DWM 6.5 with several patches applied to enhance functionality.

### Applied Patches

The following patches have been applied to the DWM 6.5 installation:

1. **adjacenttag-skipvacant**: Allows skipping vacant tags when moving to adjacent tags.
2. **attachbottom**: Makes new clients attach at the bottom of the stack instead of the top.
3. **autostart**: Enables DWM to automatically execute commands/scripts at startup.
4. **bidi-restricted**: Adds support for bidirectional text rendering (restricted version).
5. **cyclelayouts**: Adds keybindings to cycle through layouts.
6. **fullgaps**: Adds gaps between windows for visual separation.
7. **fullscreen**: Allows windows to go into true fullscreen mode.
8. **pertag**: Makes layout, mfact, barpos and nmaster settings per-tag rather than global.
9. **systray**: Adds a system tray in the status bar.

### Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/dotfiles_last.git
   cd dotfiles_last
   ```

2. Install DWM dependencies (Debian/Ubuntu):
   ```bash
   sudo apt install make gcc libx11-dev libxft-dev libxinerama-dev libfribidi-dev
   ```

3. Build and install DWM:
   ```bash
   cd dwm-6.5
   sudo make clean install
   ```

### Configuration

DWM is configured by editing the `config.h` file and recompiling the source code. The repository includes a pre-configured `config.h` file with settings for the applied patches.

To modify the configuration:

1. Edit the `config.h` file in the `dwm-6.5` directory.
2. Recompile and install DWM:
   ```bash
   cd dwm-6.5
   sudo make clean install
   ```

### Usage

To use DWM as your window manager, add the following line to your `.xinitrc` file:

```bash
exec dwm
```

For a status bar with system information, add something like this to your `.xinitrc` before the `exec dwm` line:

```bash
while xsetroot -name "$(date) $(uptime | sed 's/.*,//')" 
do
    sleep 1
done &
```

#### Default Keybindings

- **Alt+p**: Open dmenu (program launcher)
- **Alt+Shift+Enter**: Open terminal
- **Alt+j/k**: Navigate through windows
- **Alt+Shift+c**: Close focused window
- **Alt+[1-9]**: Switch to tag [1-9]
- **Alt+Shift+[1-9]**: Move focused window to tag [1-9]
- **Alt+t**: Set tiled layout
- **Alt+f**: Set floating layout
- **Alt+m**: Set monocle layout
- **Alt+Space**: Toggle between current and previous layout

## Other Configurations

(This section will be expanded as more configurations are added to the repository)

## License

The configurations in this repository are released under the MIT License. The DWM source code is licensed under the MIT/X Consortium License as specified in the DWM directory.