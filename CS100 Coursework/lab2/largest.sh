#!/bin/sh
if [ -z "$1" ] && [ -z "$2" ] && [ -z "$3" ]; then
	exit 0
fi
if [ "$1" -ge "$2" ] && [ "$1" -ge "$3" ]; then
	echo "$1"
fi
if [ "$2" -ge "$1" ] && [ "$2" -ge "$3" ]; then
	echo "$2"
fi
if [ "$3" -ge "$2" ] && [ "$3" -ge "$1" ]; then
	echo "$3"
fi
 
