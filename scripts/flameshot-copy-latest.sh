#!/usr/bin/env bash

set -euo pipefail

SCREENSHOT_DIR=~/Pictures

# Find the latest file
latest_screenshot=$(/usr/bin/ls -t "$SCREENSHOT_DIR"/*.png | head -n 1)

if [[ ! -f "$latest_screenshot" ]]; then
  echo "No screenshot found in $SCREENSHOT_DIR"
  exit 1
fi

# Copy as both file and image data for maximum compatibility

# Copy the image content to clipboard (works in most image editors)
xclip -selection clipboard -t image/png -i "$latest_screenshot"

# Copy the file path for file managers
echo -n "file://$latest_screenshot" | xclip -selection clipboard -t text/uri-list

# For file operations, also copy as plain text path
xclip -selection clipboard -t image/png -i "$latest_screenshot"

# Add to copyq clipboard history
# copyq copy image/png "$(cat "$latest_screenshot")"

notify-send "Flameshot" "📸 Copied latest screenshot to clipboard: $(basename "$latest_screenshot")"
