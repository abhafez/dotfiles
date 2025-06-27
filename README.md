# Dotfiles

This repository contains my personal dotfiles and configurations, including a patched version of the Dynamic Window Manager (DWM) 6.5.

## Notes

- `doas` is just my way to `sudo` use `sudo` if you don't have `doas` installed
- `.gitconfig` includes my name and personal email you need to change them. 

## Prerequisites

- `git` (for cloning the repository)

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
   doas apt install make gcc libx11-dev libxft-dev libxinerama-dev libfribidi-dev
   ```

3. Build and install DWM:
   ```bash
   cd dwm-6.5
   doas make clean install
   ```

### Configuration

DWM is configured by editing the `config.h` file and recompiling the source code. The repository includes a pre-configured `config.h` file with settings for the applied patches.

To modify the configuration:

1. Edit the `config.h` file in the `dwm-6.5` directory.
2. Recompile and install DWM:
   ```bash
   cd dwm-6.5
   doas make clean install
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

- **Win+d**: Open dmenu (program launcher)
- **Win+Enter**: Open terminal (ST by default)
- **Win+j/k**: Navigate through windows
- **Win+Shift+q**: Close focused window
- **Win+Shift+c**: Quit DWM (Logout)
- **Win+[1-9]**: Switch to tag [1-9]
- **Win+Shift+[1-9]**: Move focused window to tag [1-9]

#### Config Files
Installation Script
To automate the installation, here's a simple script you can use:

```bash
bash install.sh
doas cp config/fontconfig/fonts.conf /etc/fonts/local.conf # make sure you set valid fonts of your system in this file
doas fc-cache -f -v
```



## License

The configurations in this repository are released under the MIT License. The DWM source code is licensed under the MIT/X Consortium License as specified in the DWM directory.