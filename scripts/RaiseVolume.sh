#!/bin/bash

increase_volume() {
    DEFAULT_SINK=0
    
    for sink in {0..10}; do
        if pactl list sinks short | grep -q "$sink"; then
            pactl set-sink-volume "$sink" +5%
        fi
    done
    
    VOLUME=$(pactl get-sink-volume $DEFAULT_SINK | grep -Po '[0-9]+(?=%)' | head -1)
    
    PROGRESS=""
    PROGRESS_LENGTH=$((VOLUME / 5))
    
    notify-send -u low -t 1500 "Volume: ${VOLUME}%" "$PROGRESS" -h int:value:"$VOLUME" -h string:synchronous:"volume"
}

increase_volume
