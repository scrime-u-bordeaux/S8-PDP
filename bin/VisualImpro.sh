#!/bin/bash
EXECPATH="/root/Bela/projects/VisualImpro/"
WAVPATH="/root/Bela/projects/VisualImpro/wavfiles/tmp/"
CONFIGPATH="/root/Bela/projects/VisualImpro/config/"
LOGPATH="/root/Bela/projects/VisualImpro/log/"
CONFIGFILE="./config.cfg"
CONFIGTMPFILE="./configtmp.cfg"
CONFIGQTFILE="./config_qt.cfg"

function getCurrentDateTime() {
  DATE=$(date +"%Y-%m-%d.%X")
}

function cleanup(){
  ssh root@192.168.7.2 'pkill VisualImpro'
  pkill nodejs
  ssh root@192.168.7.2 'rm /root/Bela/projects/VisualImpro/wavfiles/tmp/*.wav'
  getCurrentDateTime
  if [ -d logs ] ; then
    cd logs/
  else
    mkdir logs
    cd logs/
  fi
  mkdir $DATE
  cd ..
  scp root@192.168.7.2:/root/Bela/projects/VisualImpro/log/log logs/$DATE
  rm $CONFIGTMPFILE 
  echo Data saved in logs/$DATE
  echo "Don't forget to close the Firefox window."
  exit 1
}

function change_path(){
  for ((i=0; i<${#path[@]}; i++));
  do
    path[$i]=$(echo ${path[$i]} | awk -F"/" -v wavpath=$WAVPATH '$0=""wavpath""$NF""')
  done
  for i in "${path[@]}"
  do  
    echo $i
  done
}

function qt_display(){
  #trap cleanup SIGINT
  cd ../GUI/
  ./installGUI.sh
  ./bin/GUI &
  while ! test -f $CONFIGQTFILE; do
    sleep 2
    echo "Waiting for the configuration file to be created..."
  done
  #awk -F" " -v wavpath="$WAVPATH" '$1 ==  "FILE" {system("scp "$2" root@192.168.7.2:"wavpath"")}' config_qt.cfg
  path=($(awk -F" " '$1=="FILE" {print $2};' config_qt.cfg))
  change_path $path
  awk -F" " -v path="${path[*]}" '$1=="FILE" {gsub($2, path[$NR])};1' $CONFIGQTFILE > $CONFIGTMPFILE
}

function default_display(){
  #Catch Ctrl-C signal to do cleanup and saves.
  trap cleanup SIGINT
  #Copy wav files into Bela
  awk -F" " -v wavpath="$WAVPATH" '$1 ==  "FILE" {system("scp "$2" root@192.168.7.2:"wavpath"")}' config.cfg
  #Modify config file to match Bela path to wav files
  awk -F" " -v wavpath=$WAVPATH '$1=="FILE" {gsub("tracks/", ""); gsub($2, ""wavpath""$2"")};1' config.cfg > configtmp.cfg
  #Copy config file into Bela
  scp configtmp.cfg root@192.168.7.2:/root/Bela/projects/VisualImpro/config/
  sleep 5
  #Launch server
  nodejs server.js &
  sleep 5
  # #Open Firefox tab
  firefox --new-window 192.168.7.1:8080 &
  # #Launch VisualImpro
  ssh root@192.168.7.2 'cd /root/Bela/projects/VisualImpro && ./VisualImpro config/configtmp.cfg' &
  while true; do sleep 2; done
}

function help_message(){
  echo -e "Usage : ./VisualImpro [-options]"
  echo -e "The options for this executable are :"
  echo -e "\t-d (display) and the accepted arguments (which one is recquired) are :"
  echo -e "\t\tfirefox (the old version using NodeJS and a manual config file)"
  echo -e "\t\tqt"
  echo -e "\t-t (testing) and the accepted arguments (which one is recquired) are :"
  echo -e "\t\tconfig1"
  echo -e "\t\tconfig2"
  echo -e "\t-h (help), to show this message."

}

while getopts ":hd:" opt; do
  case $opt in
    d)
      if [ $OPTARG == "firefox" ] ; then
        default_display
      elif [ $OPTARG == "qt" ]; then
        qt_display
      else
        help_message
        exit 1
      fi
      ;;
    h|\?|*|:)
      help_message
      exit 1
      ;;
  esac
done

if [ -z "${d}" ]; then
  help_message
fi



