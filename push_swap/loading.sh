# loading.sh
#!/bin/bash

# Loading animation
sp="/-\|"
echo -n ' Compiling... '
while :; do
  for i in $(seq 0 3); do
    echo -ne "\b${sp:i:1}"
    sleep 0.2
  done
done

