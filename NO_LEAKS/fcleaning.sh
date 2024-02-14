#!/bin/bash

# Loading animation
sp="/-\|"
echo -n ' '
printf "\e[38;2;153;51;153mFull Cleaning...\e[0m"
while :; do
  for i in $(seq 0 3); do
    echo -ne "\b${sp:i:1}"
    sleep 0.2
  done
done
