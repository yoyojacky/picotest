#!/bin/bash
# upload firmware and test demo code

echo -e "\e[32;40mRP2040 micropython firmware upload begin...\e[0m"

while true

do
   device=`ls /dev/ttyACM0 2>/dev/null`
   if [ $? -eq 0 ];then
     echo -e "\e[32;40mFound device $device \e[0m"
   fi

   folder=`lsblk |grep sda1 |awk '{print $NF}'`
   if [ $? -eq 0 ];then
    echo -e "\e[32;40mFind file location\e[0m"
    cp -Rf ./blink.uf2 $folder 2> /dev/null && echo -e "\e[32;40mFlash Down, remove the Pico and replace it with new one!\e[0m" || echo -e "\e[34;40mCan not find location\e[0m"
   fi

   echo -e "\e[32;40mDetecting......\e[0m"
   sleep 1
   clear
done
