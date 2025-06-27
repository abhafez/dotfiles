#!/bin/sh

copyq &
sxhkd &
bash ~/scripts/kb.sh &
bash ~/scripts/fehbg.sh &
bash ~/.screenlayout/laptop.sh &
compton --config ~/.compton.conf &


# if running dwm or other simple tiling window manager desktop, then enable the following

# dunst is a GUI notify daemon replacement

#if pgrep dunst; then pkill dunst ; fi

if [ ${XDG_CURRENT_DESKTOP} == "" ]; then

dunst &

fi

