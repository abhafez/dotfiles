#!/bin/bash
# This script lists .screenlayout scripts and lets you pick one to run via dmenu.

LAYOUT_DIR="$HOME/.screenlayout"

if [ ! -d "$LAYOUT_DIR" ]; then
  echo "No .screenlayout directory found at $LAYOUT_DIR" >&2
  exit 1
fi

# Get list of .sh files (basename only)
mapfile -t layouts < <(find "$LAYOUT_DIR" -maxdepth 1 -type f -name '*.sh' -exec basename {} \;)

if [ ${#layouts[@]} -eq 0 ]; then
  echo "No screenlayout scripts found in $LAYOUT_DIR" >&2
  exit 1
fi

# Use dmenu for selection
selected=$(printf '%s\n' "${layouts[@]}" | dmenu -i -p "Select screen layout:")

if [ -n "$selected" ]; then
  bash "$LAYOUT_DIR/$selected"
else
  echo "No selection made." >&2
  exit 1
fi
