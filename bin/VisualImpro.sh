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

function cleanup_firefox(){
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

function cleanup_qt(){
  ssh root@192.168.7.2 'pkill VisualImpro'
  pkill GUI
  ssh root@192.168.7.2 'rm /root/Bela/projects/VisualImpro/wavfiles/tmp/*.wav'
  rm $CONFIGQTFILE
  rm $CONFIGTMPFILE
  cd ../bin/
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
  echo Data saved in logs/$DATE
  exit 1
}

function change_path(){
  for ((i=0; i<${#path[@]}; i++));
  do
    path[$i]=$(echo ${path[$i]} | awk -F"/" -v wavpath=$WAVPATH '$0=""wavpath""$NF""')
  done
}

function qt_display(){
  #Catch Ctrl-C signal to do cleanu and saves.
  trap cleanup_qt SIGINT
  #Moving to GUI directory
  cd ../GUI/
  #Launch script to compile GUI source files
  ./installGUI.sh
  #Launch executable to start GUI
  ./bin/GUI &
  pid=$!
  #Loop used to wait for the configuration file to be created through GUI
  echo "Waiting for the configuration file to be created..."
  while ! test -f $CONFIGQTFILE ; do
    if kill -0 $pid 2> /dev/null; then
      sleep 2
    else
      exit 1
    fi
  done
  #Copy .wav files into Bela
  awk -F" " -v wavpath="$WAVPATH" '$1 ==  "FILE" {system("scp "$2" root@192.168.7.2:"wavpath"")}' config_qt.cfg
  #Modifying .wav paths in a configuration file that will be sent into Bela
  path=($(awk -F" " '$1=="FILE" {print $2};' config_qt.cfg))
  change_path $path
  awk -F" " -v PATH="${path[*]}" 'BEGIN {split(PATH, path, / /); i=1;} $1=="FILE" {gsub($2, ""path[i]""); i++;};1' $CONFIGQTFILE > $CONFIGTMPFILE
  #Copy configuration file into Bela
  scp configtmp.cfg root@192.168.7.2:/root/Bela/projects/VisualImpro/config/
  sleep 3
  #Launch VisualImpro
  ssh root@192.168.7.2 'cd /root/Bela/projects/VisualImpro && ./VisualImpro config/configtmp.cfg' &
  while true; do 
    if kill -0 $pid 2> /dev/null; then
      sleep 2
    else
      cleanup_qt
    fi
  done
}

function default_display(){
  #Catch Ctrl-C signal to do cleanup and saves.
  trap cleanup_firefox SIGINT
  #Copy .wav files into Bela
  awk -F" " -v wavpath="$WAVPATH" '$1 ==  "FILE" {system("scp "$2" root@192.168.7.2:"wavpath"")}' config.cfg
  #Modifying configuration file to match Bela path to .wav files
  awk -F" " -v wavpath="$WAVPATH" '$1=="FILE" {gsub("tracks/", ""); gsub($2, ""wavpath""$2"")};1' config.cfg > configtmp.cfg
  #Copy configuration file into Bela
  scp configtmp.cfg root@192.168.7.2:/root/Bela/projects/VisualImpro/config/
  sleep 3
  #Launch server
  nodejs server.js &
  sleep 3
  #Open Firefox tab
  firefox --new-window 192.168.7.1:8080 &
  #Launch VisualImpro
  ssh root@192.168.7.2 'cd /root/Bela/projects/VisualImpro && ./VisualImpro config/configtmp.cfg' &
  while true; do sleep 2; done
}

function help_message(){
  echo -e "Usage : ./VisualImpro [-options]"
  echo -e "The options for this executable are :"
  echo -e "\t-d (display) and the accepted arguments (which one is recquired) are :"
  echo -e "\t\tfirefox (the old version using NodeJS and a manual config file)"
  echo -e "\t\tqt"
  echo -e "\t-h (help), to show this message."

}

while getopts ":hd:" opt; do
  case $opt in
    d)
      if [ $OPTARG == "firefox" ] ; then
        default_display
      elif [ $OPTARG == "qt" ] ; then
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



