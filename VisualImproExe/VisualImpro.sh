#!/bin/bash
EXECPATH="/root/Bela/projects/VisualImpro/"
WAVPATH="/root/Bela/projects/VisualImpro/wavfiles/tmp/"
CONFIGPATH="/root/Bela/projects/VisualImpro/config/"
LOGPATH="/root/Bela/projects/VisualImpro/log/"
CONFIGFILE="./config.cfg"
CONFIGTMPFILE="./configtmp.cfg"
#Catch Ctrl-C signal to do cleanup and saves.
trap 'echo "";' INT
#Parse config file
#Copy wav files into Bela
awk -F" " -v wavpath="$WAVPATH" '$1 ==  "FILE" {system("scp "$2" root@192.168.7.2:"wavpath"")}' config.cfg
#Modify config file to match Bela path to wav files
cp config.cfg configtmp.cfg
awk -F" " -v wavpath="$WAVPATH" '$1 ==  "FILE" {gsub(""$2"", ""wavpath""$2""); print $0}' configtmp.cfg
#Copy config file into Bela
scp configtmp.cfg root@192.168.7.2:/root/Bela/projects/VisualImpro/config/
#Launch server
nodejs server.js &
#Open Firefox tab
firefox 192.168.7.1:8080 &
#Launch VisualImpro
ssh root@192.168.7.2
cd /root/Bela/projects/VisualImpro
./VisualImpro config/configtmp.cfg &
