#!/bin/sh
xrandr --output eDP --primary --mode 1920x1200 --pos 0x0 --rotate normal --output DisplayPort-0 --off --output DisplayPort-1 --off --output DisplayPort-3 --off --output DisplayPort-4 --off --output DisplayPort-5 --off --output DisplayPort-6 --off --output DisplayPort-7 --off --output DisplayPort-8 --off

bash ~/scripts/kb.sh

bash ~/scripts/fehbg.sh
