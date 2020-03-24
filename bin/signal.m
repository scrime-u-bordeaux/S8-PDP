filename='cosine.ogg'
fs=44100
t=0:1/fs:10
w=2*pi*440*t
signal=cos(w)
audiowrite(filename, signal, fs)
player = audioplayer (signal, fs)
play (player)