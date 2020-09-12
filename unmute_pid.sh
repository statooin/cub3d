#!/bin/bash

index=$(pacmd list-sink-inputs | 
	awk -v pid=$1 '
	$1 == "index:" {idx = $2} 
	$1 == "application.process.id" && $3 == "\"" pid "\"" {print idx; exit}
	')

echo "pacmd set-sink-input-mute $index 0 "
pacmd set-sink-input-mute $index 0 >/dev/null
