#!/bin/bash
eval $(slop)
ffmpeg -f x11grab -s "${W}x${H}" -i ":0.0+${X},${Y}" ~/myfile.webm

