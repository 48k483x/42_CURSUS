#!/bin/bash

# Loading animation
sp="/-\|"
echo -n ' '
printf "\e[38;2;255;40;0mCleaning...\e[0m"  # Printing "Cleaning" in the specified color (ff2800)
while :; do
  for i in $(seq 0 3); do
    echo -ne "\b${sp:i:1}"
    sleep 0.2
  done
done

