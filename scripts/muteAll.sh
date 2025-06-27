#!/bin/bash

toggle_mute() {
    for sink in {0..10}; do
        if pactl list sinks short | grep -q "$sink"; then
            pactl set-sink-mute "$sink" toggle
        fi
    done
}

check_mute_state() {
    # Direct check if any sink is unmuted
    if pactl list sinks | grep -q "Mute: no"; then
        return 1 # At least one sink is unmuted
    else
        return 0 # All sinks are muted
    fi
}

toggle_mute

if check_mute_state; then
    notify-send -u normal -i audio-volume-muted "Audio" "All audio outputs muted"
else
    notify-send -u normal -i audio-volume-high "Audio" "Audio outputs unmuted"
fi