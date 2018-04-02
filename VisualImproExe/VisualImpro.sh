#!/bin/bash
EXECPATH="/root/Bela/projects/VisualImpro/"
WAVPATH="/root/Bela/projects/VisualImpro/wavfiles/tmp/"
CONFIGPATH="/root/Bela/projects/VisualImpro/config/"
LOGPATH="/root/Bela/projects/VisualImpro/log/"
CONFIGFILE="./config.cfg"
CONFIGTMPFILE="./configtmp.cfg"

function getCurrentDateTime() {
  return date +"%Y-%m-%d.%X"
}
#Catch Ctrl-C signal to do cleanup and saves.
trap '{
        ssh root@192.168.7.2 pkill VisualImpro;
        pkill nodejs;
        ssh root@192.168.7.2 rm $WAVPATH*.wav;
        scp root@192.168.7.2:$LOGPATHlog logs/$getCurrentDateTime;
        echo "Data saved in logs/$getCurrentDateTime";
        rm $CONFIGTMPFILE;
        exit 1;
      }' SIGINT
#Parse config file
#Copy wav files into Bela
awk -F" " -v wavpath="$WAVPATH" '$1 ==  "FILE" {system("scp "$2" root@192.168.7.2:"wavpath"")}' config.cfg
#Modify config file to match Bela path to wav files
cp config.cfg configtmp.cfg
awk -F" " -v wavpath="$WAVPATH" '$1 ==  "FILE" {gsub(""$2"", ""wavpath""$2"")}' configtmp.cfg
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
while 1
do

done
