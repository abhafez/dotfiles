#!/bin/bash

# Create necessary directories
mkdir -p ~/.config/{bat/themes,dunst,fontconfig,rofi,sxhkd/scripts,tmux}
# I just place my scripts in home
mkdir -p ~/scripts

# Copy dotfiles
DOT_FILES=$(pwd)
cp $DOT_FILES/.aliasrc ~/.aliasrc
cp $DOT_FILES/.bg.png ~/.bg.png
cp $DOT_FILES/.tmux.conf ~/.tmux.conf
cp $DOT_FILES/.zshrc ~/.zshrc
cp $DOT_FILES/.compton.conf ~/.compton.conf

# You may want to customize .gitconfig before copying
cp $DOT_FILES/.gitconfig ~/.gitconfig

# Copy config files
cp -r $DOT_FILES/config/bat/themes/* ~/.config/bat/themes/
cp $DOT_FILES/config/dunst/* ~/.config/dunst/
cp $DOT_FILES/config/fontconfig/* ~/.config/fontconfig
cp $DOT_FILES/config/rofi/* ~/.config/rofi/
cp $DOT_FILES/config/sxhkd/sxhkdrc ~/.config/sxhkd/
cp $DOT_FILES/config/sxhkd/scripts/* ~/.config/sxhkd/scripts/
cp $DOT_FILES/config/tmux/* ~/.config/tmux/
cp $DOT_FILES/cursor/* ~/.icons/

# Copy scripts
cp $DOT_FILES/scripts/* ~/scripts/
chmod +x ~/scripts/*

# Install DWM (optional - uncomment if needed)
# cd $DOT_FILES/dwm-6.5
# sudo make clean install

echo "Dotfiles installation complete!"