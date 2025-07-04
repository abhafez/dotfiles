#!/bin/bash

increase_volume() {
    # Get all available sinks and increase volume for each one
    SINKS=$(pactl list sinks short | awk '{print $1}')
    
    # Set default sink to the first one in the list if available
    DEFAULT_SINK=$(echo "$SINKS" | head -1)
    
    # Get current volume percentage from the default sink
    VOLUME=$(pactl get-sink-volume $DEFAULT_SINK | grep -Po '[0-9]+(?=%)' | head -1)
    
    # Only increase if volume is less than 100%
    if [ "$VOLUME" -lt 100 ]; then
        # Loop through all sinks
        for sink in $SINKS; do
            pactl set-sink-volume "$sink" +5%
        done
        
        # Get updated volume after change
        VOLUME=$(pactl get-sink-volume $DEFAULT_SINK | grep -Po '[0-9]+(?=%)' | head -1)
    fi
    
    PROGRESS=""
    PROGRESS_LENGTH=$((VOLUME / 5))
    
    notify-send -u low -t 1500 "Volume: ${VOLUME}%" "$PROGRESS" -h int:value:"$VOLUME" -h string:synchronous:"volume"
}

increase_volume